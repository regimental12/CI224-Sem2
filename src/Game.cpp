#include "Game.h"

Game::Game()
{
  _window = NULL;
  _running = false;
  glContext = NULL;
  cube = new Cube;
}

Game::~Game()
{
    
}

void Game::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    _window = SDL_CreateWindow("Voxel Game 2.0" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_OPENGL);

    glContext = SDL_GL_CreateContext(_window);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, 1024, 768);

    glEnable(GL_DEPTH_TEST);
    std::cout << "init\n";
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    shader.loadShader("shaders/Vert.vrt" , "shaders/Frag.frg");
    
    _running = true;
}

void Game::CleanUp()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Game::Loop()
{
    while (_running)
    {
        while (SDL_PollEvent(&mainEvent))
        {
            HandleEvents(mainEvent);
        }

        Update();

        Render();

        SDL_GL_SwapWindow(_window);
    }
}

void Game::HandleEvents(SDL_Event e)
{
	switch (e.type) {
	case SDL_QUIT:
		_running = false;
		break;
	}
}

void Game::Update()
{

}

void Game::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	 glm::vec3 cubePositions[10] [10] [10] ;
	   for(int x = 0 ; x < 10 ; x++ )
	   {
	     for ( int y = 0 ; y < 10 ;y++)
	     {
	       for (int z = 0 ;z < 10 ; z++)
	       {
		cubePositions[x][y][z] =  glm::vec3(x, y , z);
	       }
	     }
	   }
	   
	   glm::vec3 cubePositions2[10] [10] [10] ;
	   for(int x = 0 ; x < 10 ; x++ )
	   {
	     for ( int y = 0 ; y < 10 ;y++)
	     {
	       for (int z = 0 ;z < 10 ; z++)
	       {
		cubePositions2[x][y][z] =  glm::vec3(x+10, y+10 , z+10);
	       }
	     }
	   }
    
    shader.useShader();
   
    GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
    GLint viewLoc = glGetUniformLocation(shader.getProgram(), "view");
    GLint projLoc = glGetUniformLocation(shader.getProgram(), "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
/**
 * Loop through both arrays and render.
 */
    glBindVertexArray(cube->getVAO());
	  for(int x = 0 ; x < 10 ; x++ )
	   {
	     for ( int y = 0 ; y < 10;y++)
	     {
	       for (int z = 0 ;z < 10; z++)
	       {
		  glBindTexture(GL_TEXTURE_2D, cube->getTexture());
		  glm::mat4 model;
		  model = glm::translate(model, cubePositions[x][y][z]);
		  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		  glDrawArrays(GL_TRIANGLES, 0, 36);
		  glBindTexture(GL_TEXTURE_2D , 0);
		}
	     }
	   }
    glBindVertexArray(0);

    
}