#include "Vnut.h"

#include <iostream>

class TestLayer : public Vnut::Layer
{

};

int main()
{
	Vnut::Engine* engine = new Vnut::Engine(600, 800, "Sandbox");
	engine->run();
}