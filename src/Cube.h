/**
 * Cube class
 */
#ifndef _CUBEH_
#define _CUBEH_

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

class Cube 
{
public:
      enum Type {
	    Air = 0, Dirt = 1, Stone = 2
      };
      
      Cube();
      Cube(GLfloat x, GLfloat y, GLfloat z);
      ~Cube();
      glm::vec3 getPosition();
      void setPosition(GLfloat x , GLfloat y , GLfloat z);
      void Render(Shader shader , Camera* camera);
      
      GLuint getTexture();
      void loadCube();
      GLuint getVAO();
      GLuint getVBO();
      
      void setType(GLuint cubeType);
      GLuint getType();
      
private:
      glm::vec3 position;
      GLuint texture;
      GLuint type;
      GLuint VBO, VAO;
      ImageLoader *iLoader;
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

