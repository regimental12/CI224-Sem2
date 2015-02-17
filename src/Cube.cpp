#include "Cube.h"

Cube::Cube()
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}

Cube::~Cube()
{

}

glm::vec3 Cube::getPosition()
{
    return position;
}

void Cube::setPosition(GLfloat x , GLfloat y , GLfloat z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

GLuint Cube::getTexture()
{
    return texture;
}

void Cube::setTexture(std::string fileName)
{
    // Fill out when image loader done.
    ImageLoader *iLoader = new ImageLoader();
    texture = iLoader->LoadTexture("images/image1.jpg");
    delete iLoader;
}
