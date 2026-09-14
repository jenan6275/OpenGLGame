#version 430 core
in vec3 Color;
out vec4 fColor;
/* fColor = Color;*/
uniform vec4 ourClr;
void
main()
{
//fColor = vec4(1.0, 1.0, 0.0, 1.0);
fColor = vec4(Color, 1.0f);
//  fColor = ourClr;
}