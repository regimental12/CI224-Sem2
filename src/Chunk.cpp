
#include "Chunk.h"

Chunk::Chunk(){
	size = glm::vec3(16, 10, 16);
	position.x = 0;
	position.y = 0;
	position.z = 0;

	Init();
}

Chunk::Chunk(GLfloat X, GLfloat Y, GLfloat Z, Perlin noise){
	perlin = noise;
	size = glm::vec3(16, 12, 16);
	position.x = X;
	position.y = Y;
	position.z = Z;

	Init();
	std::cout << "return from init" << std::endl;
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

/*Cube* Chunk::getCubes()
{
      //return Cubes;
}*/

//int Cubecount = 0;
void Chunk::Init(){
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {

			// get noise value - using x & z because Y is our up axis
			double value = perlin.noise(5 * ((position.x*size.x)+x), 5 * ((position.z*size.z)+z), 0.8);

			//std::cout << (int)(perlin.noise(10 * ((position.x*size.x)+3), 10 * ((position.z*size.z)+9), 0.8) * size.y) << std::endl;

			yHeight[x][z] = (int)(value * size.y);

			if (yHeight[x][z] < yLOW) {
				yLOW = yHeight[x][z];
			}

			for (int y = 0; y < size.y; y++) {	// only create cubes up to our value
					Cubes[x][y][z] = new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z);

					int dirtbuffer = (rand() % 3) + 1;

					if (y >= yHeight[x][z] - dirtbuffer && y <= yHeight[x][z]) {
						//std::cout << "Cube Type " << Cubecount << std::endl;
						Cubes[x][y][z]->setType(1);
						//std::cout << "Cube Type set"  << std::endl;
					}
					
					// This fucks everything up?
					/*if(y >= (int)(value * size.y)) {
						delete(Cubes[x][y][z]);
						std::cout << "test"  << std::endl;
					}*/
					//Cubecount++;
			}
		}
	}
}

void Chunk::Render(Shader shader, Camera* camera) {

	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {
			for (int y = 0; y < yHeight[x][z]; y++) {

				//check if cube is NULL
				if (Cubes[x][y][z]) {
					if(x == 0 || y == 0 || z == 0 || x == size.x-1 || y == yHeight[x][z]-1 || z == size.z-1){
						Cubes[x][y][z]->Render(shader, camera);
					}
						if(y >= yLOW) {
							Cubes[x][y][z]->Render(shader, camera);
						}

				}
			}
		}
	}
}

void Chunk::Update(Camera*  cam){
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {
			for (int y = 0; y < size.y; y++) {
				// only attempt to collide cubes that aren't NULL
				if (Cubes[x][y][z] != NULL) {
						Collision(cam, Cubes[x][y][z]);
				}
			}
		}
	}
	if(cam->mouseDown)
	{
	  for (int x = 0; x < size.x; x++) {
		  for (int z = 0; z < size.z; z++) {
			  for (int y = 0; y < size.y; y++) {
				  // only attempt to collide cubes that aren't NULL
				  if (Cubes[x][y][z] != NULL) {
					if(RayCollision(cam->near , cam->far , Cubes[x][y][z]))
					{
					  Cubes[x][y][z] = NULL;
					  cam->mouseDown = false;
					}
				  }
			  }
		  }
	  }
	}
}
