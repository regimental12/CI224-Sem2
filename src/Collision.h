#ifndef _COLLISIONH_
#define _COLLISIONH_

#include "Camera.h"
#include "Cube.h"
#include <cmath>
#include <iostream>
#define GLM_FORCE_RADIANS

/*#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"*/

static int count = 0;

static void Collision(Camera* playerCam, Cube* cube)
{    
    int x = cube->getPosition().x - playerCam->cameraPos.x;
    int y = cube->getPosition().y - playerCam->cameraPos.y;
    int z = cube->getPosition().z - playerCam->cameraPos.z; 
    
    int collisionDist = x*x + y*y + z*z;
    
    if( collisionDist < 1)
    {
      std::cout << "Bang!" << count << std::endl;
      count++;
      playerCam->cameraPos -= playerCam->cameraSpeed * playerCam->cameraDir;
      
    }
    
    
}

#endif