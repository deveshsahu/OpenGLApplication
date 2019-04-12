#include "RenderTarget.h"

namespace Graphics
{
	RenderTarget::RenderTarget(int bufferFlags, int width, int height):
		m_BufferFlags(bufferFlags)
	{
	}

	bool RenderTarget::create()
	{
		glGenFramebuffers(1, &m_FrameBufferID);
		glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferID);

		if (m_BufferFlags | RTCOLOR)
		{
			glGenTextures(1, &m_ColorTextureID);
			glBindTexture(GL_TEXTURE_2D, m_ColorTextureID);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_ColorTextureID, 0);
			GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
			glDrawBuffers(1, DrawBuffers);
		}

		if (m_BufferFlags | RTDEPTH)
		{
			glGenRenderbuffers(1, &m_DepthBufferID);
			glBindRenderbuffer(GL_RENDERBUFFER, m_DepthBufferID);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, m_Width, m_Height);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_READ_BUFFER, m_DepthBufferID);
		}

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			return false;
	}
	void RenderTarget::bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_FrameBufferID);
		glViewport(0, 0, m_Width, m_Height);
	}
	void RenderTarget::bindDefault()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
}