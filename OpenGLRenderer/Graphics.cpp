#pragma once
#include "Graphics.h"

namespace Graphics
{
	OpenGLGraphics::OpenGLGraphics():
		m_Triangle("triangle")
	{
	}

	OpenGLGraphics::~OpenGLGraphics()
	{
	}

	OpenGLGraphics& OpenGLGraphics::getInstance()
	{
		static OpenGLGraphics instance;
		return instance;
	}

	void OpenGLGraphics::initAllPrograms()
	{
		m_ShaderLibrary.initializeDefaultShaders();
		// SIMPLE
		std::vector<std::string> simpleSL(SHADER_TYPE::NUM);
		simpleSL[VERT] = "SimpleVertex";
		simpleSL[FRAG] = "SimpleFragment";
		m_Programs["Simple"] = m_InitProgram(simpleSL);
	}

	void OpenGLGraphics::init()
	{
		initAllPrograms();
		glViewport(0, 0, 512, 512);
	}

	void OpenGLGraphics::render()
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glUseProgram(m_Programs["Simple"]);
		m_Triangle.render();
	}

	void OpenGLGraphics::resize(int width, int height)
	{
		glViewport(0, 0, width, height);
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
