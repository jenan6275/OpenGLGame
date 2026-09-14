#pragma once
#include<glad/glad.h>

class Texture_Cls
{
public:
	GLuint ID;
	Texture_Cls(const char* fileName);
	void Bind();
	void UnBind();
	void Delete();
};