#pragma once
#include "SceneGraphNode.h"
#include "glm/glm.hpp"
namespace sg
{
	enum class CamType
	{
		ctPerspective,
		ctOrthographic
	};

	class CameraNode : public Node
	{
	public:
		CameraNode(CamType type, const std::string& name) :
			Node(name),
			mCameraType(type)
		{
		}

		~CameraNode() 
		{
		}

	private:
		CamType mCameraType;
		glm::mat4 mCameraMatrix;
	};

	class OrthographicCameraNode : public CameraNode
	{
	public:
		OrthographicCameraNode(double xmag, double ymag, double zfar, double znear, std::string name = "Ortho Cam");
	private:

	};

	class PerspectiveCameraNode : public CameraNode
	{
	public:
		PerspectiveCameraNode(double aspectRatio, double yfov, double znear, double zfar, std::string name = "Persp Cam");
	private:
	};
}