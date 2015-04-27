#ifndef _GAMEH_
#define _GAMEH_

#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include "SkyBox.h"
#include <iostream>
#include "World.h"
#include "Chunk.h"
#include "ImageLoader.h"

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
      Shader skyShader;
      glm::mat4 view;
      glm::mat4 projection;
      Camera *camera;
      World *world;
      SkyBox *skyBox;
      bool wireframe = false;
      ImageLoader* iLoader;
      
};

#endif
