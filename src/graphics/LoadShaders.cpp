#include <core/LoadShaders.h>


using namespace std;

GLint LoadShaders(ShaderInfo* si)
{
	int i = 0;
	int success;
	const char* vtxSrc;
	const char* fragSrc;
	char* infoLog=NULL;
	string vtxSource;
	string fragSource;


	// Read the array of shader and load it in memory
	while (si[i].type != GL_NONE)
	{
		if (si[i].type == GL_VERTEX_SHADER)
		{
			vtxSource = ReadFile(si[i].shaderName);
		}
		else if (si[i].type == GL_FRAGMENT_SHADER)
		{
			fragSource = ReadFile(si[i].shaderName);
		}
		++i;
	}

	vtxSrc = vtxSource.c_str();
	fragSrc = fragSource.c_str();

	GLuint shaderVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shaderVertex, 1, &vtxSrc, NULL);
	glCompileShader(shaderVertex);

	glGetShaderiv(shaderVertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	
	GLuint shaderFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shaderFragment, 1, &fragSrc, NULL);
	glCompileShader(shaderFragment);
	
	glGetShaderiv(shaderFragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMANT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	
	GLuint shaderProg = glCreateProgram();
	glAttachShader(shaderProg, shaderVertex);
	glAttachShader(shaderProg,shaderFragment);
	glLinkProgram(shaderProg);
	
	glGetProgramiv(shaderProg, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderVertex, 512, NULL, infoLog);
		std::cout << "LINK::ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
	
	glDeleteShader(shaderVertex);
	glDeleteShader(shaderFragment);

	return shaderProg;

}

//Read the file contents

std::string ReadFile(const char* fileName)
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
