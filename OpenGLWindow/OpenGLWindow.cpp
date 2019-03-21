#include <iostream>
#include <stdexcept>
#include <memory>

#include "Window.h"
#include "../Model/TeapotModel.h"

int main()
{
	// Controller
	Window myWindow;

	// Model
	TeapotModel myModel;
	try
	{
		myWindow.run();
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		return EXIT_FAILURE;
	}
}
