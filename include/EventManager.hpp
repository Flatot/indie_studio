//
// EPITECH PROJECT, 2018
// EventManager.hpp
// File description:
// Event Manager class
//

#pragma once

#include <vector>
#include "IMyEventReceiver.hpp"

namespace bbm {
	class EventManager : public IMyEventReceiver {
	public:
		EventManager();
		virtual bool OnEvent(const irr::SEvent &event) override;
		void removeEventReceiver(IMyEventReceiver *ev);
		void addEventReceiver(IMyEventReceiver *ev);
		void setRoot(bool toggle);
//		void startEventProcess();
//		void endEventProcess();
	private:
		bool _root;
		std::vector<IMyEventReceiver *> _evReceivers;
	};
}
