#include "GameManager.h"

GameManager * GameManager::sInstance = NULL;

GameManager * GameManager::Instance(){
    if(sInstance == NULL)
        sInstance = new GameManager();
    return sInstance;
}

void GameManager::Release(){
    delete sInstance;
    sInstance = NULL;
}

GameManager::GameManager(){
    mQuit = false;
    mGraphics = Graphics::Instance();
    if(!Graphics::Initialized())
        mQuit = true;

    mAssetMgr = AssetManager::Instance();
    mInputMgr = InputManager::Instance();
    // mAudioMgr = AudioManager::Instance();
    mTimer = Timer::Instance();

}

GameManager::~GameManager(){

    // AudioManager::Release();
	// mAudioMgr = NULL;

    AssetManager::Release();
    mAssetMgr = NULL;

    Graphics::Release();
    mGraphics == NULL;

    InputManager::Release();
    mInputMgr = NULL;
    
    Timer::Release();
    mTimer = NULL;

    delete mTex;
    mTex = NULL;
    // delete mParent;
    // delete mChild;
}

void GameManager::EarlyUpdate(){
    mTimer->Reset();
    mInputMgr->Update();
}

void GameManager::Update() {
	//GameEntity Updates should happen here
}

void GameManager::LateUpdate() {

	//Any collision detection should happen here
	mInputMgr->UpdatePrevInput();
}

void GameManager::Render() {

	//Clears the last frame's render from the back buffer
	mGraphics->ClearBackBuffer();
	//All other rendering is to happen here
	//Renders the current frame
	mGraphics->Render();
}

void GameManager::Run(){
    while(!mQuit){
        mTimer->Update();
        while(SDL_PollEvent(&mEvents) != 0){
            switch(mEvents.type){
                case SDL_QUIT: mQuit = true; break;
                case SDL_KEYDOWN:
                    if(mEvents.key.keysym.sym == SDLK_ESCAPE)
                        mQuit = true;
                    break;
            } 
        }
        if(mTimer->DeltaTime() >= (1.0f / FRAME_RATE)){  
            EarlyUpdate();
            Update();
            LateUpdate();
            Render();
        }
    }
}