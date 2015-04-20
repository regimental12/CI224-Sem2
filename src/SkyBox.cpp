/*
 * SkyBox.cpp
 *
 *  Created on: 15 Apr 2015
 *      Author: George
 */

#include "SkyBox.h"

SkyBox::SkyBox()
	:position(glm::vec3(0,0,0)),
	 texture(0),
	 VBO(0),
	 VAO(0),
	 iLoader(new ImageLoader())
{
	loadSkyBox();
}

SkyBox::~SkyBox()
{
	delete(iLoader);
}


void SkyBox::loadSkyBox()
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
    setTexture("images/container.jpg");
}

void SkyBox::Render(Shader shader , Camera* camera)
{
    shader.useShader();

    GLint modelLoc = glGetUniformLocation(shader.getProgram(), "model");
    GLint viewLoc = glGetUniformLocation(shader.getProgram(), "view");
    GLint projLoc = glGetUniformLocation(shader.getProgram(), "projection");


    /*glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));*/

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));

    glBindVertexArray(VAO);
		  glBindTexture(GL_TEXTURE_2D, texture);
		  glm::mat4 model;
		  model = glm::translate(model, position);

		  //model = glm::rotate(model, angle, glm::vec3(1.0f, 1.0f, 1.0f));

		  //model = glm::rotate(model, angle, glm::vec3(1.0f, 1.0f, 0.5f));

		  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		  glDrawArrays(GL_TRIANGLES, 0, 36);
		  glBindTexture(GL_TEXTURE_2D , 0);
    glBindVertexArray(0);
    glUseProgram(0);
}
