#pragma once

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <vector>

class HelloTriangleApplication
{
public:
	HelloTriangleApplication();
	~HelloTriangleApplication();
	void run();
	void initWindows();
	void initVulkan();
	void mainLoop();
	void clearup();
	
	void createInstance();
private:
	GLFWwindow *_windows;
	VkInstance instance;
};



