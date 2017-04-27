#ifndef CUBE2_H
#define CUBE2_H

	//Cube Vertices
	/*
			(-1.0f, 1.0f, -1.0f)          (1.0f, 1.0f, -1.0f)
					[7]                          [6]
					 #-----------------------------#
					/|                            /|
				   / |                           / |
			(-1.0f, 1.0f, 1.0f)           (1.0f, 1.0f, 1.0f)
			 [3] /                         [2] /
				#-----------------------------#    |
				|    |                        |    |
				|    |                        |    |
				|   [4]                       |   [5]
		(-1.0f, -1.0f, -1.0f)         (1.0f, -1.0f, -1.0f)
				|    #-----------------------------#
				|   /                         |   /
				|  /                          |  /
				| /                           | /
				|/                            |/
				#-----------------------------#
				[0]                           [1]
		(-1.0f, -1.0f, 1.0f)         (1.0f, -1.0f, 1.0f)
	*/

#include "GL\glew.h"
#include "GL\wglew.h"

#include "glm.hpp"
#include "gtc\matrix_transform.hpp"

#include "SFML\Window.hpp"
#include "SFML\OpenGL.hpp"

#include "Debug.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "SFML\Graphics.hpp"
#include "Cube.h"

enum class CubeType
{
	Ground,
	Cube2
};

class Cube2
{
public:
	Cube2();
	~Cube2();

	void update(CubeType cubeType);
	void render(CubeType cubeType);

	void create(glm::mat4 &model, CubeType cubeType);
	void translate(glm::vec3 translation);
	void scale(glm::vec3 scale);

	void unload();
	void move();

private:
	glm::mat4 mvp, projection, view, model;	// Model View Projection

	sf::Vector2i mousePos;
	sf::Vector2i prevMousePos;

	unsigned char* img_data;			// image data

	const std::string filename = ".//Assets//Textures//texture.tga";

	int width;			// Width of texture
	int height;			// Height of texture
	int componentNum;		// Component of texture


	GLuint	vsid,		// Vertex Shader ID
		fsid,		// Fragment Shader ID
		progID,		// Program ID
		vao = 0,	// Vertex Array ID
		vbo,		// Vertex Buffer ID
		vib,		// Vertex Index Buffer
		to,			// Texture ID 1 to 32
		positionID,	// Position ID
		colorID,	// Color ID
		textureID,	// Texture ID
		uvID,		// UV ID
		mvpID;		// Model View Projection ID
};
#endif	// !CUBE2_H