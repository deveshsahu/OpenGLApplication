#pragma once
#include <string>
namespace tinygltf
{
	class Model;
}
namespace fl
{
	// Singleton class to support loading of gltf file
	class GLTFLoader
	{
	public:
		static GLTFLoader& getInstance();
		GLTFLoader(GLTFLoader const&) = delete;
		void operator=(GLTFLoader const&) = delete;

		bool loadFromFile(const std::string& filepath);

	private:
		GLTFLoader();
		tinygltf::Model * mtinygltfModel;
	};
}