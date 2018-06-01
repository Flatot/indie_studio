//
// EPITECH PROJECT, 2018
// IMyEventReceiver.hpp
// File description:
// IMyEventReceiver class
//

#pragma once

#include <string>
#include "IEventReceiver.h"

namespace bbm {
	enum SPECIALKEY {
		NONE = 0,
		CONTROL,
		SHIFT
	};

	class IMyEventReceiver : public irr::IEventReceiver {
	public:
		IMyEventReceiver();
		virtual bool OnEvent(const irr::SEvent &event) override;
		bool isActive();
		void activate();
		void deactivate();
		bool isKeyPressed(irr::EKEY_CODE key, SPECIALKEY specialKey);
		void resetKey(irr::EKEY_CODE key, SPECIALKEY specialKey);
		void resetKeys();

	protected:
		bool _isActive;
		bool _keys[irr::KEY_KEY_CODES_COUNT];
		bool _keysCtrl[irr::KEY_KEY_CODES_COUNT];
		bool _keysShift[irr::KEY_KEY_CODES_COUNT];
	};
}
