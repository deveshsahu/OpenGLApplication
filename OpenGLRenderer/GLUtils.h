#pragma once
#include "opengl.h"

namespace GLUtils
{
	enum SHADER_TYPE
	{
		VERT,	// Vertex Shader
		FRAG,	// Fragment Shader
		TESC,	// Tessellation Compute Shader
		TESE,	// Tessallation Evaluation Shader
		COMP,	// Compute Shader
		GEOM,	// Geometry Shader
		NUM
	};

	GLenum getShaderEnum(SHADER_TYPE type);
	void APIENTRY debugCallback(GLenum source, GLenum type, GLuint id,
		GLenum severity, GLsizei length, const GLchar * msg, const void * param);
	int checkForOpenGLError(const char * file, int line);
}