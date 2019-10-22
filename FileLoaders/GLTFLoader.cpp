#include "GLTFLoader.h"
// Define these only in *one* .cc file.
#ifndef MY_TINY_GLTF_H
#define MY_TINY_GLTF_H
#ifndef TINYGLTF_IMPLEMENTATION
#define TINYGLTF_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#define TINYGLTF_NOEXCEPTION // optional. disable exception handling.
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef STBI_MSC_SECURE_CRT
#define STBI_MSC_SECURE_CRT
#endif
#include "tiny_gltf.h"
namespace fl
{
	GLTFLoader& GLTFLoader::getInstance()
	{
		static GLTFLoader instance;
		return instance;
	}
	bool GLTFLoader::loadFromFile(const std::string& filepath)
	{
		std::string err;
		std::string warn;
		tinygltf::TinyGLTF loader;
		mtinygltfModel = new tinygltf::Model();
		// Check file extension to check if it is binary or ascii
		if (!loader.LoadBinaryFromFile(mtinygltfModel, &err, &warn, filepath))
			//mLoader.LoadASCIIFromFile(&model, &err, &warn, filename)
		{
			if (!warn.empty()) {
				printf("Warn: %s\n", warn.c_str());
			}

			if (!err.empty()) {
				printf("Err: %s\n", err.c_str());
			}
			return false;
		}
		return true;
	}

	GLTFLoader::GLTFLoader()
	{
	}
}
#endif