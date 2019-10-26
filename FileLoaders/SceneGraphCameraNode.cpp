#include "SceneGraphCameraNode.h"

namespace sg
{
	OrthographicCameraNode::OrthographicCameraNode(double xmag, double ymag, double zfar, double znear, std::string name):
		CameraNode(CamType::ctOrthographic, name)
	{
	}

	PerspectiveCameraNode::PerspectiveCameraNode(double aspectRatio, double yfov, double znear, double zfar, std::string name):
		CameraNode(CamType::ctPerspective, name)
	{
	}
}