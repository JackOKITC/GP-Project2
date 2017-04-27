#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "GL\glew.h"
#include "GL\wglew.h"

#include <windows.h> 
#include <gl\gl.h> 
#include <gl\glu.h> 

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

#include "Debug.h"

#include "Cube2.h"

class Game
{
public:
	Game(sf::ContextSettings settings);
	~Game();
	void run();

private:
	sf::Window m_window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();

	Cube2 *m_cube;
	Cube2 *m_plane;

	const int NUM_OF_VIEWS = 2;
};
#endif