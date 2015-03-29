#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

#include "Chunk.h"
#include "Perlin.h"
#include <vector>

class World
{
public:
	World();
	~World();
	void Update(Camera* camera);
	void Render(Shader shader, Camera* camera);
private:
	  std::vector<Chunk*> Chunks;
	  Perlin perlin;
};

#endif /* SRC_WORLD_H_ */
