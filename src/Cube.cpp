#include "Cube.h"

Cube::Cube()
{
	//iLoader = new ImageLoader();
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	loadCube();
}


Cube::Cube(GLfloat x, GLfloat y, GLfloat z)
{
	//iLoader = new ImageLoader();
	position = glm::vec3(x, y, z);
	loadCube();
}

Cube::~Cube()
{
	delete(iLoader);
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
{/*
    // Fill out when image loader done
   texture = iLoader->LoadTexture(fileName);

    //texture = iLoader->LoadTexture(fileName.c_str());
    //delete iLoader;
    */
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
    setType(0);
}

void Cube::Render(Shader shader , Camera* camera)
{
    shader.useShader();

    GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
    GLint viewLoc = glGetUniformLocation(shader.getProgram(), "view");
    GLint projLoc = glGetUniformLocation(shader.getProgram(), "projection");
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));

    glBindVertexArray(VAO);
		  glBindTexture(GL_TEXTURE_2D, ImageLoader::getInstance()->GetTexture(this->getType()));
		  glm::mat4 model;
		  model = glm::translate(model, position);
		  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		  glDrawArrays(GL_TRIANGLES, 0, 36);
		  glBindTexture(GL_TEXTURE_2D , 0);
    glBindVertexArray(0);
    glUseProgram(0);
}

void Cube::setType(GLuint cubeType) {
	switch (cubeType) {
	  case 0:
		type = 0;
		break;

	  case 1:
		type = 1;
		break;

	  case 2:
		type = 2;
		break;

	default:
		type = 2;
		break;
	}
}

GLuint Cube::getType()
{
    return type;
}

