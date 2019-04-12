#include "BackgroundRenderable.h"
#include "../Resources/utils.h"
#include <glm/glm.hpp>
#include <vector>

namespace Graphics
{
	BackgroundRenderable::BackgroundRenderable(const std::string& name):
		BaseRenderable(name)
	{
		setDirty(VTX | TEX);
	}

	bool BackgroundRenderable::init()
	{
		mProgram.addShader("BackgroundVertex");
		mProgram.addShader("BackgroundFragment");
		if (!mProgram.createProgram())
			return false;
		m_updateVtx();
		m_updateTex();
		
		return true;
	}

	void BackgroundRenderable::drawBegin()
	{
		mProgram.useProgram();
		glActiveTexture(GL_TEXTURE0);
	}

	void BackgroundRenderable::draw()
	{
		glBindVertexArray(m_vao);
		glBindTexture(GL_TEXTURE_2D, m_tex);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		glBindVertexArray(0);
	}

	void BackgroundRenderable::drawEnd()
	{
	}

	void BackgroundRenderable::m_updateVtx()
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		std::vector<glm::vec2> data = {
			glm::vec2(-1, -1),
			glm::vec2(-1, 1),
			glm::vec2(1, -1),
			glm::vec2(1, 1)
		};
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
		unsetDirty(VTX);
	}

	void BackgroundRenderable::m_updateTex()
	{

		int width = 512, height = 512;
		auto data = utils::loadImageFile(m_ImagePath, width, height);
		if (data)
		{
			glActiveTexture(GL_TEXTURE0);
			glGenTextures(1, &m_tex);
			glBindTexture(GL_TEXTURE_2D, m_tex);
			glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			free(data);
		}
		unsetDirty(TEX);
	}
}