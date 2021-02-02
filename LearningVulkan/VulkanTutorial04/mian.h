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

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif // NDEBUG

	const std::vector<const char *> validationLayers = { "VK_LAYER_LUNARG_standard_validation" };

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
	bool checkValidationLayerSupport();

	std::vector<const char *> getRequiredExtensions();
	void setupDebugCallback();

	VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
	void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator);

private:
	GLFWwindow *_windows;
	VkInstance instance;
	VkDebugReportCallbackEXT callback;
};

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
	VkDebugReportFlagsEXT flage, VkDebugReportObjectTypeEXT objType,
	uint64_t obj, size_t loaction, int32_t code, const char *layerPrefix,
	const char *msg, void *userData);



