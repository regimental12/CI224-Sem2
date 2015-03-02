#include "Cube.h"

Cube::Cube()
{
	std::cout  << "enter cube consructor" << std::endl;
	iLoader = new ImageLoader();
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	loadCube();
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
    std::cout  << "enter cube settexure" << std::endl;
    // Fill out when image loader done.
   /* texture = iLoader->LoadTexture(fileName);
    delete iLoader;*/
}

GLuint Cube::getVAO()
{
    return VAO;
}

GLuint Cube::getVBO()
{
    return VBO;
}



void Cube::loadCube()
{
    std::cout  << "enter cube loadcube" << std::endl;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    std::cout  << "1" << std::endl;
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    std::cout  << "2" << std::endl;
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    std::cout  << "3" << std::endl;
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    std::cout  << "4" << std::endl;
    glBindVertexArray(0);
    setTexture("images/wall.jpg");
}
