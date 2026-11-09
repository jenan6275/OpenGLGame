#pragma once
#include<glad/glad.h>
//#include <GL/glew.h>
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>
#include<cerrno>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


std::string get_file_contents(const char* fileName);

class Shader
{
	GLuint ID;
public:
	Shader(const char* shaderFile, const char* fragmentFile);
	void setFloat(std::string str, float i);
	void setInt(std::string str, int value);
	void setMat4(std::string str, glm::mat4 &mat);
	void setVec3(std::string str, float x, float y, float z);
	void Activate();
	void Delete();
};