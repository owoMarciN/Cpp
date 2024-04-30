#include "Application.h"

SDL_Surface *load_surface(char const *path){
    SDL_Surface *image_surface = IMG_Load(path);
    if(!image_surface)
        return 0;
    
    return image_surface;
}

Application::Application(){
    m_window = SDL_CreateWindow("The World Over Heaven",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,
                                0);

    if(!m_window){
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if(!m_window_surface){
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

Application::~Application(){
    SDL_FreeSurface(m_window_surface);
    m_window_surface = NULL;
    SDL_DestroyWindow(m_window);
    m_window = NULL;
}

void Application::loop(){
    bool keep_window_open = true;
    int i = 1;
    if(i == m_menu.drawMain(m_window_surface, m_window))
        keep_window_open = false;
    while(keep_window_open){
        while(SDL_PollEvent(&m_window_event) > 0){
            m_ship.handle_events(m_window_event);
            switch(m_window_event.type){
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }
        update(1.7);
        draw();
    }
}

void Application::update(double delta_time){
    m_ship.update(delta_time);
}

void Application::draw(){
    cosmos = load_surface("./Images/Cosmos.jpg");
    SDL_BlitSurface(cosmos, nullptr, m_window_surface, nullptr);
    SDL_FreeSurface(cosmos);
    m_ship.draw(m_window_surface);
    SDL_UpdateWindowSurface(m_window);
}
// FPS COUNTER
// while (gamerunning)
//     {
//     Uint32 start_time, frame_time;
//     float fps;

//     start_time = SDL_GetTicks();

//     // do stuff
//     SDL_Flip();

//     frame_time = SDL_GetTicks()-start_time;
//     fps = (frame time > 0) ? 1000.0f / frame_time : 0.0f;

// }