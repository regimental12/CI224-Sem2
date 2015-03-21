#include "Chunk.h"

Chunk::Chunk(){
	position.x = 0;
	position.y = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			for (int z = 0; z < 1; z++) {
				Cubes.push_back(new Cube(x, y, z));
			}
		}
	}
}

Chunk::Chunk(GLfloat X, GLfloat Y){
	position.x = X;
	position.y = Y;

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				Cubes.push_back(new Cube(x, y, z));
			}
		}
	}
}

Chunk::~Chunk(){

}

void Chunk::Render(Shader shader, Camera* camera){
	for (int z = 0; z < Cubes.size(); z++) {
		Cubes[z]->Render(shader, camera);
	}
}

void Chunk::Update(){

}
