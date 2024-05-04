#ifndef BULLETS_H_
#define BULLETS_H_

#include "Texture.h"
#include "MathHelper.h"
#include "Timer.h"

class Bullet{
private:

    const int OFF_SCREEN_BUFFER = 10;
    Timer * mTimer; /// Timer.h file from tutorial 
    double mSpeed;
    Texture * mTexture;
    
public:

    Bullet();
    ~Bullet();

    void FireBullet(Vector2 pos);
    void Reload();
    void Update();
    void Render();

};

#endif