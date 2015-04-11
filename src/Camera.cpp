#include "Camera.h"


/**
 * Initialise Variables;
 */
Camera::Camera() : xPos(1024/2), yPos(768/2), xOffSet(0), yOffSet(0),cameraPos ( glm::vec3(0.0f, 0.0f, 10.0f)),  projection ( glm::perspective(45.0f, (float)1024/(float)768, 0.1f, 1000.0f))
{
   

    
}

/**
 * Handle input form passed in mainEvent struct.
 * @bug
 * movement does not work as intended. camera will move for a certain amount then stop.
 * also camera suffers from gimble lock.
 * need to move over to quaternions in the future.
 */
void Camera::handleMovement(SDL_Event *e)
{
        if (e->type == SDL_KEYDOWN )
        {
            switch (e->key.keysym.sym)
            {
                case SDLK_UP:
                    cameraPos += cameraSpeed * cameraDir;
                    break;
                case SDLK_DOWN:
                    cameraPos -= cameraSpeed * cameraDir;
                    break;
                case SDLK_LEFT:
                    cameraPos -= glm::cross(cameraDir, cameraUp) * cameraSpeed;
                    break;
                case SDLK_RIGHT:
                    cameraPos += glm::cross(cameraDir, cameraUp) * cameraSpeed;
                    break;
		
            }
        }

        else if (e->type == SDL_KEYUP && e->key.repeat == 1)
        {
            switch (e->key.keysym.sym)
            {
                case SDLK_UP:
                    cameraPos -= cameraSpeed * cameraDir;
                    break;
                case SDLK_DOWN:
                    cameraPos += cameraSpeed * cameraDir;
                    break;
                case SDLK_LEFT:
                    cameraPos += glm::cross(cameraDir, cameraUp) * cameraSpeed;
                    break;
                case SDLK_RIGHT:
                    cameraPos -= glm::cross(cameraDir, cameraUp) * cameraSpeed;
                    break;
            }
        }

        
        if(e->type == SDL_MOUSEMOTION)
	{
	  int midX = 1024/2;
	  int midY = 768/2;
	  SDL_MouseMotionEvent mouse;
	  SDL_GetMouseState(&xPos , &yPos);
	  
	  GLfloat sens = 0.01f;
	  int x = midX - xPos;
	  int y = midY - yPos;
	  	  
	  cameraDir.x = (-x * sens);
	  cameraDir.y = (y * sens);
	  
	  /**
	   * used for debug
	   */ 
	 //std::cout <<  "x: " << xPos << "\n" ;
	  //std::cout <<  "y: " << yPos << "\n" ;
	}
}


void Camera::update()
{
     view = glm::lookAt(cameraPos , cameraPos + cameraDir , cameraUp);
}


