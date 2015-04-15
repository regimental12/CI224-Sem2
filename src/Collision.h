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
    
    if(glm::distance(cube->getPosition() , closestPoint) < 1.0f)
    {
      std::cout << "rayhit" << std::endl;
      return true;
    }
    return false;
}

#endif






