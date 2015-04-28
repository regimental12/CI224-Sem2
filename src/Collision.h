
#ifndef _COLLISIONH_
#define _COLLISIONH_

#include "Camera.h"
#include "Cube.h"
#include <cmath>
#include <iostream>
#define GLM_FORCE_RADIANS

#define GLM_SWIZZLE
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
}

static bool Collision1(Cube* cube, glm::vec4 ray)
{   
	if(ray.x <= (cube->getPosition().x +0.5  ) && cube->getPosition().x <= (ray.x + 0.5  ) &&
	ray.y <= (cube->getPosition().y + 0.5 ) && cube->getPosition().y <= (ray.y + 0.5 ) && 
	ray.z <= (cube->getPosition().z + 0.5 ) && cube->getPosition().z <= (ray.z +0.5 ) )
	{
	  std::cout << "Collision1" << count << std::endl;
	  return true;
	}
	return false;
}

/*static bool RayCollision(glm::vec3 near , glm::vec3 far , Cube* cube)
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
    
    if(glm::distance(cube->getPosition() , closestPoint) <= 1.0f)
    {
      std::cout << "rayhit" << std::endl;
      return true;
    }
    return false;
}*/

static bool rayCol(int mouse_x , int mouse_y  , Camera* cam , Cube* cube)
{
  float x = (2.0f * mouse_x) / 1366 - 1.0f;
  float y = 1.0f - (2.0f * mouse_y) / 768;
  float z = 1.0f;
  glm::vec3 ray_nds(x,y,z);
  glm::vec4 ray_clip(ray_nds.x, ray_nds.y , -1.0 , 1.0 );
  glm::vec4 ray_eye = glm::inverse(cam->projection) * ray_clip;
  
  ray_eye = glm::vec4(ray_eye.x , ray_eye.y,-1.0 , 1.0);
  
  //glm::vec3 ray_eye1 = ray_eye.xyz();
  glm::vec4 ray_wor = glm::inverse (cam->view) * ray_eye;
  if(Collision1(cube , ray_wor))
  {
    return true;
  }
  return false;
}

#endif






