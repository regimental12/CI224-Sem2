#include "Camera.h"


/**
 * Initialise Variables;
 */
Camera::Camera() : cameraPos ( glm::vec3(0.0f, 0.0f, 10.0f)),  projection ( glm::perspective(45.0f, (float)1024/(float)768, 0.1f, 1000.0f))
{
   

    
}

/**
 * Handle input form passed in mainEvent struct.
 * @bug
 * movement does not work as intended. camera will move for a certain amount then stop.
 * also camera suffers from gimble lock.
 * need to move over to quaternions in the future.
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
	   //SDL_WarpMouseInWindow(_window,1920/2,1080/2); 
	  
	  /*
	   GLfloat sens = 0.01f;
	  SDL_ShowCursor(SDL_DISABLE);
	  int midX = 1920/2;
	  int midY = 1080/2;
	  SDL_MouseMotionEvent mouse;
	  SDL_GetMouseState(&xPos , &yPos);
	  
	  int x = midX - xPos;
	  int y = midY - yPos;
	    
	  cameraDir.x = (-x * sens);
	  cameraDir.y = (y   * sens);
	 

	  int MidX=1920/2;   //middle of the screen
	  int MidY=1080/2;
	  // SDL_ShowCursor(SDL_DISABLE);    //we don't show the cursor
	  int tmpx,tmpy;
	  SDL_GetMouseState(&tmpx,&tmpy); //get the current position of the cursor
	  cameraDir.x +=sens*(MidX-tmpx);   //get the rotation, for example, if the mouse current position is 315, than 5*0.2, this is for Y
	  cameraDir.y +=sens*(MidY-tmpy); //this is for X
          */
	}
}


void Camera::update()
{
    view = glm::lookAt(cameraPos , cameraPos + cameraDir , cameraUp);    
    
}


