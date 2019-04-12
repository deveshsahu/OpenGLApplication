#pragma once

#include "glm/glm.hpp"
#include <vector>
#include <memory>

namespace Graphics
{
	class BaseRenderable;
	class Scene;
	class OpenGLGraphics
	{
	public:
		~OpenGLGraphics();
		OpenGLGraphics(OpenGLGraphics const&) = delete;
		void operator=(OpenGLGraphics const&) = delete;

		static OpenGLGraphics& getInstance();

		/*std::shared_ptr<Scene>*/void createNewScene(int width, int height);

		std::shared_ptr<Scene> getScene() { return m_Scene; }

	private:
		OpenGLGraphics();

		std::shared_ptr<Scene> m_Scene;
	};
}