#include "Graphics.hpp"

Graphics* Graphics::sInstance = nullptr;
bool Graphics::sInitialized = false;

Graphics* Graphics::Instance() {
	if (sInstance == nullptr){
		sInstance = new Graphics();
	}
	return sInstance;
}

void Graphics::Release(){
	delete sInstance;
	sInstance = nullptr;
	sInitialized = false;
}

bool Graphics::Initialized(){
	return sInitialized;
}

Graphics::Graphics(){
	_surf = nullptr;
	_window = nullptr;
	sInitialized = Init();
}

Graphics::~Graphics(){
	SDL_DestroyWindow(_window);
	_window = NULL;
	SDL_Quit();
}

bool Graphics::Init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == NULL) {
		std::cout << SDL_GetError() << std::endl;
		return false;
	}
	_surf = SDL_GetWindowSurface(_window);
	return true;
}

void Graphics::Render(){
	SDL_UpdateWindowSurface(_window);
}