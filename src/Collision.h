#ifndef _COLLISIONH_
#define _COLLISIONH_

#include "Camera.h"
#include "Cube.h"
#include <cmath>
#include <iostream>
#define GLM_FORCE_RADIANS

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

static int count = 0;

static void Collision(Camera* playerCam, Cube* cube)
{   
	if(playerCam->cameraPos.x <= (cube->getPosition().x +0.5  ) && cube->getPosition().x <= (playerCam->cameraPos.x + 0.5  ) &&
	playerCam->cameraPos.y <= (cube->getPosition().y + 0.5 ) && cube->getPosition().y <= (playerCam->cameraPos.y + 0.5 ) && 
	playerCam->cameraPos.z <= (cube->getPosition().z + 0.5 ) && cube->getPosition().z <= (playerCam->cameraPos.z +0.5 ) )
	{
	  std::cout << "Bang!" << count << std::endl;
	  
	  count++;
	  playerCam->cameraPos -= playerCam->cameraSpeed * playerCam->cameraDir;
	}
  
//     float x = fabs(cube->getPosition().x - playerCam->cameraPos.x);
//     float y = fabs(cube->getPosition().y - playerCam->cameraPos.y);
//     float z = fabs(cube->getPosition().z - playerCam->cameraPos.z); 
//     
//     float collisionDist = x+y+z;
//     
//     if( collisionDist <= 0.775f)
//     {  
// 	  std::cout << "Bang!" << count << std::endl;
// 	  std::cout << x << " " << y << " " << z << std::endl;
// 	  count++;
// 	  playerCam->cameraPos -= playerCam->cameraSpeed * playerCam->cameraDir;
//     }
}

static bool Collision(Camera* playerCam, Cube* cube , int i)
{   
	if(playerCam->cameraPos.x <= (cube->getPosition().x +0.5  ) && cube->getPosition().x <= (playerCam->cameraPos.x + 0.5  ) &&
	playerCam->cameraPos.y <= (cube->getPosition().y + 0.5 ) && cube->getPosition().y <= (playerCam->cameraPos.y + 0.5 ) && 
	playerCam->cameraPos.z <= (cube->getPosition().z + 0.5 ) && cube->getPosition().z <= (playerCam->cameraPos.z +0.5 ) )
	{
	  std::cout << "Bang!" << count << std::endl;
	  
	  count++;
	  playerCam->cameraPos -= playerCam->cameraSpeed * playerCam->cameraDir;
	  return true;
	}
	return false;
}

static bool RayCollision(glm::vec3 near , glm::vec3 far , Cube* cube)
{
    glm::vec3 dirToShpere = cube->getPosition() - near;
    
    glm::vec3  lineDir = glm::normalize(far - near);
    
    float lineLength = glm::distance(near , far);
    
    float t = glm::dot(dirToShpere , lineDir);
    
    glm::vec3 closestPoint;
    if(t <= 0.0f)
    {
      closestPoint = near;
    }
    else if(t >= lineLength)
    {
      closestPoint = far;
    }
    else
    {
      closestPoint = near+ lineDir * t;
    }
    
    if(glm::distance(cube->getPosition() , closestPoint) < 0.5f)
    {
      std::cout << "rayhit" << std::endl;
      return true;
    }
    return false;
}

#endif






