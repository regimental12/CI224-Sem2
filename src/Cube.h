#ifndef _CUBEH_
#define _CUBEH_


#include "ImageLoader.h"
#include "Shader.h"
#include "Camera.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include <iostream>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



class Cube 
{
public:
  Cube();
  Cube(GLfloat x, GLfloat y, GLfloat z);
  ~Cube();
  glm::vec3 getPosition();
  void setPosition(GLfloat x , GLfloat y , GLfloat z);
  void Render(Shader shader , Camera* camera);
  ImageLoader* iLoader;
  GLuint getTexture();
  void setTexture(std::string fileName);
  void loadCube();
  GLuint getVAO();
  GLuint getVBO();

private:
  glm::vec3 position;
  GLuint texture;
  GLuint VBO, VAO;
  GLfloat vertices[36*5] =
  {
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	    };
};

#endif
