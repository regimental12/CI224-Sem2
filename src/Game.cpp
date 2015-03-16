#include "Game.h"

Game::Game()
{
  _window = NULL;
  _running = false;
  glContext = NULL;
  camera = new Camera();
}

Game::~Game()
{
    
}

void Game::Init()
{
  
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 3);
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
    cube = new Cube;
}

void Game::CleanUp()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

GLfloat i = 0 , j = 0 , k = 0;
void Game::Loop()
{
    while (_running)
    {
        while (SDL_PollEvent(&mainEvent))
        {
            HandleEvents(mainEvent);
	    
        }
        camera->handleMovement(&mainEvent);
	camera->update();
        Update();
	cube->setPosition(i,j,k);

        Render();

        SDL_GL_SwapWindow(_window);
    }
    i++;
    j++;
    k++;
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
    cube->Render(shader , camera);
}

    


