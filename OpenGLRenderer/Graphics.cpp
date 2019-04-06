#pragma once
#include "Graphics.h"
#include "Scene.h"

namespace Graphics
{
	OpenGLGraphics::OpenGLGraphics()
	{
	}

	OpenGLGraphics::~OpenGLGraphics()
	{
	}

	OpenGLGraphics& OpenGLGraphics::getInstance()
	{
		static OpenGLGraphics instance;
		return instance;
	}

	/*std::shared_ptr<Scene>*/void OpenGLGraphics::createNewScene(int width, int height)
	{
		m_Scene = std::make_shared<Scene>(width, height);
	}
}
