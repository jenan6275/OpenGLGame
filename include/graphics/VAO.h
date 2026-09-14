#pragma once
//#include <glad/glad.h>
#include <GL/glew.h>

#include "VBO.h"
#include "EBO.h"

class VAO
{
	GLuint ID;
public:
	VAO();
	void LinkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset);
	void LinkAttrib(EBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};

