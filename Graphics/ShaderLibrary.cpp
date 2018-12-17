#include "ShaderLibrary.h"

#include "../Resources/utils.h"
#include <iostream>

ShaderLibrary::ShaderLibrary()
{


}

void ShaderLibrary::addShaderFromFile(const std::string& name, const std::string & filePath, SHADER_TYPE type)
{
	if (type >= SHADER_TYPE::SIZE)
	{
		std::cerr << "ERROR: Incorrect shader type\n";
		return;
	}
	auto sourceCode = loadFile(filePath);
	if (sourceCode.empty())
	{
		std::cerr << "ERROR: Could not find shader file \"" << filePath << "\"" << std::endl;
		return;
	}
	auto id = glCreateShader(type);
	if (id == 0)
	{
		std::cerr << "ERROR: glCreateShader returned 0\n";
		return;
	}
	GLchar* shaderSource[] = { sourceCode.data() };
	glShaderSource(id, 1, shaderSource, NULL);
	glCompileShader(id);
	GLint result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		std::cerr << "ERROR: Shader compilation failed\n";
		GLint logLen;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLen);
		if (logLen > 0)
		{
			char* log = new char[logLen];
			GLsizei written;
			glGetShaderInfoLog(id, logLen, &written, log);
			std::cout << "INFO: " << log << std::endl;
			delete[] log;
		}
		return;
	}
	m_ShaderList.emplace_back(id, type, name);
}
