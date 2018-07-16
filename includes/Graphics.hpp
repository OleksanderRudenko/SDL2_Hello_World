#ifndef _GRAPHICS_HPP
#define _GRAPHICS_HPP
#include "SDL2/SDL.h"
#include <iostream>

class Graphics
{

public:
	static const int WIDTH = 640;
	static const int HEIGHT = 480;

public:

	static Graphics *Instance();
	static bool Initialized();
	static void Release();
	void Render();

private:

	static Graphics *sInstance;
	static bool sInitialized;
	SDL_Window *_window;
	SDL_Surface	*_surf;

private:
	bool Init();
	Graphics();
	~Graphics();



};

#endif