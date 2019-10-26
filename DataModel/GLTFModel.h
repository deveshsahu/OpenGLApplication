#pragma once
#include "Model.h"
#include <memory>

namespace model
{
	class GLTFModel : public Model
	{
	public:
		bool load(const std::string& filepath) override;

	private:
		std::shared_ptr<sg::Node> mModelSceneGraphRoot;
	};
}