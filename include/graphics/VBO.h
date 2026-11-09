#pragma once
#include <glad/glad.h>
//#include <GL/glew.h>

class VBO
{
	GLuint ID;
public:
	VBO(GLfloat* vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
};
