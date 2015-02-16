#include "Cube.h"

Cube::Cube()
{

}

Cube::~Cube()
{

}

glm::vec3 Cube::getPosition()
{
    return position;
}

glm::vec3 Cube::setPosition(GLuint x , GLuint y , GLuint z)
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
