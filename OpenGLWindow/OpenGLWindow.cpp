#include "pch.h"
#include <iostream>
#include <stdexcept>

#include "Window.h"

int main()
{
	Window myWindow;
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
