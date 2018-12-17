#include "utils.h"

#include <fstream>

std::vector<char> loadFile(const std::string & fileName)
{
	std::fstream fs(fileName.c_str(), std::ios::ate | std::ios::binary);
	if (!fs.is_open())
		return std::vector<char>();
	// Let NRVO-copy ellison happen if compiler supported
	// instead of forcing std::move()
	size_t fileSize = fs.tellg();
	std::vector<char> content(fileSize);
	fs.seekg(0);
	fs.read(content.data(), fileSize);
	fs.close();
	return content;
}
