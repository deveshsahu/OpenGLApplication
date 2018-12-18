#include "Window.h"
#include "../Graphics/Graphics.h"
#include <assert.h>
#include <iostream>

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

void Window::onCheckError(int error, const char * description)
{
	std::cout << "ERROR: " << description << std::endl;
}

void Window::myInitWindow()
{
	glfwSetErrorCallback(onCheckError);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	myGLWindow = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", nullptr, nullptr);
	assert(myGLWindow != nullptr);
	glfwSetWindowUserPointer(myGLWindow, this);
	glfwSetWindowSizeCallback(myGLWindow, Window::onWindowResized);
	auto renderer = Graphics::OpenGLGraphics::getInstance();

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
