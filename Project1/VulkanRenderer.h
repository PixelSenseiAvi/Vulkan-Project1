#pragma once

//#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <set>

#include <iostream>

#include "Utilities.h"

class VulkanRenderer
{
public:
	VulkanRenderer();

	int init(GLFWwindow* window);

	void cleanup();
	~VulkanRenderer();

private:
	GLFWwindow* window;


	//Vulkan Components
	VkInstance instance;

	struct {
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	}mainDevice;

	VkQueue graphicsQueue;
	VkQueue presentationQueue;

	VkSurfaceKHR surface;

	//Vulkan Functions
	void createInstance();
	void createLogicalDevice();
	void createSurface();

	//Get functions
	void getPhysicalDevice();

	bool checkInstanceExtensionSupport(std::vector<const char*>* extensions);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
	SwapChainDetails getSwapChainDetails(VkPhysicalDevice device);
};

