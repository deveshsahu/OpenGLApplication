#pragma once
#include "BaseRenderable.h"
#include "GLSLProgram.h"

namespace Graphics
{
	class TriangleRenderable : public BaseRenderable
	{
	public:
		enum DIRTY
		{
			VTX = 1 << 0,
			CLR = 1 << 1
		};

	public:
		TriangleRenderable(const std::string& name);
		~TriangleRenderable();

		bool init() override;
		void drawBegin() override;
		void draw() override;
		void drawEnd() override;

	protected:
		void updateVtx();

	private:
		GLuint m_VtxBufferId, m_IdxBufferId;

		GLuint m_vao;

		GLSLProgram m_Program;
	};
}//namespace Graphics