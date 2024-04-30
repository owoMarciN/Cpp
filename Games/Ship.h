#ifndef SHIP_H_
#define SHIP_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

const int SHIP_HEIGHT = 140;
const int SHIP_WIDTH = 140;

class Ship{
public:
    enum class Direction{
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        UP_RIGHT,
        UP_LEFT,
        DOWN_RIGHT,
        DOWN_LEFT,
    };
	int HP;
	bool isAlive();
	Ship();
	~Ship() = default;
	void update(double delta_time);
	void draw(SDL_Surface * window_surface);
    void handle_events(SDL_Event const &event);
private:
    Direction m_direction;
	SDL_Surface * ship;
	SDL_Rect * m_position;
    double x, y;
    double xVel, yVel;
};


#endif