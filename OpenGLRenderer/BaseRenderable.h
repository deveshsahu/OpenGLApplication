#pragma once

#include "opengl.h"
#include <string>

class BaseRenderable
{
public:
	BaseRenderable(const std::string& name) : m_Name(name) {}
	virtual ~BaseRenderable() {}
	
	virtual bool render() = 0;
	std::string getName() { return m_Name; }

	void unsetDirty(int flag) { m_DirtyFlag &= ~flag; }
	void setDirty(int flag) { m_DirtyFlag |= flag; }
	bool isDirty(int flag) { return m_DirtyFlag & flag; }

protected:
	std::string m_Name;
	size_t m_DirtyFlag = 0;
};