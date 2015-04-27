
#include "Chunk.h"
#include "Inventory.h"

Chunk::Chunk(){
      size = glm::vec3(16, 10, 16);
      position.x = 0;
      position.y = 0;
      position.z = 0;
      Init();
}

Chunk::Chunk(GLfloat X, GLfloat Y, GLfloat Z, Perlin noise){
      perlin = noise;
      size = glm::vec3(16, 48, 16);
      position.x = X;
      position.y = Y;
      position.z = Z;
      Init();
}

Chunk::~Chunk(){
      for (int x = 0; x < size.x; x++) {
	    for (int z = 0; z < size.z; z++) {
		  for (int y = 0; y < size.y; y++) {	// only create cubes up to our value
			delete Cubes[x][y][z];
		  }
	    }
      }
}

void Chunk::Init(){
      for (int x = 0; x < size.x; x++) {
	    for (int z = 0; z < size.z; z++) {
		  double value = perlin.noise(((position.x*size.x)+x), ((position.z*size.z)+z), 0.8);
		  
		  yHeight[x][z] = (int)(value * size.y);
		  
		  if (yHeight[x][z] < yLOW) {
			yLOW = yHeight[x][z];
		  }
		  
		  for (int y = 0; y < size.y; y++) {	// only create cubes up to our value
			Cubes[x][y][z] = new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z);
			
			int dirtbuffer = (rand() % 3) + 1;
			
			// between yheight and dirtbuffer away from yheight
			if (y >= yHeight[x][z] - dirtbuffer && y <= yHeight[x][z]) {
			      
			      Cubes[x][y][z]->setType(1);
			      
			} else if (y < yHeight[x][z] - dirtbuffer) {
			      Cubes[x][y][z]->setType(2);
			}
			else{
			      Cubes[x][y][z]->setType(0);
			}
		  }
	    }
      }
}

void Chunk::Render(Shader shader, Camera* camera) {
      
      for (int x = 0; x < size.x; x++) {
	    for (int z = 0; z < size.z; z++) {
		  for (int y = 0; y < size.y; y++) {
			
			//check if cube is not NULL or if cube type is NOT 0 which is air
			if (Cubes[x][y][z] || Cubes[x][y][z]->getType() != 0) {
			      
			      // render cubes on edges of chunks
			      if(x == 0 || x == size.x -1 ||
				    y == 0 || y == size.y -1 ||
				    z == 0 || z == size.z -1) {
				    Cubes[x][y][z]->Render(shader, camera);
			      
			      //if one of 6 neighbours is air
				    } else if (Cubes[x][y+1][z]->getType() == 0 ||
					  Cubes[x][y-1][z]->getType() == 0 ||
					  Cubes[x+1][y][z]->getType() == 0 ||
					  Cubes[x-1][y][z]->getType() == 0 ||
					  Cubes[x][y][z+1]->getType() == 0 ||
					  Cubes[x][y][z-1]->getType() == 0) {
					  Cubes[x][y][z]->Render(shader, camera);
					  }
			}
		  }
	    }
      }
}

void Chunk::Update(Camera* cam) {
      for (int x = 0; x < size.x; x++) {
	    for (int z = 0; z < size.z; z++) {
		  for (int y = 0; y < size.y; y++) {
			// only attempt to collide cubes that aren't NULL
			if (Cubes[x][y][z]->getType() != 0) {
			      Collision(cam, Cubes[x][y][z]);
			}
			if (cam->mouseDownleft) {
			      if (Cubes[x][y][z] != 0) {
				    if (rayCol(cam->x1, cam->y1, cam, Cubes[x][y][z])) {
					  GLuint placed = Cubes[x][y][z]->getType();
					  Cubes[x][y][z]->setType(0);
					  cam->inventory->incBlockCount(placed);
					  cam->mouseDownleft = false;
				    }
			      }
			}
			if (cam->mouseDownright) {
			      if (Cubes[x][y][z]->getType() == 0) {
				    if (rayCol(cam->x1, cam->y1, cam, Cubes[x][y][z])) {
					  if(cam->inventory->getBlockCount(cam->placeType) > 0)
					  {
						Cubes[x][y][z]->setType(cam->getPlaceType());
						cam->inventory->decBlockCount(Cubes[x][y][z]->getType());
						cam->mouseDownright = false;
					  }
				    }
			      }
			}
		  }
	    }
      }
}
