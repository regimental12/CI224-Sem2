/*
 * SkyBox.h
 *
 *  Created on: 15 Apr 2015
 *      Author: George
 */

#ifndef SRC_SKYBOX_H_
#define SRC_SKYBOX_H_

#include "GL/glew.h"
#include "GL/gl.h"
#include <iostream>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ImageLoader.h"
#include "Shader.h"
#include "Camera.h"

class SkyBox {
public:
	SkyBox();
	~SkyBox();

	void loadSkyBox();
	void Render(Shader shader , Camera* camera);

	//setters
	void setPosition(glm::vec3 pos) { position = pos; }
	//void setTexture() { texture = ImageLoader::getInstance()->GetTexture(3); }

	//getters
	glm::vec3 getPosition() { return position; }
	GLuint getTexture () { return texture; }

private:
	glm::vec3 position;
	GLuint texture;
	GLuint VBO, VAO;
	//ImageLoader *iLoader;
	GLfloat vertices[36*5] =
	{
	  //X,   Y,     Z,      U,   V
	 -50.0f, -50.0f, -50.0f,  0.0f, 0.0f,
	  50.0f, -50.0f, -50.0f,  1.0f, 0.0f,
	  50.0f,  50.0f, -50.0f,  1.0f, 1.0f,
	  50.0f,  50.0f, -50.0f,  1.0f, 1.0f,
	 -50.0f,  50.0f, -50.0f,  0.0f, 1.0f,
	 -50.0f, -50.0f, -50.0f,  0.0f, 0.0f,

	 -50.0f, -50.0f,  50.0f,  0.0f, 0.0f,
	  50.0f, -50.0f,  50.0f,  1.0f, 0.0f,
	  50.0f,  50.0f,  50.0f,  1.0f, 1.0f,
	  50.0f,  50.0f,  50.0f,  1.0f, 1.0f,
	 -50.0f,  50.0f,  50.0f,  0.0f, 1.0f,
	 -50.0f, -50.0f,  50.0f,  0.0f, 0.0f,

	 -50.0f,  50.0f,  50.0f,  1.0f, 0.0f,
	 -50.0f,  50.0f, -50.0f,  1.0f, 1.0f,
	 -50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	 -50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	 -50.0f, -50.0f,  50.0f,  0.0f, 0.0f,
	 -50.0f,  50.0f,  50.0f,  1.0f, 0.0f,

	  50.0f,  50.0f,  50.0f,  1.0f, 0.0f,
	  50.0f,  50.0f, -50.0f,  1.0f, 1.0f,
	  50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	  50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	  50.0f, -50.0f,  50.0f,  0.0f, 0.0f,
	  50.0f,  50.0f,  50.0f,  1.0f, 0.0f,

	 -50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	  50.0f, -50.0f, -50.0f,  1.0f, 1.0f,
	  50.0f, -50.0f,  50.0f,  1.0f, 0.0f,
	  50.0f, -50.0f,  50.0f,  1.0f, 0.0f,
	 -50.0f, -50.0f,  50.0f,  0.0f, 0.0f,
	 -50.0f, -50.0f, -50.0f,  0.0f, 1.0f,
	 -50.0f,  50.0f, -50.0f,  0.0f, 1.0f,
	  50.0f,  50.0f, -50.0f,  1.0f, 1.0f,
	  50.0f,  50.0f,  50.0f,  1.0f, 0.0f,
	  50.0f,  50.0f,  50.0f,  1.0f, 0.0f,
	 -50.0f,  50.0f,  50.0f,  0.0f, 0.0f,
	 -50.0f,  50.0f, -50.0f,  0.0f, 1.0f
	};
};

#endif /* SRC_SKYBOX_H_ */
