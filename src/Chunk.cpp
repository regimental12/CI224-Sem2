#include "Chunk.h"

Chunk::Chunk(){
	size = glm::vec3(4, 2, 4);
	position.x = 0;
	position.y = 0;

	Init();
}

Chunk::Chunk(GLfloat X, GLfloat Y, GLfloat Z){
	size = glm::vec3(4, 2, 4);
	position.x = X;
	position.y = Y;
	position.z = Z;

	Init();
}

Chunk::~Chunk(){

}

void Chunk::Init(){
	for (int x = 0; x < size.x; x++) {
		for (int y = 0; y < size.y; y++) {
			for (int z = 0; z < size.z; z++) {
				Cubes.push_back(new Cube((position.x*size.x)+x, (position.y*size.y)+y, (position.z*size.z)+z));
			}
		}
	}
}

void Chunk::Render(Shader shader, Camera* camera){
	for (int z = 0; z < Cubes.size(); z++) {
		Cubes[z]->Render(shader, camera);
	}
}

void Chunk::Update(){

}
