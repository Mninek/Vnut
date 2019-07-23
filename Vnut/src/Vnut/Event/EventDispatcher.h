#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Event.h"
#include "..//LayerStack.h"

class EventDispatcher
{
public:
	static void dispatchMouseScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
	{
	}
	static void dispatchMouseMoveEvent(GLFWwindow* window, double xpos, double ypos)
	{
	}
	static void dispatchMouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
	{
	}
	static void dispatchKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Event* event;
		switch (action)
		{
		case GLFW_PRESS:
			event = new KeyPressEvent(key);
		case GLFW_RELEASE:
			event = new KeyReleaseEvent(key);
		case GLFW_REPEAT:
			event = new KeyRepeatEvent(key);
		}
	}
	static void dispatchWindowResizeEvent(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	static void dispatchWindowCloseEvent()
	{

	}
};