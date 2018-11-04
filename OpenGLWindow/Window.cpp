#include "pch.h"
#include "Window.h"

#define WIDTH 800
#define HEIGHT 600

void Window::run()
{
	myInitWindow();
	myMainLoop();
	myCleanup();
}

void Window::onWindowResized(GLFWwindow * window, int width, int height)
{
	auto app = reinterpret_cast<Window*>(window);
	app->myResizeCallback(width, height);
}

void Window::myInitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	myGLWindow = (glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", nullptr, nullptr));

	glfwSetWindowUserPointer(myGLWindow, this);
	glfwSetWindowSizeCallback(myGLWindow, Window::onWindowResized);
}

void Window::myResizeCallback(int width, int height)
{
	//glViewport(0, 0, width, height);
}

void Window::myMainLoop()
{
	while (!glfwWindowShouldClose(myGLWindow))
	{
		glfwPollEvents();
	}

}

void Window::myCleanup()
{
	glfwDestroyWindow(myGLWindow);
	glfwTerminate();
}
