#pragma once

#include<glad/glad.h>

class Texture_Cls
{
public:
	GLenum tex= GL_TEXTURE0;
		
public:
	GLuint ID;
	Texture_Cls(const char* fileName, GLenum t);
	void Bind();
	void UnBind();
	void Delete();
};