#pragma once

#include "Window.h"
#include "LayerStack.h"

namespace Vnut
{

	class Engine
	{
	public:
		Engine(const unsigned int height, const unsigned int width, const char* title);

		void run();
		void stop();
	private:
		const unsigned int m_height, m_width;
		const char* m_title;
		Window* m_window = new Window(m_height, m_width, m_title);
		bool m_running;
	};

}