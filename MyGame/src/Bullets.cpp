#include "Bullets.h"

Bullet::Bullet(){
    mTimer = Timer::Instance();
    mSpeed = 500.0;
    mTexture = new Texture("bullet.png");
    mTexture->Pos(VEC2_Zero);

    Reload();
}

Bullet::~Bullet(){
    mTimer = NULL;
    delete mTexture;
}

void Bullet::FireBullet(Vector2 pos){
    Pos(pos);
    Active(true);
}

void Bullet::Reload(){
    Actrive(false);
}

void Bullet::Update(){
    if(Active()){
        Translate(-VECT2 * mSpeed * mTimer->DeltaTime());
    }
}