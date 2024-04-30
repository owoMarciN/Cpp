#ifndef MENU_H_
#define MENU_H_

#include "Ship.h"
#include <SDL2/SDL_ttf.h>
#include <string>

#define NUMMENU 2

class Menu{
public:
    Menu();
    ~Menu() = default;
    int drawMain(SDL_Surface * window_surface, SDL_Window * window);
    void clear();
private:
    int x, y;
    char * labels[NUMMENU];
    SDL_Surface * menus[NUMMENU];
    bool selected[NUMMENU];
    SDL_Color color[NUMMENU];
    SDL_Surface *menu_surface;
    TTF_Font* font;
};

#endif