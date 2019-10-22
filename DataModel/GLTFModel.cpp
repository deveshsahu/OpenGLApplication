#include "GLTFModel.h"
#include "GLTFLoader.h"

namespace model
{
	bool GLTFModel::load(const std::string& filepath)
	{
		return fl::GLTFLoader::getInstance().loadFromFile(filepath);
	}
}