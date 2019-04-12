#version 450

in VS_OUT
{
 vec2 texCoord;
}fs_in;

layout (binding = 0) uniform sampler2D bkgImage;

out vec4 color;

void main()
{
	color = texture(bkgImage, fs_in.texCoord);
}
