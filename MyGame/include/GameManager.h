#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Texture.h"
#include "Timer.h"
//#include "AudioManager"
#include "InputManager.h"

class GameManager{
private:

    const int FRAME_RATE= 60;

    static GameManager * sInstance;
    bool mQuit;

    Graphics * mGraphics;
    Timer * mTimer;
    AssetManager * mAssetMgr;
    InputManager * mInputMgr;
    //AudioManager * mAudioMgr;
    
    SDL_Event mEvents;
    Texture * mTex;
    Texture * mShip;
    // GameEntity * mParent;
    // GameEntity * mChild;
public:

    static GameManager * Instance();
    static void Release();
    void Run();

private:

    GameManager();
    ~GameManager();
    void EarlyUpdate();
    void Update();
    void LateUpdate();
    void Render();

};

#endif