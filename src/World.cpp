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
	for (int x =-1; x < 1; x++) {
		for (int z = -1 ; z < 1; z++) {
			Chunks.push_back(new Chunk(x, 0, z, perlin));
		}
	}


}

World::~World()
{
	//de-allocate pointers inside vector then clear the vector
	for (int i = 0; i < Chunks.size(); i++) {
		delete(Chunks[i]);
	}
	Chunks.clear();
}

/**
 * Render should call each of the 9 loaded chunks own render method
 */
void World::Render(Shader shader, Camera* camera)
{
	for(int i = 0; i < Chunks.size(); i++) {
		Chunks[i]->Render(shader, camera);
	}
}

/**
 * Update will find the chunk the player is in and check that all 8 surrounding chunks are loaded.
 * If they arne't it will load them. If they are it will do nothing.
 */
void World::Update(Camera* camera)
{
	for(int i = 0; i < Chunks.size(); i++) {
		Chunks[i]->Update(camera);
	}
}
