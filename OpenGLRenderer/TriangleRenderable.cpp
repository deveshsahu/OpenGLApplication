#include "TriangleRenderable.h"
#include "glm/glm.hpp"
#include <vector>

namespace Graphics
{
	TriangleRenderable::TriangleRenderable(const std::string& name) :
		BaseRenderable(name)
	{
	}

	TriangleRenderable::~TriangleRenderable()
	{
	}

	bool TriangleRenderable::init()
	{
		mProgram.addShader("SimpleVertex");
		mProgram.addShader("SimpleFragment");
		if (!mProgram.createProgram())
			return false;
		updateVtx();
		return true;
	}

	void TriangleRenderable::drawBegin()
	{
		mProgram.useProgram();
		glBindVertexArray(m_vao);
	}

	void TriangleRenderable::draw()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void TriangleRenderable::drawEnd()
	{
		glBindVertexArray(0);
	}

	void TriangleRenderable::updateVtx()
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		glGenBuffers(1, &m_VtxBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, m_VtxBufferId);
		std::vector<glm::vec3> vtx = {
			glm::vec3(-0.5, 0, 0), glm::vec3(0.5, 0, 0), glm::vec3(0, 0.5, 0)
		};
		glBufferData(GL_ARRAY_BUFFER, vtx.size() * sizeof(glm::vec3), vtx.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
		unsetDirty(VTX);
	}
}//namespace Graphics