#include "Scene.h"
#include "GLUtils.h"
#include "TriangleRenderable.h"
#include "BackgroundRenderable.h"
#include <iostream>
namespace Graphics
{
	Scene::Scene(int width, int height):
		m_Width(width),
		m_Height(height)
	{
		//m_Renderables.push_back(std::make_shared<TriangleRenderable>("Triangle"));
		m_Renderables.push_back(std::make_shared<BackgroundRenderable>("Background"));
	}

	void Scene::init()
	{
		GLUtils::printInfo();
		for (auto& renderable : m_Renderables)
		{
			if (!renderable->init())
			{
				std::cerr << "ERROR: Failed to initialize renderables!" << std::endl;
				mInitFailed = true;
			}
		}
	}

	void Scene::render()
	{
		if (mInitFailed)
			return;
		m_BeginFrame();
		m_Draw();
		m_EndFrame();
	}

	void Scene::resize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
	}

	void Scene::dispose()
	{
		
	}

	void Scene::addRenderable(std::shared_ptr<BaseRenderable>& renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Scene::m_BeginFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Scene::m_Draw()
	{
		for (auto& renderable : m_Renderables)
		{
			renderable->drawBegin();
			renderable->draw();
			renderable->drawEnd();
		}
	}

	void Scene::m_EndFrame()
	{
	}

}