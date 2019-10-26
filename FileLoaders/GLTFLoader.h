#pragma once
#include <string>
#include <memory>
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
		void configureScenegraph();

	private:
		GLTFLoader();
		tinygltf::Model * mTinygltfModel = nullptr;
	};
}