#include <iostream>
#include <core/Texture.h>
#define STB_IMAGE_IMPLEMENTATION

#include <core/stb_image.h>

using namespace  std;

Texture_Cls::Texture_Cls(const char* fileName, GLenum t)
{
	//read the tecture file using stb_image.h header file
	int widthImg, heightImg, numColCha;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(fileName, &widthImg, &heightImg, &numColCha, 0);
	if (t == GL_TEXTURE0)
		tex = GL_TEXTURE0;
	else if (t == GL_TEXTURE1)
		tex = GL_TEXTURE1;
	else
		tex = GL_TEXTURE0;

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	try {
		if (t == GL_TEXTURE0)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
		else if (t == GL_TEXTURE1)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widthImg, heightImg, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	}
	catch (exception e)
	{
		cout << "exception" << e.what();
	}
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture_Cls::Bind()
{
	glActiveTexture(tex);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture_Cls::UnBind()
{
	glActiveTexture(tex);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture_Cls::Delete()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glDeleteTextures(1, &ID);
}