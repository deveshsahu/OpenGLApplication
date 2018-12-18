#pragma once

#include "ShaderLibrary.h"

namespace Graphics
{
	class OpenGLGraphics
	{
	public:
		OpenGLGraphics();
		~OpenGLGraphics();

		static OpenGLGraphics* getInstance();

		void initAllPrograms();

	private:
		GLuint m_InitProgram(std::vector<std::string>& shaderList);
		std::vector<std::pair<std::string, GLuint>> m_Programs;
		ShaderLibrary m_ShaderLibrary;

		static OpenGLGraphics* m_GraphicsRenderer;
	};
}