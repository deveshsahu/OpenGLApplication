#pragma once
#include "Model.h"

#include <memory>
namespace Graphics
{
	class Scene;
}

namespace model
{
	class GLTFModel : public Model
	{
	public:
		bool load(const std::string& filepath) override;
		bool configureScene();
	private:
		std::shared_ptr<Graphics::Scene> mModelScene;
	};
}