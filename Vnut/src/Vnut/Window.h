#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Event\EventDispatcher.h"

namespace Vnut
{

	class Window
	{
	public:
		Window(unsigned int width, unsigned int heigth, const char *title);
		
		bool init();
		bool shouldClose();
		void update();
		void terminate();
		GLFWwindow* getWindow();
	private:
		unsigned int m_width, m_height;
		const char* m_title;
		GLFWwindow* m_window;
		bool m_shouldClose;
	};

}