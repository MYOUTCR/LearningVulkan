#pragma once

#ifndef _HELLO_TRIANGLE_APPLICATION_H
#define _HELLO_TRIANGLE_APPLICATION_H

#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>
#include<GLFW/glfw3.h>

#include<vector>

class HelloTriangleApplication
{
public:
	HelloTriangleApplication();
	~HelloTriangleApplication();
public:
	void run();

protected:
	void initWindows();
	void initVulkan();
	void mainLoop();
	void cleanup();

	void createInstance();

	bool checkValidationLayerSupport();

	std::vector<const char*> getRequiredExtensions();
private:
	GLFWwindow* m_window = nullptr;
	VkInstance m_instance;
};

#endif // !_HELLO_TRIANGLE_APPLICATION_H




