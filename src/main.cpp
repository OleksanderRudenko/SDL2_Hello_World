#include <iostream>
#include "Graphics.hpp"
#include "gManager.hpp"

int main()
{
	gManager *game;
	game = gManager::Instance();
	game->run();
	gManager::Release();
	game = nullptr;
	// std::cout << "Hello, world" << std::endl;

	return (0);
}