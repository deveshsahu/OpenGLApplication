#version 450

in VS_OUT
{
 vec2 texCoord;
}fs_in;

layout (binding = 0) uniform sampler2D bkgImage;
uniform bkgInfo {
	int type;
	vec4 color;
	vec4 color2;
};
layout (location = 0) out vec4 outColor;

void main()
{
	switch (type)
	{
	case 0:
	outColor = color;
	break;
	case 1:
	outColor = texture(bkgImage, fs_in.texCoord);
	break;
	case 2:
	outColor = mix(color, color2, fs_in.texCoord.y);
	break;
	default:
	outColor = vec4(0.4, 0.5, 0.5, 1.0);
	}
	
}
