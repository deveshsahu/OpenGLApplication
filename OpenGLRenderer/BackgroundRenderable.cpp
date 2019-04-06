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

	void BackgroundRenderable::draw()
	{
		if (isDirty(VTX))
			m_updateVtx();
		if (isDirty(TEX))
			m_updateTex();

		glBindVertexArray(m_vao);
		glBindTexture(GL_TEXTURE_2D, m_tex);
		glDrawArrays(GL_TRIANGLES, 0, 4);
		glBindVertexArray(0);
	}

	void BackgroundRenderable::m_updateVtx()
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		glGenBuffers(1, &m_vbo);
		glBindVertexArray(m_vbo);

		std::vector<glm::vec2> data = {
			glm::vec2(-1, -1),
			glm::vec2(-1, 1),
			glm::vec2(1, -1),
			glm::vec2(1, 1)
		};
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		unsetDirty(VTX);
	}

	void BackgroundRenderable::m_updateTex()
	{
		glGenTextures(1, &m_tex);
		glBindTexture(GL_TEXTURE_2D, m_tex);

		int width, height;
		auto data = utils::loadImageFile(m_ImagePath, width, height);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			free(data);
		}
		unsetDirty(TEX);
	}
}