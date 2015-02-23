#version 330 core
in vec2 TexCoord;
in vec2 TexCoord2;

out vec4 color;
out vec4 color2;

uniform sampler2D ourTexture1;


void main()
{
    color = texture2D(ourTexture1 , TexCoord.st);
   
}