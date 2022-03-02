#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

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

	//Vulkan Functions
	void createInstance();
	void createLogicalDevice();

	//Get functions
	void getPhysicalDevice();

	bool checkInstanceExtensionSupport(std::vector<const char*>* extensions);
	bool checkDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices getQueueFamilies(VkPhysicalDevice device);
};

