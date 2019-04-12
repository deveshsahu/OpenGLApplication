#version 450

layout (location = 0) in vec3 inVert;
layout (location = 1) in vec4 inColor;

// layout (binding = 2) uniform matrix
// {
	// mat4 mvp;
	// mat4 mv;
// }m_matrix;

void main()
{
	gl_Position = vec4(inVert, 1.0);
}