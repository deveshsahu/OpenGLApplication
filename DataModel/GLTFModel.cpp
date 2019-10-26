#include "GLTFModel.h"
#include "GLTFLoader.h"
#include "SceneGraphNode.h"

namespace model
{
	bool GLTFModel::load(const std::string& filepath)
	{
		auto& loader = fl::GLTFLoader::getInstance();
		if (loader.loadFromFile(filepath))
		{
			return true;
		}
		return false;
	}
}