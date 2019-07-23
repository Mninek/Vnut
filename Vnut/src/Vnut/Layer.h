#pragma once

#include "Event/Event.h"

namespace Vnut
{
	class Layer
	{
	public:
		Layer() : m_enabled(true) {}
		virtual ~Layer() {}
		virtual void start() {}
		virtual void stop() {}
		virtual void update() {}
		virtual void onEvent(Event& event) {}
		void setEnabled(bool enabled) { m_enabled = enabled; }
		bool isEnabled() { return m_enabled; }
	protected:
		bool m_enabled;
	};
}