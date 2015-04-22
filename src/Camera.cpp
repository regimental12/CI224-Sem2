#include "Camera.h"


/**
 * Initialise Variables;
 */
Camera::Camera() : cameraPos ( glm::vec3(10.0f, 20.0f, -10.0f)),  projection ( glm::perspective(45.0f, (float)1366/(float)768, 0.1f, 1000.0f))
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
	
	
	/*if(e->type == SDL_MOUSEBUTTONDOWN)
	{*/
	  if(e->button.button == SDL_BUTTON_LEFT)
	  {
	      glm::vec4 viewport = glm::vec4(0.0f , 0.0f , 1366.0f , 768.0f);
	      SDL_GetMouseState(&x1, &y1);
	      int y2 = 768 - y1;
	      near = glm::unProject(glm::vec3(cameraPos.x , cameraPos.y, 0.0f) , view , projection , viewport );
	      far = glm::unProject(glm::vec3(float(x1) ,float(y2), 1.0f ), view , projection , viewport );
	      mouseDownleft = true;
	      std::cout << x1 << " " << y1 << std::endl;
	}
	 if(e->button.button == SDL_BUTTON_RIGHT )
	  {
	      glm::vec4 viewport = glm::vec4(0.0f , 0.0f , 1366.0f , 768.0f);
	      SDL_GetMouseState(&x1, &y1);
	      int y2 = 768 - y1;
	      near = glm::unProject(glm::vec3(cameraPos.x , cameraPos.y, 0.0f) , view , projection , viewport );
	      far = glm::unProject(glm::vec3(float(x1) ,float(y2), 1.0f ), view , projection , viewport );
	      mouseDownright = true;
	      std::cout << x1 << " " << y1 << std::endl;
	}
	//}
}


void Camera::update()
{
    view = glm::lookAt(cameraPos , cameraPos + cameraDir , cameraUp);
}


