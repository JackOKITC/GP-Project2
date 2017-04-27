#include "Game.h"

Game::Game(sf::ContextSettings settings) :
	m_window(sf::VideoMode(800, 600), "Introduction to OpenGL Texturing", sf::Style::Default, settings)
{
}

Game::~Game()
{
	m_cube->~Cube2();
	m_plane->~Cube2();
	delete this;
}

void Game::run()
{
	initialize();

	sf::Event event;

	while (isRunning) {

#if (DEBUG >= 2)
		DEBUG_MSG("Game running...");
#endif

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}

		update();
		render();
	}

#if (DEBUG >= 2)
	DEBUG_MSG("Calling Cleanup...");
#endif
}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);

	m_cube = new Cube2();
	m_plane = new Cube2();

	m_plane->translate(glm::vec3(0, -2, 0));
	m_plane->scale(glm::vec3(5, 0.01f, 5));
}

void Game::update()
{
#if (DEBUG >= 2)
	DEBUG_MSG("Updating...");
#endif
	m_cube->update(CubeType::Cube2);
	m_plane->update(CubeType::Ground);
}

void Game::render()
{

#if (DEBUG >= 2)
	DEBUG_MSG("Render Loop...");
#endif
	int windowWidth = m_window.getSize().x;
	int windowHeight = m_window.getSize().y;

	for (int i = 0; i < NUM_OF_VIEWS; i++)
	{
		if (i == 0)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Left Viewport 
			glViewport(-1, 60, windowWidth / 2, windowHeight);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, (GLfloat)(windowWidth) / (GLfloat)(windowHeight), 0.1f, 500.0);

			m_cube->render(CubeType::Cube2);
			m_plane->render(CubeType::Ground);
		}

		if (i == 1)
		{
			//GL_COLOR_BUFFER_BIT |
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Right Viewport 
			glViewport((windowWidth / 2) + 1, 60, windowWidth / 2, windowHeight);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0, (GLfloat)(windowWidth) / (GLfloat)(windowHeight), 0.1f, 500.0);

			m_cube->render(CubeType::Cube2);
			m_plane->render(CubeType::Ground);
		}

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		m_window.display();
	}
}