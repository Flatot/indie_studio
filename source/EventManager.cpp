//
// EPITECH PROJECT, 2018
// EventManager.cpp
// File description:
// Event Manager implementation
//

#include <iostream>
#include "EventManager.hpp"

bbm::EventManager::EventManager() : 
	IMyEventReceiver(),
	_root(false),
	_evReceivers()
{
	activate();
}

bool bbm::EventManager::OnEvent(const irr::SEvent &event)
{
	if (_root) {
		std::cout << "EventManager root ";
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
			std::cout << ((event.KeyInput.PressedDown) ? "PressedDown " : "") << "[" << (char)event.KeyInput.Char << "] [" << event.KeyInput.Key ; 
		else
			std::cout << "[Not a char";
		std::cout << "] - OnEvent" << std::endl;
	}
	for (auto it = _evReceivers.begin(); it != _evReceivers.end(); ++it) {
		auto ev = *it;
		if (ev->isActive() && ev->OnEvent(event))
			return true;
	}
	return false;
}

void bbm::EventManager::removeEventReceiver(IMyEventReceiver *ev)
{
	for (auto it = _evReceivers.begin(); it != _evReceivers.end(); ++it)
		if (*it == ev)
			_evReceivers.erase(it);
}

void bbm::EventManager::addEventReceiver(IMyEventReceiver *ev)
{
	_evReceivers.push_back(ev);
}

void bbm::EventManager::setRoot(bool toggle)
{
	_root = toggle;
}
