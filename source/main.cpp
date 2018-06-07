//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main
//

#include "irrlicht.h"
#include "Config.hpp"
#include "Game.hpp"

int main()
{
	bbm::Config config;
	bbm::Game g(config);

	g.run();
	return 0;
}
