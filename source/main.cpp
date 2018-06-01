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
	auto *log = g.getGraphic().getDevice()->getLogger();
	log->log("Debut\n");

	g.run();

	return 0;
}
