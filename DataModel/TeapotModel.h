#pragma once
#include "Model.h"

namespace model
{
	class TeapotModel : public Model
	{
	public:
		TeapotModel();
		~TeapotModel();
		bool load(const std::string& filePath) override;

	};
}