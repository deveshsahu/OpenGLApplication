#pragma once
#include "gl_core_4_5.h"
#include <GLFW/glfw3.h>
#include <memory>
class Window
{
public:
	Window() = default;
	~Window() = default;

	void run();

	static void onWindowResized(GLFWwindow*, int, int);
	static void onCheckError(int error, const char* description);
private:
	void myInitWindow();
	void myMainLoop();
	void myCleanup();

	void myResizeCallback(int, int);

private:
	GLFWwindow* myGLWindow;
};

