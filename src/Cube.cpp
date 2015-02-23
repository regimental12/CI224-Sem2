#include "Cube.h"

Cube::Cube()
{
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
    // Fill out when image loader done.
    ImageLoader *iLoader = new ImageLoader();
    texture = iLoader->LoadTexture("images/image1.jpg");
    delete iLoader;
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
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}
