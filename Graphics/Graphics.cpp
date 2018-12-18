#pragma once
#include "Graphics.h"

namespace Graphics
{
	OpenGLGraphics::OpenGLGraphics()
	{
	}

	OpenGLGraphics::~OpenGLGraphics()
	{
	}

	OpenGLGraphics * OpenGLGraphics::getInstance()
	{
		if (!m_GraphicsRenderer)
			m_GraphicsRenderer = new OpenGLGraphics();
		return m_GraphicsRenderer;
	}

	void OpenGLGraphics::initAllPrograms()
	{
		// SIMPLE
		std::vector<std::string> simpleSL(SHADER_TYPE::SIZE);
		simpleSL[VERT] = "SimpleVertex";
		simpleSL[FRAG] = "SimpleFragment";
		m_Programs.push_back(std::pair<std::string, GLuint>("Simple", m_InitProgram(simpleSL)));
	}

	GLuint OpenGLGraphics::m_InitProgram(std::vector<std::string>& shaderList)
	{
		GLuint programID = glCreateProgram();
		if (shaderList[VERT].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[VERT])->m_id);
		if (shaderList[FRAG].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[FRAG])->m_id);
		if (shaderList[TESE].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[TESE])->m_id);
		if (shaderList[TESC].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[TESC])->m_id);
		if (shaderList[COMP].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[COMP])->m_id);
		if (shaderList[GEOM].size() > 0)
			glAttachShader(programID, m_ShaderLibrary.getShader(shaderList[GEOM])->m_id);
		glLinkProgram(programID);
		return programID;
	}
}
