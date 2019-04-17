#include "Scene.h"
#include "GLUtils.h"
#include "TriangleRenderable.h"
#include "BackgroundRenderable.h"
#include <iostream>
namespace Graphics
{
	Scene::Scene(int width, int height) :
		mWidth(width),
		mHeight(height),
		mModelRenderTarget(rtTargetFlag::RT_BOTH, width, height, 1),
		mBackgroundRenderTarget(rtTargetFlag::RT_BOTH, width, height, 0)
	{
	}

	void Scene::init()
	{
		GLUtils::printInfo();
		if (!mModelRenderTarget.create())
		{
			mInitFailed = true;
			return;
		}

		for (auto& renderable : mRenderables)
		{
			if (!renderable->init())
			{
				std::cerr << "ERROR: Failed to initialize renderables!" << std::endl;
				mInitFailed = true;
				return;
			}
		}

		if (mBackgroundRenderTarget.create())
		{
			if (!mBackgroundRenderable->init())
			{
				std::cerr << "ERROR: Failed to initialize background!" << std::endl;
				mInitFailed = true;
			}
		}

		// Initialize compositing program
		mCompositingProgram.addShader("ResolveVertex");
		mCompositingProgram.addShader("ResolveFragment");
		if (!mCompositingProgram.createProgram())
		{
			std::cerr << "ERROR: Failed to create Compositing program!" << std::endl;
		}
		glGenVertexArrays(1, &mCompositingVao);
	}

	void Scene::render()
	{
		if (mInitFailed)
			return;
		mBeginFrame();
		mDraw();
		mEndFrame();
	}

	void Scene::resize(int width, int height)
	{
		mWidth = width;
		mHeight = height;
	}

	void Scene::dispose()
	{
		
	}

	void Scene::addRenderable(std::shared_ptr<BaseRenderable> renderable)
	{
		mRenderables.push_back(renderable);
	}

	void Scene::addBackground(const std::string filepath)
	{
		mBackgroundRenderable = std::make_shared<BackgroundRenderable>("Background");
	}

	void Scene::mBeginFrame()
	{
	}

	void Scene::mDraw()
	{
		mModelRenderTarget.bind();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		for (auto& renderable : mRenderables)
		{
			renderable->drawBegin();
			renderable->draw();
			renderable->drawEnd();
		}
	}

	void Scene::mEndFrame()
	{
		mBackgroundRenderTarget.bind();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mBackgroundRenderable->drawBegin();
		mBackgroundRenderable->draw();
		mBackgroundRenderable->drawEnd();
		GLUtils::checkForOpenGLError(__FILE__, __LINE__);

		glBindFramebuffer(GL_FRAMEBUFFER, 0); // Switch to default frame buffer
		glViewport(0, 0, mWidth, mHeight);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mCompositingProgram.useProgram();
		glActiveTexture(GL_TEXTURE1);
		mModelRenderTarget.bindColorTexture();
		glActiveTexture(GL_TEXTURE0);
		mBackgroundRenderTarget.bindColorTexture();
		glBindVertexArray(mCompositingVao);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

}