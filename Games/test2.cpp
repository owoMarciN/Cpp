#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

bool init();
bool loadMedia();
void close();

SDL_Window * window = NULL;
SDL_Surface * surface = NULL;
SDL_Surface * cosmos = NULL;

bool init(){

    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        std::cout << "SDL could not inittialize! SDL_Error: " << SDL_GetError();
        success = false;
    }
    else{
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr){
            std::cout << "Window could not be created! SDL_Error: " <<  SDL_GetError() << std::endl;
            success = false;
        }
        else{
            surface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

bool loadMedia(){

    bool success = true;
    cosmos = IMG_Load("Cosmos.jpg");
    if(cosmos == nullptr){
        std::cout << "IMG_Load: " << IMG_GetError() << std::endl;
        success = false;
    }

    return success;
}

void close(){
    SDL_FreeSurface(cosmos);
    cosmos = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

int main(int argc, char * args[]){

    if(!init())
        std::cout << "Failed to initialize!" << std::endl;
    else    
        if(!loadMedia())
            std::cout << "Failed to load media!" <<std::endl;
        else{
            SDL_BlitSurface(cosmos, NULL, surface, NULL);
            SDL_UpdateWindowSurface(window);
            SDL_Event e; bool quit = false; while(quit == false){ while(SDL_PollEvent(&e)){ if(e.type == SDL_QUIT) quit = true; }};
        }
        
    close();

    return 0;
}