#pragma once
#include <vector>
#include <memory>

namespace Graphics
{
	class BaseRenderable;
	class Scene
	{
	public:
		Scene(int width, int height);
		
		void init();
		void render();
		void resize(int width, int height);
		void dispose();

		void addRenderable(std::shared_ptr<BaseRenderable>& renderable);

	protected:
		void m_BeginFrame();
		void m_Draw();
		void m_EndFrame();

	protected:
		int m_Width = 0, m_Height = 0;
		std::vector<std::shared_ptr<BaseRenderable>> m_Renderables;

		bool mInitFailed = false;
	};
}