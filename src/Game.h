#ifndef _GAMEH_
#define _GAMEH_

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include <iostream>

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
  
private:
  SDL_Window* _window;
  SDL_Event mainEvent;
  SDL_GLContext glContext;
  bool _running;
  
};

#endif
