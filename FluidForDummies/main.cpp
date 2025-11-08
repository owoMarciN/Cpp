#include <SDL3/SDL.h>
#include <random>
#include "FluidCell.hpp"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int width = N * SCALE, height = N * SCALE;
const int FRAME_RATE = 60;
const int FRAME_DELAY = 1000 / FRAME_RATE; // ~16.(6)

static int Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL_Init() Error: %s", SDL_GetError());
        return -1;
    }
    
    window = SDL_CreateWindow("Fluid Simulation", 640, 480, 0);
    if (!window) {
        SDL_Log("SDL_CreateWindow() Error: ", SDL_GetError());
        return -1;
    } 

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer() Error: ", SDL_GetError());
        return -1;
    }

    return 0;
}

void HSBtoRGB(double h, double s, double b, Uint8 &outR, Uint8 &outG, Uint8 &outB) {
    h = std::fmod(h, 1.0);
    s = std::clamp(s, 0.0, 1.0);
    b = std::clamp(b, 0.0, 1.0);
    
    int i = static_cast<int>(h * 6);
    double f = h * 6 - i;
    double p = b * (1 - s);
    double q = b * (1 - f * s);
    double t = b * (1 - (1 - f) * s);

    switch (i % 6) {
        case 0: outR = b * 255; outG = t * 255; outB = p * 255; break;
        case 1: outR = q * 255; outG = b * 255; outB = p * 255; break;
        case 2: outR = p * 255; outG = b * 255; outB = t * 255; break;
        case 3: outR = p * 255; outG = q * 255; outB = b * 255; break;
        case 4: outR = t * 255; outG = p * 255; outB = b * 255; break;
        case 5: outR = b * 255; outG = p * 255; outB = q * 255; break;
    }
}

static void Term() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}

static void RenderDensity(FluidCell *fluid, SDL_Renderer *mRenderer) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            double d = fluid->density[fluid->ix(i, j)];
            d = std::clamp(d, 0.0, 255.0);  // Keeping the value within visible range

            // Compute color based on density

            // double hue = std::fmod(d + 50.0, 255.0) / 255.0;
            // double sat = 0.8;
            // double bri = d / 255.0;

            // SDL_Color color;
            // HSBtoRGB(hue, sat, bri, color.r, color.g, color.b);
            // SDL_SetRenderDrawColor(mRenderer, color.r, color.g, color.b, 255);

            SDL_FRect rect = {static_cast<float>(i) * SCALE, static_cast<float>(j) * SCALE, SCALE, SCALE };

            // If you want to have grayscale color pallet comment-out lines above and use:
            Uint8 val = static_cast<Uint8>(d);
            SDL_SetRenderDrawColor(mRenderer, val, val, val, 255);
            SDL_RenderFillRect(mRenderer, &rect);
        }
    }
}

static void Start(FluidCell* fluid, SDL_Renderer* renderer) {
    SDL_Event event;
    bool running = true;
    bool mousePressed = false;
    int prevMouseX = -1, prevMouseY = -1;

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> randDensity(10.0, 70.0);

    Uint32 frameStart;
    int frameTime;

    while (running) {
        frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    mousePressed = true;
                    break;
                case SDL_EVENT_MOUSE_BUTTON_UP:
                    mousePressed = false;
                    prevMouseX = prevMouseY = -1;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE)
                        running = false;
                    break;
            }
        }
		
        // --- Mouse handling ---
        float mx, my;
        SDL_GetMouseState(&mx, &my);
        int fx = mx / SCALE;
        int fy = my / SCALE;

        if (mousePressed && fx >= 0 && fx < N && fy >= 0 && fy < N) {
            // Add density in 3x3 area
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    fluid->addDensity(fx + i, fy + j, randDensity(rng));
                }
            }

            // Add velocity
            if (prevMouseX >= 0 && prevMouseY >= 0) {
                int pmx = prevMouseX / SCALE;
                int pmy = prevMouseY / SCALE;
                double vx = (fx - pmx) * 0.5;
                double vy = (fy - pmy) * 0.5;
                fluid->addVelocity(fx, fy, vx, vy);
            }
            prevMouseX = mx;
            prevMouseY = my;
        }

        // --- Central motion ---
        if (!mousePressed) {
            int cx = int(N / 2.0);
            int cy = int(N / 2.5);
            double t = SDL_GetTicks() * 0.001;
            double angle = t * 2.0;
            double vx = std::cos(angle) * 0.5;
            double vy = std::sin(angle) * 0.5;
            fluid->addVelocity(cx, cy, vx, vy);
            fluid->addDensity(cx, cy, 80.0);
        }

        // --- Simulation step ---
        fluid->step();
        fluid->fadeDensity(0.02);

        // --- Render ---
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        RenderDensity(fluid, renderer);

        SDL_RenderPresent(renderer);

        // --- Frame timing ---
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
            SDL_Delay(FRAME_DELAY - frameTime);
        }
}

int main(int argc, char* argv[]) {
    if (Init() != 0) {
        return -1;
    }
    
    FluidCell* fluid = nullptr;
    try {
        fluid = new FluidCell(N, 0.1, 0, 1e-7);
        Start(fluid, renderer);
    }
    catch (const std::exception& e) {
        SDL_Log("Error: %s", e.what());
    }
    
    delete fluid;
    Term();
    return 0;
}