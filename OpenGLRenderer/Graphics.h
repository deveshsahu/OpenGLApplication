#pragma once

#include "ShaderLibrary.h"
#include "TriangleRenderable.h"
#include "glm/glm.hpp"
#include <unordered_map>

namespace Graphics
{
	class OpenGLGraphics
	{
	public:
		
		~OpenGLGraphics();
		OpenGLGraphics(OpenGLGraphics const&) = delete;
		void operator=(OpenGLGraphics const&) = delete;

		static OpenGLGraphics& getInstance();

		void initAllPrograms();
		void init();

		void render();

		void resize(int width, int height);

	private:
		OpenGLGraphics();

		GLuint m_InitProgram(std::vector<std::string>& shaderList);
		std::unordered_map<std::string, GLuint> m_Programs;
		ShaderLibrary m_ShaderLibrary;
		TriangleRenderable m_Triangle;
	};
}