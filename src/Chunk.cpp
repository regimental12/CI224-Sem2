#include "Chunk.h"

Chunk::Chunk(){
	size = glm::vec3(4, 3, 4);
	position.x = 0;
	position.y = 0;
	position.z = 0;

	Init();
}

Chunk::Chunk(GLfloat X, GLfloat Y, GLfloat Z){
	size = glm::vec3(16, 24, 16);
	position.x = X;
	position.y = Y;
	position.z = Z;

	Init();
}

Chunk::~Chunk(){

}

/*Cube* Chunk::getCubes()
{
      //return Cubes;
}*/


void Chunk::Init(){
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			for (int z = 0; z < size.z; z++) {
				Cubes[x][y][z] = new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z);
			}
		}
	}
}

void Chunk::Render(Shader shader, Camera* camera) {
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			for (int z = 0; z < size.z; z++) {
				// only attempt to render cubes that aren't NULL
				if (Cubes[x][y][z]) {
					// only render cubes that are on the very edges of the chunk.
					if (x == 0 || x == size.x - 1 || y == 0 || y == size.y - 1
							|| z == 0 || z == size.z - 1) {
						Cubes[x][y][z]->Render(shader, camera);
					//	Update(camera);
					} else {
						//check all inside cubes
						//only render cubes if they'res an empty cube on any face
						if (!Cubes[x + 1][y][z] || !Cubes[x - 1][y][z]
								|| !Cubes[x][y + 1][z] || !Cubes[x][y - 1][z]
								|| !Cubes[x][y][z + 1] || !Cubes[x][y][z - 1]) {
							Cubes[x][y][z]->Render(shader, camera);
							//Update(camera);
						} else {

						}
					}
				}
			}
		}
	}

}

void Chunk::Update(Camera*  cam){
      for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			for (int z = 0; z < size.z; z++) {
			      Collision(cam , Cubes[x][y][z]);
			}
		}
	}
}
