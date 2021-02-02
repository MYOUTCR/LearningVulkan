

#include "HelloTriangleApplication.h"



HelloTriangleApplication::HelloTriangleApplication()
{
}

HelloTriangleApplication::~HelloTriangleApplication()
{
}

void HelloTriangleApplication::run()
{
	initVulkan();
	mainLoop();
	clearup();
}

void HelloTriangleApplication::initVulkan()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	const int WIDTH = 800, HEIGHT = 600;
	_windows = glfwCreateWindow(WIDTH, HEIGHT, "VULKAN", nullptr, nullptr);

}

void HelloTriangleApplication::mainLoop()
{
	while (!glfwWindowShouldClose(_windows))
	{
		glfwPollEvents();
	}
}

void HelloTriangleApplication::clearup()
{
	glfwDestroyWindow(_windows);
	glfwTerminate();
}

int main()
{
	HelloTriangleApplication app;
	try
	{
		app.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}