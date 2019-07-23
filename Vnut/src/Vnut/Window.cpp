#include <iostream>

#include "Window.h"

using namespace Vnut;

Window::Window(unsigned int width, unsigned int height, const char *title) :
	m_width(width), m_height(height), m_title(title), m_shouldClose(false)
{
	if (!init())
		glfwTerminate();
}

bool Window::init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW!" << std::endl;
		return false;
	}
	m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
	if (!m_window)
	{
		std::cout << "Failed to create window!" << std::endl;
		return false;
	}
	glfwMakeContextCurrent(m_window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	glViewport(0, 0, m_width, m_height);
	glfwSetScrollCallback(m_window, EventDispatcher::dispatchMouseScrollEvent);
	glfwSetCursorPosCallback(m_window, EventDispatcher::dispatchMouseMoveEvent);
	glfwSetMouseButtonCallback(m_window, EventDispatcher::dispatchMouseButtonEvent);
	glfwSetKeyCallback(m_window, EventDispatcher::dispatchKeyEvent);
	glfwSetWindowSizeCallback(m_window, EventDispatcher::dispatchWindowResizeEvent);
	return true;
}

bool Window::shouldClose()
{
	return m_shouldClose;
}

void Window::update()
{
	glfwSwapBuffers(m_window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
	m_shouldClose = glfwWindowShouldClose(m_window);
}

void Window::terminate()
{
	glfwTerminate();
}

GLFWwindow* Window::getWindow()
{
	return m_window;
}