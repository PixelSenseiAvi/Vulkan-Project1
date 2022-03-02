#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <string>

#include "VulkanRenderer.h"

GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string title = "Project 1", const int width = 800, const int height = 600)
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}


int main()
{

	initWindow("Project 1", 800, 600);

	if (vulkanRenderer.init(window) == EXIT_FAILURE)
		return EXIT_FAILURE;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	vulkanRenderer.cleanup();

	glfwDestroyWindow(window);

	glfwTerminate();
}