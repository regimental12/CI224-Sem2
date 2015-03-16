#ifndef _GAMEH_
#define _GAMEH_

#include "SDL2/SDL.h"
#define GLEW_STATIC
#include "GL/glew.h"
#include "GL/gl.h"
//#include "GL/glut.h"
#include "GL/glx.h"
#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include <iostream>
#include <vector>


#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Game
{
public:
  Game();
  ~Game();
  void Init();
  void Loop();
  void CleanUp();
  void Render();
  void Update();
  void HandleEvents(SDL_Event);
  void objinit();
  
private:
  SDL_Window* _window;
  SDL_Event mainEvent;
  SDL_GLContext glContext;
  bool _running;
  Shader shader;
  Cube* cube;
  glm::mat4 view;
  glm::mat4 projection;
  Camera *camera;
  std::vector<Cube*> Cubes;
  
};

#endif
