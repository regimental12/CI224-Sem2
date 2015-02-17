#ifndef _SHADERH_
#define _SHADERH_

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

class Shader
{
public:
  Shader();
  ~Shader();
  void loadShader(std::string vFilename ,std::string fFilename);
  void useShader();

private:
  GLuint program;
  std::string code;
  std::string vertexCode;
  std::string fragmentCode;
};

#endif
