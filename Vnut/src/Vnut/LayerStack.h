#pragma once

#include <vector>

#include "Layer.h"

namespace Vnut
{
	class LayerStack
	{
	public:
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
		void popLayer(Layer* layer);
		void popOverlay(Layer* overlay);
	private:
		std::vector<Layer*> m_layers;
		unsigned int m_lastLayerIndex = 0;
	};
}