//
// EPITECH PROJECT, 2018
// PlayerConfig.hpp
// File description:
// PlayerConfig class
//

#pragma once

#include <map>
#include <fstream>
#include <ostream>
#include <algorithm>
#include "IEntity.hpp"
#include "irrlicht.h"

typedef struct s_keys {
	std::string str;
	irr::EKEY_CODE keycode;
} keys_t;

namespace bbm {
	class PlayerConfig {
	public:
		PlayerConfig(bbm::Entities entity);
		std::map<std::string, irr::EKEY_CODE> getMap() const;
		std::map<std::string, irr::EKEY_CODE> &getMap();
		std::string getName() const;
		void loadConfig();
		std::string codeToString(irr::EKEY_CODE code) const;
		irr::EKEY_CODE stringToCode(std::string str) const;
	private:
		std::string _name;
		bbm::Entities _entity;
		std::map<std::string, irr::EKEY_CODE> _keys;
		bool isValuable(std::string str);
		bool handleLine(std::string line, std::string delimiter,
				bool start);
	};
}

std::ostream& operator<< (std::ostream& stream,
		bbm::PlayerConfig const& playerConf);

static std::string valuableControl[5] = {
	"PUT_BOMB",
	"UP",
	"DOWN",
	"RIGHT",
	"LEFT"
};

static keys_t keysparse[] = {
	{"KEY_LBUTTON", irr::KEY_LBUTTON},
	{"KEY_RBUTTON", irr::KEY_RBUTTON},
	{"KEY_CANCEL", irr::KEY_CANCEL},
	{"KEY_MBUTTON", irr::KEY_MBUTTON},
	{"KEY_XBUTTON1", irr::KEY_XBUTTON1},
	{"KEY_XBUTTON2", irr::KEY_XBUTTON2},
	{"KEY_BACK", irr::KEY_BACK},
	{"KEY_TAB", irr::KEY_TAB},
	{"KEY_CLEAR", irr::KEY_CLEAR},
	{"KEY_RETURN", irr::KEY_RETURN },
	{"KEY_SHIFT", irr::KEY_SHIFT},
	{"KEY_CONTROL", irr::KEY_CONTROL},
	{"KEY_MENU", irr::KEY_MENU},
	{"KEY_PAUSE", irr::KEY_PAUSE},
	{"KEY_CAPITAL", irr::KEY_CAPITAL},
	{"KEY_KANA", irr::KEY_KANA},
	{"KEY_HANGUEL", irr::KEY_HANGUEL},
	{"KEY_HANGUL", irr::KEY_HANGUL},
	{"KEY_JUNJA", irr::KEY_JUNJA},
	{"KEY_FINAL", irr::KEY_FINAL},
	{"KEY_HANJA", irr::KEY_HANJA},
	{"KEY_KANJI", irr::KEY_KANJI},
	{"KEY_ESCAPE", irr::KEY_ESCAPE },
	{"KEY_ESCAPE", irr::KEY_CONVERT},
	{"KEY_NONCONVERT", irr::KEY_NONCONVERT},
	{"KEY_MODECHANGE", irr::KEY_MODECHANGE},
	{"KEY_SPACE", irr::KEY_SPACE},
	{"KEY_PRIOR", irr::KEY_PRIOR},
	{"KEY_NEXT", irr::KEY_NEXT},
	{"KEY_END", irr::KEY_END},
	{"KEY_HOME", irr::KEY_HOME},
	{"KEY_LEFT", irr::KEY_LEFT},
	{"KEY_UP", irr::KEY_UP },
	{"KEY_RIGHT", irr::KEY_RIGHT},
	{"KEY_DOWN", irr::KEY_DOWN},
	{"KEY_SELECT", irr::KEY_SELECT },
	{"KEY_PRINT", irr::KEY_PRINT},
	{"KEY_EXECUT", irr::KEY_EXECUT },
	{"KEY_SNAPSHOT", irr::KEY_SNAPSHOT},
	{"KEY_INSERT", irr::KEY_INSERT },
	{"KEY_DELETE", irr::KEY_DELETE },
	{"KEY_HELP", irr::KEY_HELP},
	{"KEY_KEY_0", irr::KEY_KEY_0},
	{"KEY_KEY_1", irr::KEY_KEY_1},
	{"KEY_KEY_2", irr::KEY_KEY_2},
	{"KEY_KEY_3", irr::KEY_KEY_3},
	{"KEY_KEY_4", irr::KEY_KEY_4},
	{"KEY_KEY_5", irr::KEY_KEY_5},
	{"KEY_KEY_6", irr::KEY_KEY_6},
	{"KEY_KEY_7", irr::KEY_KEY_7},
	{"KEY_KEY_8", irr::KEY_KEY_8},
	{"KEY_KEY_9", irr::KEY_KEY_9},
	{"KEY_KEY_A", irr::KEY_KEY_A},
	{"KEY_KEY_B", irr::KEY_KEY_B},
	{"KEY_KEY_C", irr::KEY_KEY_C},
	{"KEY_KEY_D", irr::KEY_KEY_D},
	{"KEY_KEY_E", irr::KEY_KEY_E},
	{"KEY_KEY_F", irr::KEY_KEY_F},
	{"KEY_KEY_G", irr::KEY_KEY_G},
	{"KEY_KEY_H", irr::KEY_KEY_H},
	{"KEY_KEY_I", irr::KEY_KEY_I},
	{"KEY_KEY_J", irr::KEY_KEY_J},
	{"KEY_KEY_K", irr::KEY_KEY_K},
	{"KEY_KEY_L", irr::KEY_KEY_L},
	{"KEY_KEY_M", irr::KEY_KEY_M},
	{"KEY_KEY_N", irr::KEY_KEY_N},
	{"KEY_KEY_O", irr::KEY_KEY_O},
	{"KEY_KEY_P", irr::KEY_KEY_P},
	{"KEY_KEY_Q", irr::KEY_KEY_Q},
	{"KEY_KEY_R", irr::KEY_KEY_R},
	{"KEY_KEY_S", irr::KEY_KEY_S},
	{"KEY_KEY_T", irr::KEY_KEY_T},
	{"KEY_KEY_U", irr::KEY_KEY_U},
	{"KEY_KEY_V", irr::KEY_KEY_V},
	{"KEY_KEY_W", irr::KEY_KEY_W},
	{"KEY_KEY_X", irr::KEY_KEY_X},
	{"KEY_KEY_Y", irr::KEY_KEY_Y},
	{"KEY_KEY_Z", irr::KEY_KEY_Z},
	{"KEKEY_LWINY_", irr::KEY_LWIN},
	{"KEY_RWIN", irr::KEY_RWIN},
	{"KEY_APPS", irr::KEY_APPS},
	{"KEY_SLEEP", irr::KEY_SLEEP},
	{"KEY_NUMPAD0", irr::KEY_NUMPAD0},
	{"KEY_NUMPAD1", irr::KEY_NUMPAD1},
	{"KEY_NUMPAD2", irr::KEY_NUMPAD2},
	{"KEY_NUMPAD3", irr::KEY_NUMPAD3},
	{"KEY_NUMPAD4", irr::KEY_NUMPAD4},
	{"KEY_NUMPAD5", irr::KEY_NUMPAD5},
	{"KEY_NUMPAD6", irr::KEY_NUMPAD6},
	{"KEY_NUMPAD7", irr::KEY_NUMPAD7},
	{"KEY_NUMPAD8", irr::KEY_NUMPAD8},
	{"KEY_NUMPAD9", irr::KEY_NUMPAD9},
	{"KEY_MULTIPLY", irr::KEY_MULTIPLY},
	{"KEY_ADD", irr::KEY_ADD},
	{"KEY_SEPARATOR", irr::KEY_SEPARATOR},
	{"KEY_SUBTRACT", irr::KEY_SUBTRACT},
	{"KEY_DECIMAL", irr::KEY_DECIMAL},
	{"KEY_DIVIDE", irr::KEY_DIVIDE },
	{"KEY_F1", irr::KEY_F1 },
	{"KEY_F2", irr::KEY_F2 },
	{"KEY_F3", irr::KEY_F3 },
	{"KEY_F4", irr::KEY_F4 },
	{"KEY_F5", irr::KEY_F5 },
	{"KEY_F6", irr::KEY_F6 },
	{"KEY_F7", irr::KEY_F7 },
	{"KEY_F8", irr::KEY_F8 },
	{"KEY_F9", irr::KEY_F9 },
	{"KEY_F10", irr::KEY_F10},
	{"KEY_F11", irr::KEY_F11},
	{"KEY_F12", irr::KEY_F12},
	{"KEY_F13", irr::KEY_F13},
	{"KEY_F14", irr::KEY_F14},
	{"KEY_F15", irr::KEY_F15},
	{"KEY_F16", irr::KEY_F16},
	{"KEY_F17", irr::KEY_F17},
	{"KEY_F18", irr::KEY_F18},
	{"KEY_F19", irr::KEY_F19},
	{"KEY_F20", irr::KEY_F20},
	{"KEY_F21", irr::KEY_F21},
	{"KEY_F22", irr::KEY_F22},
	{"KEY_F23", irr::KEY_F23},
	{"KEY_F24", irr::KEY_F24},
	{"KEY_NUMLOCK", irr::KEY_NUMLOCK},
	{"KEY_SCROLL", irr::KEY_SCROLL},
	{"KEY_LSHIFT", irr::KEY_LSHIFT},
	{"KEY_RSHIFT", irr::KEY_RSHIFT},
	{"KEY_LCONTROL", irr::KEY_LCONTROL},
	{"KEY_RCONTROL", irr::KEY_RCONTROL},
	{"KEY_LMENU", irr::KEY_LMENU},
	{"KEY_RMENU", irr::KEY_RMENU},
	{"KEY_OEM_1", irr::KEY_OEM_1},
	{"KEY_PLUS", irr::KEY_PLUS},
	{"KEY_COMMA", irr::KEY_COMMA},
	{"KEY_MINUS", irr::KEY_MINUS},
	{"KEY_PERIOD", irr::KEY_PERIOD},
	{"KEY_OEM_2", irr::KEY_OEM_2},
	{"KEY_OEM_3", irr::KEY_OEM_3},
	{"KEY_OEM_4", irr::KEY_OEM_4},
	{"KEY_OEM_5", irr::KEY_OEM_5},
	{"KEY_OEM_6", irr::KEY_OEM_6},
	{"KEY_OEM_7", irr::KEY_OEM_7},
	{"KEY_OEM_8", irr::KEY_OEM_8},
	{"KEY_OEM_AX", irr::KEY_OEM_AX },
	{"KEY_OEM_102", irr::KEY_OEM_102},
	{"KEY_ATTN", irr::KEY_ATTN},
	{"KEY_CRSEL", irr::KEY_CRSEL},
	{"KEY_EXSEL", irr::KEY_EXSEL},
	{"KEY_EREOF", irr::KEY_EREOF},
	{"KEY_PLAY", irr::KEY_PLAY},
	{"KEY_ZOOM", irr::KEY_ZOOM},
	{"KEY_PA1", irr::KEY_PA1},
	{"KEY_OEM_CLEAR", irr::KEY_OEM_CLEAR},
	{"KEY_KEY_CODES_COUNT", irr::KEY_KEY_CODES_COUNT},
};