#ifndef _CUBEH_
#define _CUBEH_

#include "GL/gl.h"
#include "GL/glew.h"
#include "glm/glm.hpp"
#include <iostream>

class Cube 
{
public:
  Cube();
  ~Cube();
  glm::vec3 getPosition();
  glm::vec3 setPosition(GLuint x , GLuint y , GLuint z);
  
  GLuint getTexture();
  void setTexture(std::string fileName);

private:
  glm::vec3 position;
  GLuint texture;
  GLfloat verticies[36];  
};

#endif