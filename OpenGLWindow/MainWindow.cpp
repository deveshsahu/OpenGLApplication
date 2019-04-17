#include "MainWindow.h"
#include "Graphics.h"
#include "Scene.h"
#include "GLUtils.h"
#include "TriangleRenderable.h"
#include <assert.h>
#include <iostream>

static const int WIDTH = 800;
static const int HEIGHT = 600;

std::weak_ptr<Graphics::Scene> MainWindow::m_ActiveScene;

void MainWindow::run()
{
	myInitWindow();
	myMainLoop();
	myCleanup();
}

void MainWindow::onWindowResized(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
	if (auto scene = m_ActiveScene.lock())
		scene->resize(width, height);
}

void MainWindow::onCheckError(int error, const char * description)
{
	std::cout << "ERROR: " << description << std::endl;
}

void MainWindow::myInitWindow()
{
	glfwSetErrorCallback(onCheckError);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef _DEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif // DEBUG

	myGLWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", nullptr, nullptr);
	assert(myGLWindow != nullptr);
	glfwSetWindowUserPointer(myGLWindow, this);
	glfwSetWindowSizeCallback(myGLWindow, MainWindow::onWindowResized);

	glfwMakeContextCurrent(myGLWindow);
	ogl_LoadFunctions();
	
	glDebugMessageCallback(GLUtils::debugCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
	/*glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 0,
		GL_DEBUG_SEVERITY_NOTIFICATION, -1, "Start debugging");*/

	auto& systemGraphics = Graphics::OpenGLGraphics::getInstance();
	systemGraphics.createNewScene(WIDTH, HEIGHT);
	auto scene = systemGraphics.getScene();
	m_ActiveScene = scene;
	scene->addRenderable(std::make_shared <Graphics::TriangleRenderable>("Triangle") );
	scene->addBackground("");
	scene->init();
}

void MainWindow::myMainLoop()
{
	auto scene = m_ActiveScene.lock();
	while (!glfwWindowShouldClose(myGLWindow))
	{
		glfwMakeContextCurrent(myGLWindow);
		if (scene)
			scene->render();
		glfwSwapBuffers(myGLWindow);
		glfwWaitEvents();
	}

}

void MainWindow::myCleanup()
{
	glfwDestroyWindow(myGLWindow);
	glfwTerminate();
}
