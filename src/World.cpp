#include "World.h"
/**
 * On creation World needs to create 9 chunks i.e. chunk (0,0) and all 8 surrounding chunks.
 * E.G. - If X is (0,0)
 * +++
 * +X+
 * +++
 * So chunks created are:
 * ( 1,-1), ( 1,0), ( 1,1)
 * ( 0,-1), ( 0,0), ( 0,1)
 * (-1,-1), (-1,0), (-1,1)
 */
World::World()
{
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				Cubes.push_back(new Cube(x, y, z));
			}
		}
	}

}

World::~World()
{

}

/**
 * Render should call each of the 9 loaded chunks own render method
 */
void World::Render(Shader shader, Camera* camera)
{
	for (int z = 0; z < Cubes.size(); z++) {
		Cubes[z]->Render(shader, camera);
	}
}

/**
 * Update will fins the chunk the p;layer is in and check that all 8 surrounding chunks are loaded.
 * If they arne't it will load them. If they are it will do nothing.
 */
void World::Update()
{

}
