#version 450

layout (location = 0) in vec3 inVert;
layout (location = 1) in vec4 inColor;

layout (std140, binding = 0) uniform ViewMatrix
 {// Member						base alignment 			offset			aligned offset
	mat4 view;               //	16						0				0
	mat4 viewprojection;	 //	16						64				64
 };

void main()
{
	gl_Position = viewprojection * vec4(inVert, 1.0);
}