#include "Camera.h"


/**
 * Initialise Variables;
 */
Camera::Camera()
	:cameraPos ( glm::vec3(10.0f, 20.0f, -10.0f)),
	 projection ( glm::perspective(45.0f, (float)1366/(float)768, 0.1f, 1000.0f)),
	 inventory(new Inventory())
{

}

/**
 * Handle input form passed in mainEvent struct. 
 */

void Camera::handleMovement(SDL_Event *e , SDL_Window* _window)
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
	   SDL_GetMouseState(&xpos , &ypos);
	  if(firstMove)
	  {
	    lastX = xpos;
	    lastY = ypos;
	    firstMove = false;
	  }
	  
	  GLfloat xoffset = xpos - lastX;
	  GLfloat yoffset = lastY - ypos;
	  
	  lastX = xpos;
	  lastY = ypos;
	  GLfloat sensitivityX = 1.0f;	
	  GLfloat sensitivityY = 0.5f;	
	  xoffset *= sensitivityX;
	  yoffset *= sensitivityY;
	  
	  yaw   += xoffset;
	  pitch += yoffset;
	  
	  if (pitch > 89.0f)
	      pitch = 89.0f;
	  if (pitch < -89.0f)
	      pitch = -89.0f;
	  
	  glm::vec3 front;
	  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	  front.y = sin(glm::radians(pitch));
	  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	  cameraDir = glm::normalize(front);
	}
	
	/**
	 * Handle mouse buttons
	 * Also invert y axis to convert SDL coords to Opengl coords.
	 */
	if(e->button.button == SDL_BUTTON_LEFT)
	{
	  SDL_GetMouseState(&x1, &y1);
	  y1 = 768 - y1; 
	  mouseDownleft = true;
	}
	if(e->button.button == SDL_BUTTON_RIGHT )
	{
	  SDL_GetMouseState(&x1, &y1);
	  y1 = 768 - y1;
	  mouseDownright = true;
	}
}


void Camera::update()
{
    view = glm::lookAt(cameraPos , cameraPos + cameraDir , cameraUp);
}


