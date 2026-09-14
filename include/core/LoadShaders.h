#pragma once
#include<sstream>
#include<iostream>
#include<fstream>
#include <GL/glew.h>

#define BUFFER_OFFSET(offset) ((void *)(offset))

struct ShaderInfo {
	GLint type;
	const char* shaderName;
};

GLint LoadShaders(ShaderInfo* si);
std::string ReadFile(const char* fileName);
