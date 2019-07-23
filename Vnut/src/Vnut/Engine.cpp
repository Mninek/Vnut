#include "Engine.h"

#include <iostream>

using namespace Vnut;

Engine::Engine(const unsigned int width, const unsigned int height, const char* title) :
	m_width(width), m_height(height), m_title(title), m_running(false)
{

}

void Engine::run()
{
	m_running = true;
	while (m_running)
	{
		if (m_window->shouldClose())
		{
			stop();
		}
		m_window->update();
	}
}

void Engine::stop()
{
	m_running = false;
	EventDispatcher::dispatchWindowCloseEvent();
	m_window->terminate();
}