#ifndef _COLLISIONH_
#define _COLLISIONH_

#include "Camera.h"
#include "Cube.h"
#include <cmath>
#include <iostream>

static bool Collision(Camera* playerCam , Cube* cube)
{
    //check the X axi
   if((playerCam->cameraPos.x + 0.5f  <  cube->getPosition().x - 0.5f))// || (playerCam->cameraPos.x - 0.5f  >  cube->getPosition().x + 0.5f))// player right, cube left
   {
	if((playerCam->cameraPos.y - 0.5f  <  cube->getPosition().y + 0.5f))// || (playerCam->cameraPos.y + 0.5f >  cube->getPosition().y - 0.5f)) // player bottom , cube top
	{
	    if((playerCam->cameraPos.z - 0.5f  <  cube->getPosition().z + 0.5f))// || (playerCam->cameraPos.z + 0.5f  >  cube->getPosition().z - 0.5f)) // player top , cube bottom
	    {
		    std::cout << "bang!" << std::endl;
		    return true;
	    }
	}
   }
        
    //std::cout << "no Bang!" << std::endl;
    return false;
}

#endif