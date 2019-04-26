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

	// Glfw Callbacks
	static void onCheckError(int error, const char* description);
	static void onWindowResized(GLFWwindow*, int, int);
	static void onMouseMove(GLFWwindow*, double, double);
	static void onMouseButton(GLFWwindow*, int, int, int);
	static void onMouseScroll(GLFWwindow*, double, double);

private:
	void mInitWindow();
	void mMainLoop();
	void mCleanup();

private:
	GLFWwindow* mGLWindow;
	static std::weak_ptr<Graphics::Scene> mActiveScene;
};

