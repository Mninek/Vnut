#include "LayerStack.h"

using namespace Vnut;

LayerStack::~LayerStack()
{
	for (Layer* layer : m_layers)
	{
		delete layer;
	}
}

void LayerStack::pushLayer(Layer* layer)
{
	m_layers.emplace(m_layers.begin() + m_lastLayerIndex, layer);
	m_lastLayerIndex++;
	layer->start();
}

void LayerStack::pushOverlay(Layer* overlay)
{
	m_layers.emplace_back(overlay);
	overlay->start();
}

void LayerStack::popLayer(Layer* layer)
{
	auto it = std::find(m_layers.begin(), m_layers.end(), layer);
	if (it != m_layers.end())
	{
		m_layers.erase(it);
		m_lastLayerIndex--;
		layer->stop();
	}
}

void LayerStack::popOverlay(Layer* overlay)
{
	auto it = std::find(m_layers.begin(), m_layers.end(), overlay);
	if (it != m_layers.end())
	{
		m_layers.erase(it);
		overlay->stop();
	}
}