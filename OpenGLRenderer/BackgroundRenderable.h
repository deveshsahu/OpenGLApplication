#pragma once
#include "BaseRenderable.h"
#include "GLSLProgram.h"
namespace Graphics
{

	class BackgroundRenderable : public BaseRenderable
	{
		enum DIRTY
		{
			VTX = 1 << 0,
			TEX = 1 << 1
		};
	public:
		BackgroundRenderable(const std::string & name);
		bool init() override;
		void drawBegin() override;
		void draw() override;
		void drawEnd() override;
	private:
		void m_updateVtx();
		void m_updateTex();

	private:
		std::string m_ImagePath="D:\\FirefoxDownloads\\image.jpg";
		GLuint m_vao;
		GLuint m_vbo;
		GLuint m_tex;

		GLSLProgram mProgram;
	};
}