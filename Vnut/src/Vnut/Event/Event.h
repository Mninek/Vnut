#pragma once

#include <iostream>

namespace Vnut
{

	enum EventType {
		WINDOW_CLOSE, WINDOW_RESIZE,
		KEY_PRESS, KEY_RELEASE, KEY_REPEAT,
		MOUSE_BUTTON_PRESS, MOUSE_BUTTON_RELEASE, MOUSE_MOVE, MOUSE_SCROLL
	};

	class Event
	{
	public:
		virtual EventType getType() {}
		bool isHandled() { return m_handled; }
		void setHandled(bool handled) { m_handled = handled; }
	protected:
		bool m_handled = false;
	};

	class WindowCloseEvent : public Event
	{
	public:
		EventType getType() { return WINDOW_CLOSE; }
	};

	class WindowResizeEvent : public Event
	{
	public:
		EventType getType() { return WINDOW_RESIZE; }
		unsigned int getWidth() { return m_width; }
		unsigned int getHeight() { return m_height; }
	private:
		unsigned int m_width, m_height;
	};

	class KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(int key) : m_key(key) {}
		EventType getType() { return KEY_PRESS; }
		int getKey() { return m_key; }
	private:
		int m_key;
	};

	class KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(int key) : m_key(key) {}
		EventType getType() { return KEY_RELEASE; }
		int getKey() { return m_key; }
	private:
		int m_key;
	};

	class KeyRepeatEvent : public Event
	{
	public:
		KeyRepeatEvent(int key) : m_key(key) {}
		EventType getType() { return KEY_REPEAT; }
		int getKey() { return m_key; }
	private:
		int m_key;
	};

}