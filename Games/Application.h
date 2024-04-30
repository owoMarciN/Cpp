#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Menu.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMES_PER_SECOND = 60;

class Application{
public:
    Application();
    ~Application();
    void loop();
    void loopMenu();
    void update(double delta_time);
    SDL_Surface * loadSurface();
    void draw();
    void drawMenu();
private:
    Ship m_ship;
    Menu m_menu;
    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Surface *cosmos;
    SDL_Event    m_window_event;
};

#endif