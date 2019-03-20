#pragma once
#include "BaseRenderable.h"

class TriangleRenderable : public BaseRenderable
{
	enum DIRTY
	{
		VTX = 1 << 0,
		CLR = 1 << 1
	};
public:
	TriangleRenderable(const std::string& name);
	~TriangleRenderable();

	bool render() override;

protected:

	void updateVtx();

private:
	GLuint m_VtxBufferId, m_IdxBufferId;

	GLuint m_vao;

};