#version 450

layout (location = 0) in vec2 inVert;

out VS_OUT
{
 vec2 texCoord;
}vs_out;

void main()
{
	gl_Position = vec4(inVert, 0, 1.0);
	vs_out.texCoord = vec2((inVert.x + 1.0) * 0.5, (inVert.y + 1) * 0.5) ;
}