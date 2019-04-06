#pragma once
#include "gl_core_4_5.h"
#include <GLFW/glfw3.h>
#include <memory>
#include <unordered_map>

namespace Graphics
{
	class Scene;
}

class MainWindow
{
public:
	MainWindow() = default;
	~MainWindow() = default;

	void run();

	static void onWindowResized(GLFWwindow*, int, int);
	static void onCheckError(int error, const char* description);
private:
	void myInitWindow();
	void myMainLoop();
	void myCleanup();

private:
	GLFWwindow* myGLWindow;
	//static std::unordered_map<GLFWwindow*, Graphics::
	static std::weak_ptr<Graphics::Scene> m_ActiveScene;
};

