#version 450

in VS_OUT
{
 vec2 texCoord;
}fs_in;

layout (binding = 0) uniform sampler2D background;
layout (binding = 1) uniform sampler2D model;
out vec4 outColorfs;

void main()
{
	outColorfs = texture(model, fs_in.texCoord);
	outColorfs = vec4(mix(outColorfs.xyz, texture(background, fs_in.texCoord).xyz, 1-outColorfs.w), 1.0); 
}