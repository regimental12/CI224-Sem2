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
	Chunk(GLfloat X, GLfloat Y, GLfloat Z);
	~Chunk();
	void Update();
	void Render(Shader shader, Camera* camera);
	void Init();
private:
//	  std::vector<Cube*> Cubes;
	Cube* Cubes[16][24][16];
	  glm::vec3 position;
	  glm::vec3 size;
};

#endif /* SRC_CHUNK_H_ */