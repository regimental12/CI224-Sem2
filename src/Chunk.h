/*
 * Chunk.h
 *
 *  Created on: 21 Mar 2015
 *      Author: George
 */

#ifndef SRC_CHUNK_H_
#define SRC_CHUNK_H_

#include "Cube.h"
#include "Perlin.h"
#include <vector>
#include "Collision.h"

class Chunk {
public:
	Chunk();
	Chunk(GLfloat X, GLfloat Y, GLfloat Z, Perlin noise);
	~Chunk();
	void Update(Camera* camera);
	void Render(Shader shader, Camera* camera);
	void Init();
	//Cube* getCubes();
private:
	Cube* Cubes[16][24][16];
	glm::vec3 position;
	glm::vec3 size;
	Perlin perlin;
	int yHeight[16][16];
	int yLOW = 100;
};

#endif /* SRC_CHUNK_H_ */
