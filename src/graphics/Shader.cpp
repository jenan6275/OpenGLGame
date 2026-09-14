#pragma once
#include "graphics/Shader.h"
// Read the file content and return the content string
std::string get_file_contents(const char* fileName) 
{
	std::ifstream in(fileName, std::ios::binary);
	if (in) 
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw(errno);
}

Shader::Shader(const char* shaderFile, const char* fragmentFile)
{
	int success;
	char infoLog[512];
	std::string shaderVertexStr = get_file_contents(shaderFile);
	std::string shaderFragmentStr = get_file_contents(fragmentFile);

	const char* vertexShaderSource = shaderVertexStr.c_str();
	const char* fragmentShaderSource = shaderFragmentStr.c_str();


	// Vertex shader compilation
	GLuint shaderVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shaderVertex, 1, &vertexShaderSource, NULL);
	glCompileShader(shaderVertex);

	glGetShaderiv(shaderVertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// Fragment shader compilation
	GLuint shaderFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shaderFragment, 1, &fragmentShaderSource, NULL);
	glCompileShader(shaderFragment);

	glGetShaderiv(shaderFragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMANT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};

	// Shader program linking 
	ID = glCreateProgram();
	glAttachShader(ID, shaderVertex);
	glAttachShader(ID, shaderFragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "LINK::ERROR::SHADER::VERTEX::LINKER_FAILED\n" << infoLog << std::endl;
	};

	glDeleteShader(shaderVertex);
	glDeleteShader(shaderFragment);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}

void Shader::setFloat(std::string str, float value)
{
	int loc = glGetUniformLocation(ID, str.c_str());
	glUniform4f(loc, 0.0f, value, 0.0f, 1.0f);
	//glUniform4f(loc, value);
}