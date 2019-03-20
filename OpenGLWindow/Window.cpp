#include "Window.h"
#include "Graphics.h"
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

	//glDebugMessageCallback(GLUtils::debugCallback, NULL);
	/*glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
	glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 0,
		GL_DEBUG_SEVERITY_NOTIFICATION, -1, "Start debugging");*/
	glfwMakeContextCurrent(myGLWindow);
	ogl_LoadFunctions();

	Graphics::OpenGLGraphics::getInstance().init();
}

void Window::myResizeCallback(int width, int height)
{
	Graphics::OpenGLGraphics::getInstance().resize(width, height);
}

void Window::myMainLoop()
{
	while (!glfwWindowShouldClose(myGLWindow))
	{
		glViewport(0, 0, WIDTH, HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(0.f, 0.0, 0, 1.0);
		Graphics::OpenGLGraphics::getInstance().render();

		glfwSwapBuffers(myGLWindow);
		glfwPollEvents();
	}

}

void Window::myCleanup()
{
	glfwDestroyWindow(myGLWindow);
	glfwTerminate();
}
