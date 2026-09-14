#pragma once
//#include <glad/glad.h>
#include <GL/glew.h>

class EBO
{
	GLuint ID;
public:
	EBO(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
};
