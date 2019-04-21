#pragma once
#include "RenderTarget.h"
#include "GLSLProgram.h"
#include "ViewMatrix.h"
#include "Camera.h"
#include <vector>
#include <memory>

namespace Graphics
{
	class BaseRenderable;
	class BackgroundRenderable;
	class Scene
	{
	public:
		Scene(int width, int height);
		
		void init();
		void render();
		void resize(int width, int height);
		void dispose();

		void addRenderable(std::shared_ptr<BaseRenderable> renderable);
		void addBackground(const std::string filepath);

	protected:

		void mBeginFrame();
		void mDraw();
		void mEndFrame();

	protected:
		int mWidth = 0, mHeight = 0;
		std::vector<std::shared_ptr<BaseRenderable>> mRenderables;
		std::shared_ptr<BackgroundRenderable> mBackgroundRenderable;

		RenderTarget mModelRenderTarget;
		RenderTarget mBackgroundRenderTarget;

		Camera mCamera;
		ViewMatrix mViewMatrix;

		GLSLProgram mCompositingProgram;
		GLuint mCompositingVao;

		GLuint mViewMatrixBuffer;

		bool mInitFailed = false;
	};
}