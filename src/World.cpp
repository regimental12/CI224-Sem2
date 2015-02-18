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

}

World::~World()
{

}

/**
 * Render should call each of the 9 loaded chunks own render method
 */
void World::Render()
{

}

/**
 * Update will fins the chunk the p;layer is in and check that all 8 surrounding chunks are loaded.
 * If they arne't it will load them. If they are it will do nothing.
 */
void World::Update()
{

}
