#include "MainWindow.h"
#include "Graphics.h"
#include "Scene.h"
#include "GLUtils.h"
#include "TriangleRenderable.h"
#include "MouseEvent.h"
#include "GLTFModel.h"
#include <assert.h>
#include <iostream>

static const int WIDTH = 800;
static const int HEIGHT = 600;

namespace controller
{
	void MainWindow::run()
	{
		mInitWindow();
		mMainLoop();
		mCleanup();
	}

	void MainWindow::onWindowResized(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);

		//scene->resize(width, height);
	}

	void MainWindow::onMouseMove(GLFWwindow* w, double xpos, double ypos)
	{
		if (!w)
			return;
		/*if (auto scene = mActiveScene.lock())
			scene->mouseMove(xpos, ypos);*/
	}

	void MainWindow::onMouseButton(GLFWwindow* w, int button, int action, int mods)
	{
		if (!w)
			return;

		Graphics::MouseButtonEvent evt;
		glfwGetCursorPos(w, &evt.xpos, &evt.ypos);

		switch (button)
		{
		case GLFW_MOUSE_BUTTON_LEFT:
			evt.button = Graphics::MouseButton::mbLeft;
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			evt.button = Graphics::MouseButton::mbRight;
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
			evt.button = Graphics::MouseButton::mbMiddle;
			break;
		}
		switch (action)
		{
		case GLFW_PRESS:
			evt.state = Graphics::ButtonState::bsPressed;
			break;
		case GLFW_RELEASE:
			evt.state = Graphics::ButtonState::bsReleased;
			break;
		default:
			break;
		}

		switch (mods)
		{
		case GLFW_MOD_CONTROL:
			evt.mods = Graphics::Modifier::modCtrl;
			break;
		case GLFW_MOD_ALT:
			evt.mods = Graphics::Modifier::modAlt;
			break;
		case GLFW_MOD_SHIFT:
			evt.mods = Graphics::Modifier::modShift;
			break;
		default:
			evt.mods = Graphics::Modifier::modInvalid;
		}

		/*if (auto scene = mActiveScene.lock())
		{
			scene->mouseButton(evt);
		}*/
	}

	void MainWindow::onMouseScroll(GLFWwindow* w, double xoffset, double yoffset)
	{
		if (!w)
			return;
		/*if (auto scene = mActiveScene.lock())
			scene->mouseScroll(xoffset, yoffset);*/
	}

	void MainWindow::onCheckError(int error, const char* description)
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
		// Mouse scroll
		glfwSetScrollCallback(mGLWindow, MainWindow::onMouseScroll);

		glfwMakeContextCurrent(mGLWindow);
		ogl_LoadFunctions();

#ifdef _DEBUG
		glDebugMessageCallback(GLUtils::debugCallback, NULL);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
#endif // _DEBUG

		mModel = new model::GLTFModel();
		if (!mModel->load("D:\\FirefoxDownloads\\GLTF Samples\\Lantern.glb"))
			return;

		/*auto& systemGraphics = Graphics::OpenGLGraphics::getInstance();
		systemGraphics.createNewScene(WIDTH, HEIGHT);*/
		/*auto scene = systemGraphics.getScene();
		std::vector<glm::vec3> vtx;
		vtx.push_back(glm::vec3(0, 0.288, 0));
		vtx.push_back(glm::vec3(0, -0.1445, 0.289));
		vtx.push_back(glm::vec3(0.25, -0.1445, -0.1445));
		vtx.push_back(glm::vec3(-0.25, -0.1445, -0.1445));
		std::vector<unsigned int> idx;
		idx.push_back(0);
		idx.push_back(1);
		idx.push_back(2);

		idx.push_back(0);
		idx.push_back(2);
		idx.push_back(3);

		idx.push_back(0);
		idx.push_back(3);
		idx.push_back(1);

		idx.push_back(1);
		idx.push_back(3);
		idx.push_back(2);*/

		//scene->addRenderable(std::make_shared <Graphics::TriangleRenderable>("Tetrahedra", vtx, idx) );
		//scene->addBackground("Solid Background");



		/*scene->init();
		mActiveScene = scene;*/
	}

	void MainWindow::mMainLoop()
	{
		//auto scene = mActiveScene.lock();
		while (!glfwWindowShouldClose(mGLWindow))
		{
			glfwMakeContextCurrent(mGLWindow);
			Graphics::OpenGLGraphics::getInstance().render();
			glfwSwapBuffers(mGLWindow);
			glfwWaitEvents();
		}
	}

	void MainWindow::mCleanup()
	{
		glfwDestroyWindow(mGLWindow);
		glfwTerminate();
	}
}