#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 		

#pragma comment (lib,"opengl32.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment( lib, "glu32.lib" )		

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Game.h"

///	Cube VR Project
///	Author: Jack O'Kelly
///	Ver: 1.0
///	Brief: We were tasked with making a project that would simulate VR
///	and be compatible with most phone based VR headsets.
///	Time taken: 15.5 hours

int main(void)
{
	sf::ContextSettings settings;
	settings.depthBits = 24u;
	settings.antialiasingLevel = 4u;
	Game& game = Game(settings);
	game.run();
}