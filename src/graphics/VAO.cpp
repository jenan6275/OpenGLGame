#pragma	once
#include "graphics/VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset)
{
	Bind();
	vbo.Bind();
	//copy the vertices data to opengl buffer
	glVertexAttribPointer(layout, numComponents, type , GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	//vbo.Unbind();
	Unbind();
}

void VAO::LinkAttrib(EBO ebo, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset)
{
	Bind();
	ebo.Bind();
	//copy the vertices data to opengl buffer
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
//	ebo.Unbind();
	Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}