#pragma once
#include <GLFW/glfw3.h>
#include <memory>
class Window
{
public:
	Window() = default;
	~Window() = default;

	void run();

	static void onWindowResized(GLFWwindow*, int, int);
private:
	void myInitWindow();
	void myMainLoop();
	void myCleanup();

	void myResizeCallback(int, int);

private:
	GLFWwindow* myGLWindow;
};

