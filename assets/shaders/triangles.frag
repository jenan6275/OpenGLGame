#version 430 core
in vec3 Color;
in vec2 TexCoord;

out vec4 fColor;


uniform vec4 ourClr;
uniform sampler2D tex0;
uniform sampler2D tex1;

void main()
{
  fColor = mix(texture(tex0, TexCoord), texture(tex1, TexCoord), 0.2);
  // fColor = texture(tex0, TexCoord);
  //fColor = vec4(Color, 1.0f);

}