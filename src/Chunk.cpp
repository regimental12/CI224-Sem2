
#include "Chunk.h"
#include "Inventory.h"

/**
 * Chunk constructor initialises values to zero.
 */
Chunk::Chunk()
	:position(glm::vec3(0, 0, 0)),
	 size(glm::vec3(16, 10, 16))
{
	Init();
}

/**
 * Overloaded Chunk constructor that sets the position and noise used to generate the chunk.
 *
 * @param X - x position of the chunk
 * @param Y - y position of the chunk
 * @param Z - z position of the chunk
 * @param noise - the PErlin noise being used to generate this chunk.
 *
 * @return NULL
 */
Chunk::Chunk(GLfloat X, GLfloat Y, GLfloat Z, Perlin noise){
	perlin = noise;
	size = glm::vec3(16, 48, 16);
	position.x = X;
	position.y = Y;
	position.z = Z;

	Init();
}

/**
 * Chunk destructor.
 */
Chunk::~Chunk(){
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {
			for (int y = 0; y < size.y; y++) {
				delete Cubes[x][y][z];
			}
		}
	}
}


/**
 * Chunk initialisation method. Sets up the chunks model from
 * the perlin noise passed into the constructor.
 *
 * @return NULL
 */
void Chunk::Init(){
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {

			// get noise value - using x & z because Y is our up axis
			double value = perlin.octave(((position.x*size.x)+x), ((position.z*size.z)+z), 0.8, 20, 0.8);

			//std::cout << (int)(perlin.noise(10 * ((position.x*size.x)+3), 10 * ((position.z*size.z)+9), 0.8) * size.y) << std::endl;

			yHeight[x][z] = (int)(value * size.y);

			if (yHeight[x][z] < yLOW) {
				yLOW = yHeight[x][z];
			}

			for (int y = 0; y < size.y; y++) {	// only create cubes up to our value
					Cubes[x][y][z] = new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z);

					int dirtbuffer = (rand() % 3) + 1;

					// between yheight and dirtbuffer away from yheight
					if (y >= yHeight[x][z] - dirtbuffer && y <= yHeight[x][z]) {
						//std::cout << "Cube Type " << Cubecount << std::endl;
						Cubes[x][y][z]->setType(1);
						//std::cout << "Cube Type set"  << std::endl;
					} else if (y < yHeight[x][z] - dirtbuffer) {
						Cubes[x][y][z]->setType(2);
					}
					else{
					  Cubes[x][y][z]->setType(0);
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


/**
 * Chunks render function.
 *
 * @param shader - The shader being used to render the cubes
 * 				   gets passed to the cubes when there render function is called.
 * @param camera - The camera that will see the rendered chunks.
 *
 * @return NULL
 */
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

						/**
						 * If one of 6 neighbours is air.
						 * This way if a face is visible the cube
						 * is rendered.
						 */
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


/**
 * Chunks update method.
 *
 * @param cam - the camera that will be used to test for collisions with cubes when it moves.
 *
 * @return NULL
 */
void Chunk::Update(Camera* cam) {
	for (int x = 0; x < size.x; x++) {
		for (int z = 0; z < size.z; z++) {
			for (int y = 0; y < size.y; y++) {
				// only attempt to collide cubes that aren't air
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
