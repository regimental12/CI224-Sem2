#ifndef _COLLISIONH_
#define _COLLISIONH_

#include "Camera.h"
#include "Cube.h"
#include <cmath>
#include <iostream>

static int count = 0 ;

static bool Collision(Camera* playerCam , Cube* cube)
{
    float playerLeft = playerCam->cameraPos.x  - 0.5f;
    float playerRight = playerCam->cameraPos.x + 0.5f;
    
    float playerBottom = playerCam->cameraPos.y - 0.5f;
    float playerTop = playerCam->cameraPos.y + 0.5f;
    
    float playerBack = playerCam->cameraPos.z - 0.5f;
    float playerFront = playerCam->cameraPos.z + 0.5f;
    
    float cubeLeft = cube->getPosition().x + 0.5f ;
    float cubeRight = cube->getPosition().x - 0.5f;
    
    float cubeBottom = cube->getPosition().y + 0.5f;
    float cubeTop= cube->getPosition().y - 0.5f;
    
    float cubeBack = cube->getPosition().z + 0.5f;
    float cubeFront = cube->getPosition().z - 0.5f;
    
    if(playerLeft > cubeRight)
    {
      if(playerTop > cubeBottom)
      {
	if(playerFront > cubeBack)
	{
	  //std::cout << "Bang!" << count << std::endl;
	  count++;
	  return true;
	}
      }
    }
        
    //std::cout << "no Bang!" << std::endl;
    return false;
}

#endif
