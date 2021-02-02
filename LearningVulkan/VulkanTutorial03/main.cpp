
#include "mian.h"


HelloTriangleApplication::HelloTriangleApplication()
{
}

HelloTriangleApplication::~HelloTriangleApplication()
{
}

void HelloTriangleApplication::run()
{
	initWindows();
	initVulkan();
	mainLoop();
	clearup();
}

void HelloTriangleApplication::initVulkan()
{
	createInstance();
}

void HelloTriangleApplication::initWindows()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	const int WIDTH = 800, HEIGHT = 600;
	_windows = glfwCreateWindow(WIDTH, HEIGHT, "VULKAN", nullptr, nullptr);
}

void HelloTriangleApplication::createInstance()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pNext = nullptr;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	unsigned int glfwExtensionCount = 0;
	const char **glfwExtension = nullptr;
	glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtension;
	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create instance!");
	}

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	std::cout << "available extensions:" << std::endl;
	for (const auto &extension : extensions)
	{
		std::cout << "\t" << extension.extensionName << std::endl;
	}
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
	vkDestroyInstance(instance,nullptr);
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