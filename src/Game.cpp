#include "Game.h"

Game::Game()
{
  _window = NULL;
  _running = false;
  glContext = NULL;
  camera = new Camera();
  world = NULL;
}

Game::~Game()
{
    delete(_window);
    delete(camera);
    delete(world);
}

void Game::Init()
{
  
    SDL_Init(SDL_INIT_EVERYTHING);
    //SDL_SetRelativeMouseMode(SDL_TRUE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION , 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    _window = SDL_CreateWindow("Voxel Game 2.0" , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_OPENGL);
    
    glContext = SDL_GL_CreateContext(_window);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, 1366, 768);

    glEnable(GL_DEPTH_TEST);
    std::cout << "init\n";
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    shader.loadShader("shaders/Vert.vrt" , "shaders/Frag.frg");
    
    _running = true;
    objinit();
}

void Game::objinit()
{
	world = new World();
	std::cout << "loaded data" << std::endl;
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
        while (SDL_PollEvent(&mainEvent) != 0)
        {
            HandleEvents(mainEvent , _window);
        }

        Update();
	
        Render();

        SDL_GL_SwapWindow(_window);
    }

}

void Game::HandleEvents(SDL_Event e ,SDL_Window*  _window)
{
	switch (e.type) {
	case SDL_QUIT:
		_running = false;
		break;
	}

	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		//IF f1 pressed Toggle wireframe mode
		case SDLK_F1:
			wireframe = !wireframe;
			break;
		}
	}
	camera->handleMovement(&mainEvent , _window);
	
    
}

void Game::Update()
{
	camera->update();
	world->Update(camera);
}

void Game::Render()
{
	//checks wireframe bool and sets LINE or FILL mode accordingly
	if(wireframe) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	} else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	world->Render(shader, camera);
}

    


