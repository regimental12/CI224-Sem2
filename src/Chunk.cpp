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
	size = glm::vec3(16, 10, 16);
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

/*Cube* Chunk::getCubes()
{
      //return Cubes;
}*/


void Chunk::Init(){
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {

			// get noise value - using x & z because Y is our up axis
			double value = perlin.noise(10 * ((position.x*size.x)+x), 10 * ((position.z*size.z)+z), 0.8);


			for (int y = 0; y < (int)(value * size.y); y++) {	// only create cubes up to our value
					Cubes[x][y][z] = new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z);
			}
		}
	}
}

void Chunk::Render(Shader shader, Camera* camera) {
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {

			// get noise value - using x & z because Y is our up axis
			double value = perlin.noise(10 * ((position.x*size.x)+x), 10 * ((position.z*size.z)+z), 0.8);

			for (int y = 0; y < (int)(value * size.y); y++) {
				// only attempt to render cubes that aren't NULL
				if (Cubes[x][y][z]) {
					// only render cubes that are on the very edges of the chunk.
					if (x == 0 || x == size.x - 1 || y == 0 || y == size.y - 1
							|| z == 0 || z == size.z - 1) {
						Cubes[x][y][z]->Render(shader, camera);
					} else {
						//check all inside cubes
						//only render cubes if they'res an empty cube on any face
						if (!Cubes[x + 1][y][z] || !Cubes[x - 1][y][z]
								|| !Cubes[x][y + 1][z] || !Cubes[x][y - 1][z]
								|| !Cubes[x][y][z + 1] || !Cubes[x][y][z - 1]) {

							Cubes[x][y][z]->Render(shader, camera);
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
		for (int z = 0; z < size.z; z++) {
			for (int y = 0; y < size.y; y++) {
				// only attempt to collide cubes that aren't NULL
				if (Cubes[x][y][z] != NULL) {
						Collision(cam, Cubes[x][y][z]);
				}
			}
		}
	}
}
