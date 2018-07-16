#include "gManager.hpp"

gManager* gManager::sInstance = nullptr;

gManager* gManager::Instance(){
	if(sInstance == NULL){
		sInstance = new gManager();
	}
	return sInstance;
}

void gManager::Release(){
	delete sInstance;
	sInstance = nullptr;
}

gManager::gManager(){
	_isDone = false;
	mGraphics = Graphics::Instance();

	if (!Graphics::Initialized()){
		_isDone = true;
	}
}

gManager::~gManager(){
	Graphics::Release();
	mGraphics = nullptr;
}

void gManager::run(){
	while (!_isDone) {
		while (SDL_PollEvent(&mEvent) != 0){
			if (mEvent.type == SDL_QUIT || (mEvent.type == SDL_KEYDOWN &&
			mEvent.key.keysym.sym == SDLK_ESCAPE)){
				_isDone = true;
			}
			mGraphics->Render();
		}
	}
}