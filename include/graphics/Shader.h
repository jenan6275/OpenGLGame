#pragma once
//#include<glad/glad.h>
#include <GL/glew.h>
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>
#include<cerrno>


std::string get_file_contents(const char* fileName);

class Shader
{
	GLuint ID;
public:
	Shader(const char* shaderFile, const char* fragmentFile);
	void setFloat(std::string str, float i);
	void Activate();
	void Delete();
};