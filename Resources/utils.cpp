#pragma once
#include "utils.h"
#include <fstream>

namespace utils
{
	std::vector<char> loadFile(const std::string& fileName)
	{
		std::ifstream fs(fileName, std::ios::ate | std::ios::binary);
		if (!fs.is_open())
			return std::vector<char>();
		// Let NRVO-copy ellison happen if supported by compiler
		// instead of forcing std::move()
		size_t fileSize = fs.tellg();
		std::vector<char> content(fileSize);
		fs.seekg(0);
		fs.read(content.data(), fileSize);
		fs.close();
		content.push_back('\0'); // Null terminate the string
		return content;
	}
}