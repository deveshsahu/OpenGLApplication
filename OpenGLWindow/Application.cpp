#include <iostream>
#include <stdexcept>
#include <memory>

#include "MainWindow.h"

int main()
{
	// Controller
	MainWindow myWindow;

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
