#pragma once
#include "GLUtils.h"
#include <vector>
#include <string>
#include <memory>

using namespace GLUtils;
namespace Graphics
{

	struct Shader
	{
		SHADER_TYPE m_type;
		GLuint m_id;
		std::string m_name;
		Shader(GLuint id, SHADER_TYPE type, std::string name) :
			m_type(type),
			m_id(id),
			m_name(name)
		{}
	};

	/** Singleton Shader Library */
	class ShaderLibrary
	{
	public:
		~ShaderLibrary() = default;
		ShaderLibrary(ShaderLibrary const&) = delete;
		void operator=(ShaderLibrary const&) = delete;

		/** @brief Accessor */
		static ShaderLibrary& getInstance();

		void addShaderFromFile(const std::string& name, const std::string& filePath, SHADER_TYPE type);
		std::shared_ptr<Shader> getShader(const std::string& name);

		void initializeDefaultShaders();

	private:
		ShaderLibrary();

		std::vector<std::shared_ptr<Shader>> m_ShaderList;
	};
}//namespace Graphics