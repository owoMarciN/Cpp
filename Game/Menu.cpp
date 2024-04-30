#include "Menu.h"

Menu::Menu(){
    x = 0;
    y = 0;
    labels[0] = "PLAY";
    labels[1] = "EXIT";
    selected[0] = 0;
    selected[1] = 0;
    color[0] = {255, 255, 255}; 
    color[1] = {255, 0, 0};
}

void Menu::clear(){
    for(int i = 0; i < NUMMENU; i++)
        SDL_FreeSurface(menus[i]);
}

int Menu::drawMain(SDL_Surface * window_surface, SDL_Window * window){
    
    TTF_Init();
    font = TTF_OpenFont("MyFont.ttf", 64);
    Uint32 time;
    for(int i = 0; i < NUMMENU; i++)
        menus[i] = TTF_RenderText_Solid(font, labels[i], color[0]);

    SDL_Rect pos[NUMMENU];
    pos[0].x=window_surface->clip_rect.w/2 - menus[0]->clip_rect.w/2;
    pos[0].y=window_surface->clip_rect.h/2 - menus[0]->clip_rect.h;
    pos[1].x=window_surface->clip_rect.w/2 - menus[0]->clip_rect.w/2;
    pos[1].y=window_surface->clip_rect.h/2 + menus[0]->clip_rect.h;

    SDL_FillRect(window_surface, nullptr, SDL_MapRGB(window_surface->format, 0, 0 ,0));
    SDL_UpdateWindowSurface(window);

    SDL_Event menu_event;
    while(1){
        time = SDL_GetTicks();
        while(SDL_PollEvent(&menu_event)){
            switch(menu_event.type){
                case SDL_QUIT:
                    clear();
                    return 1;
                case SDL_MOUSEMOTION:
                    x = menu_event.motion.x;
                    y = menu_event.motion.y;
                    for(int i = 0; i < NUMMENU; i++){
                        if(x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <=pos[i].y + pos[i].h){
                            if(!selected[i]){
                                selected[i] = 1;
                                SDL_FreeSurface(menus[i]);
                                menus[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
                            }
                        }
                        else{
                            if(selected[i]){
                                selected[i] = 0;
                                SDL_FreeSurface(menus[i]);
                                menus[i] = TTF_RenderText_Solid(font, labels[i], color[0]);
                            }
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    x = menu_event.button.x;
                    y = menu_event.button.y;
                    for(int i = 0; i < NUMMENU; i++){
                        if(x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && y <=pos[i].y + pos[i].h){
                            clear();
                            return i;
                        }
                    }
                    break;
                // case SDL_KEYDOWN:
                //     if(menu_event.key.keysym.sym == SDLK_ESCAPE){
                //         clear();
                //         return 0;
                //     }
            }
        }
        for(int i = 0; i < NUMMENU; i++)
            SDL_BlitSurface(menus[i], NULL, window_surface, &pos[i]);
        SDL_UpdateWindowSurface(window);
    }
}
