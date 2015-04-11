#ifndef _GAMEH_
#define _GAMEH_

#include "SDL2/SDL.h"
//#define GLEW_STATIC
#include "GL/glew.h"
#include "GL/gl.h"
//#include "GL/glut.h"
#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include <iostream>
#include "World.h"
#include "Chunk.h"

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
  void HandleEvents(SDL_Event e , SDL_Window* _window);
  void objinit();
  SDL_Window* _window;
private:
  
  SDL_Event mainEvent;
  SDL_GLContext glContext;
  bool _running;
  Shader shader;
  glm::mat4 view;
  glm::mat4 projection;
  Camera *camera;
  World *world;
  bool wireframe = false;
  
};

#endif
