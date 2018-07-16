#ifndef _GMANAGER_HPP
#define _GMANAGER_HPP
#include "Graphics.hpp"

class gManager {

private:
	static gManager *sInstance;
	bool _isDone;
	Graphics *mGraphics;
	SDL_Event mEvent;

private:
	gManager();
	~gManager();

public:
	static gManager *Instance();
	static void Release();
	void run();
};

#endif