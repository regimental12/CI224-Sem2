#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

#include "Chunk.h"
#include <vector>

class World
{
public:
	World();
	~World();
	void Update();
	void Render(Shader shader, Camera* camera);
private:
	  std::vector<Chunk*> Chunks;
};

#endif /* SRC_WORLD_H_ */
