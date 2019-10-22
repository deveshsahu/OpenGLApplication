#pragma once

#include <string>
namespace model
{
	class Model
	{

	public:
		Model();
		virtual ~Model();

		virtual bool load(const std::string& filePath) = 0;
	};
}