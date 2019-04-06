#version 450

layout (location = 0) in vec2 inVert;

void main()
{
	gl_Position = vec4(inVert, 0, 1.0);
}