#include "PlayScreen.h"

PlayScreen::PlayScreen(){

    mInput = InputManager::Instance();
    
    mBackGround = new GameEntity(VEC2_ZERO);
    mCosmos = std::make_unique<Texture>("Cosmos.png");

    mCosmos->Parent(mBackGround);
    mCosmos->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.5f));

    mBackGround->Parent(this);

    mPlayer = std::make_unique<Player>();;
    mPlayer->Parent(this);
    mPlayer->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.8f));
    mPlayer->Scale(VEC2_ONE*0.5f);

    mBoss = std::make_unique<Boss>();
    mBoss->Parent(this);
    mBoss->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.2f));
    mBoss->Scale(VEC2_ONE*0.25f);

    // Enemy::createPaths();

    // mEnemy = new Enemy(0);
    // mEnemy->Scale(VEC2_ONE*0.25f);

}

void PlayScreen::HandleBossCollision() {
    if (mBoss->Active() && mBoss->mHP > 0) {
        for (int i = 0; i < mPlayer->MAX_BULLETS; ++i) {
            if (mPlayer->mBullet[i].Active()) {
                // Use bounding box collision detection
                Vector2 bulletPos = mPlayer->mBullet[i].Pos();
                Vector2 bossPos = mBoss->Pos();
                
                // Define the bounding box for the boss
                float bossLeft = bossPos.x - 100; 
                float bossRight = bossPos.x + 100;
                float bossTop = bossPos.y - 70;
                float bossBottom = bossPos.y + 70;
                
                // Check for collision
                if (bulletPos.x >= bossLeft && bulletPos.x <= bossRight &&
                    bulletPos.y >= bossTop && bulletPos.y <= bossBottom) {
                    mPlayer->mBullet[i].Reload();
                    mBoss->LoseHP(mPlayer->mDamage);
                }
            }
        }
    } else {
        mBoss->Active(false);
    }
}

void PlayScreen::HandlePlayerCollision() {
    if (mPlayer->Active() && mPlayer->mHP > 0) {
        for (int i = 0; i < mBoss->MAX_BULLETS; ++i) {
            if (mBoss->mBullet[i].Active()) {
                // Use bounding box collision detection
                Vector2 bulletPos = mBoss->mBullet[i].Pos();
                Vector2 playerPos = mPlayer->Pos();
                
                // Define the bounding box for the player
                float playerLeft = playerPos.x - 25;  
                float playerRight = playerPos.x + 25;
                float playerTop = playerPos.y - 25;   
                float playerBottom = playerPos.y + 25;
                
                // Check for collision
                if (bulletPos.x >= playerLeft && bulletPos.x <= playerRight &&
                    bulletPos.y >= playerTop && bulletPos.y <= playerBottom) {
                    mBoss->mBullet[i].Reload();
                    mPlayer->LoseHP(mBoss->mDamage);
                }
            }
        }
    } else {
        mPlayer->Active(false);
    }
}

PlayScreen::~PlayScreen(){

    mInput = nullptr;

    delete mBackGround;
    mBackGround = nullptr;
}

void PlayScreen::Update(){
    if(mPlayer->Active() && mBoss->Active()){
        mPlayer->Update();
        mBoss->Update();
        HandleBossCollision();
        HandlePlayerCollision();
    }
    else{
        if(mPlayer->Active())
            mPlayer->Update();
        else if(mBoss->Active()) 
           mBoss->Update();
    }
}

void PlayScreen::Render(){
    mCosmos->Render();
    if(mPlayer->Active())
        mPlayer->Render();
    if(mBoss->Active())
        mBoss->Render();
}