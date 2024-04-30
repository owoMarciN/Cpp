#include "Ship.h"

Ship::Ship(){
	ship = IMG_Load("./Images/Ship.png");
	x = 570;
	y = 570;
	m_position->x = 0;
	m_position->y = 0;
	m_position->w = SHIP_WIDTH;
	m_position->h = SHIP_HEIGHT;
    m_direction = Direction::NONE;
}

bool Ship::isAlive(){
	if(HP < 0)
		return false;
	return true;
}

void Ship::update(double delta_time){
    switch(m_direction){
        case Direction::NONE:
            x += 0.0;
            y += 0.0;
            break;
        case Direction::UP:
            y = y - (5.0 * delta_time);
            break;
        case Direction::DOWN:
            y = y + (5.0 * delta_time);
            break;
        case Direction::LEFT:
            x = x - (5.0 * delta_time);
            break;
        case Direction::RIGHT:
            x = x + (5.0 * delta_time);
            y = y - 0;
            break;
        case Direction::UP_RIGHT:
            x = x + (5.0 * delta_time);
            y = y - (5.0 * delta_time);
            break;
        case Direction::UP_LEFT:
            x = x - (5.0 * delta_time);
            y = y - (5.0 * delta_time);
            break;
        case Direction::DOWN_RIGHT:
            y = y + (5.0 * delta_time);
            x = x + (5.0 * delta_time);
            break;
        case Direction::DOWN_LEFT:
            x = x - (5.0 * delta_time);
            y = y + (5.0 * delta_time);
            break;
    }
    m_position->x = x;
    m_position->y = y;
    m_position->w = x + SHIP_WIDTH;
	m_position->h = y + SHIP_HEIGHT;
}

void Ship::handle_events(SDL_Event const &event){
    Uint8 const *keys = SDL_GetKeyboardState(nullptr);
    if(event.type == SDL_KEYDOWN){
        if(keys[SDL_SCANCODE_W] == 1 && keys[SDL_SCANCODE_D] == 1)
            m_direction = Direction::UP_RIGHT;
        else if(keys[SDL_SCANCODE_W] == 1 && keys[SDL_SCANCODE_A] == 1)
            m_direction = Direction::UP_LEFT;
        else if(keys[SDL_SCANCODE_S] == 1 && keys[SDL_SCANCODE_D] == 1)
            m_direction = Direction::DOWN_RIGHT;
        else if(keys[SDL_SCANCODE_S] == 1 && keys[SDL_SCANCODE_A] == 1)
            m_direction = Direction::DOWN_LEFT;
        else if(keys[SDL_SCANCODE_W] == 1)
            m_direction = Direction::UP;
        else if(keys[SDL_SCANCODE_S] == 1)
            m_direction = Direction::DOWN;
        else if(keys[SDL_SCANCODE_A] == 1)
            m_direction = Direction::LEFT;
        else if(keys[SDL_SCANCODE_D] == 1)
            m_direction = Direction::RIGHT;
    }
    else if(keys[SDL_SCANCODE_W] == 0 && keys[SDL_SCANCODE_S] == 0 && keys[SDL_SCANCODE_A] == 0 && keys[SDL_SCANCODE_D] == 0){
            m_direction = Direction::NONE;
    }
}

void Ship::draw(SDL_Surface * window_surface){
	SDL_BlitSurface(ship, nullptr, window_surface, m_position);
}
