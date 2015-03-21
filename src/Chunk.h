/*
 * Chunk.h
 *
 *  Created on: 21 Mar 2015
 *      Author: George
 */

#ifndef SRC_CHUNK_H_
#define SRC_CHUNK_H_

#include "Cube.h"
#include <vector>

class Chunk {
public:
	Chunk();
	Chunk(GLfloat X, GLfloat Y);
	~Chunk();
	void Update();
	void Render(Shader shader, Camera* camera);
private:
	  std::vector<Cube*> Cubes;
	  glm::vec2 position;
};

#endif /* SRC_CHUNK_H_ */
