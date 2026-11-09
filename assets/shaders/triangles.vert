#version 430 core
layout(location = 0) in vec3 vPosition;
layout(location = 1) in vec3 vColor;
layout(location = 2) in vec2 vTex;
layout(location = 3) in vec3 vIndx;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProject;

out vec3 Color;
out vec2 TexCoord;

void main()
{
	//gl_Position = vec4(vPosition, 1.0f);
	gl_Position = uProject * uView * uModel * vec4(vPosition, 1.0f);
	TexCoord = vTex;
	Color = vColor;
}