#pragma once
#include "Model.h"

namespace model
{
	class GLTFModel : public Model
	{
	public:
		bool load(const std::string& filepath) override;
	private:
	};
}