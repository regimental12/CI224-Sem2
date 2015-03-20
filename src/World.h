#ifndef SRC_WORLD_H_
#define SRC_WORLD_H_

#include "Cube.h"
#include <vector>

class World
{
public:
	World();
	~World();
	void Update();
	void Render(Shader shader, Camera* camera);
private:
	  std::vector<Cube*> Cubes;
};

#endif /* SRC_WORLD_H_ */
