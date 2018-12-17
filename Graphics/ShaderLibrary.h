#pragma once
#include "opengl.h"
#include <vector>
#include <string>

enum SHADER_TYPE
{
	VERT,	// Vertex Shader
	FRAG,	// Fragment Shader
	TESC,	// Tessellation Compute Shader
	TESE,	// Tessallation Evaluation Shader
	COMP,	// Compute Shader
	GEOM,	// Geometry Shader
	SIZE
};

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

class ShaderLibrary
{
public:
	ShaderLibrary();
	~ShaderLibrary() = default;

	void addShaderFromFile(const std::string& name, const std::string& filePath, SHADER_TYPE type);

private:
	std::vector<Shader> m_ShaderList;
};