#pragma once
#include "opengl.h"
#include <vector>
namespace Graphics
{
	enum RTBufferFlag
	{
		RTCOLOR,
		RTDEPTH,
	};

	class RenderTarget
	{
	public:
		RenderTarget(int bufferFlags, int width, int height);
		bool create();
		void bind();
		void bindDefault();
	private:
		GLuint m_FrameBufferID;
		GLuint m_ColorTextureID;
		GLuint m_DepthBufferID;

		int m_BufferFlags;

		int m_Width, m_Height;
	};
}