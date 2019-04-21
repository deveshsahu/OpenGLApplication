#include "MainWindow.h"
#include "Graphics.h"
#include "Scene.h"
#include "GLUtils.h"
#include "TriangleRenderable.h"
#include <assert.h>
#include <iostream>

static const int WIDTH = 800;
static const int HEIGHT = 600;

std::weak_ptr<Graphics::Scene> MainWindow::mActiveScene;

void MainWindow::run()
{
	mInitWindow();
	mMainLoop();
	mCleanup();
}

void MainWindow::onWindowResized(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
	if (auto scene = mActiveScene.lock())
		scene->resize(width, height);
}

void MainWindow::onCursorMove(GLFWwindow *, double xpos, double ypos)
{
}

void MainWindow::onMouseButton(GLFWwindow *, int button, int action, int mods)
{
}

void MainWindow::onMouseScroll(GLFWwindow *, double, double)
{
}

void MainWindow::onCheckError(int error, const char * description)
{
	std::cout << "ERROR: " << description << std::endl;
}

void MainWindow::mInitWindow()
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

	mGLWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", nullptr, nullptr);
	assert(mGLWindow != nullptr);
	glfwSetWindowUserPointer(mGLWindow, this);
	// Window Resize
	glfwSetWindowSizeCallback(mGLWindow, MainWindow::onWindowResized);
	// Mouse Move
	glfwSetCursorPosCallback(mGLWindow, MainWindow::onMouseMove);
	// Mouse button
	glfwSetMouseButtonCallback(mGLWindow, MainWindow::onMouseButton);
	

	glfwMakeContextCurrent(mGLWindow);
	ogl_LoadFunctions();
	
	glDebugMessageCallback(GLUtils::debugCallback, NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
	/*glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION, GL_DEBUG_TYPE_MARKER, 0,
		GL_DEBUG_SEVERITY_NOTIFICATION, -1, "Start debugging");*/

	auto& systemGraphics = Graphics::OpenGLGraphics::getInstance();
	systemGraphics.createNewScene(WIDTH, HEIGHT);
	auto scene = systemGraphics.getScene();
	scene->addRenderable(std::make_shared <Graphics::TriangleRenderable>("Triangle") );
	scene->addBackground("Solid Background");
	scene->init();
	mActiveScene = scene;
}

void MainWindow::mMainLoop()
{
	auto scene = mActiveScene.lock();
	while (!glfwWindowShouldClose(mGLWindow))
	{
		glfwMakeContextCurrent(mGLWindow);
		if (scene)
			scene->render();
		glfwSwapBuffers(mGLWindow);
		glfwWaitEvents();
	}
}

void MainWindow::mCleanup()
{
	glfwDestroyWindow(mGLWindow);
	glfwTerminate();
}
