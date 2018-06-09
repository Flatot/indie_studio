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
	{"KEY_LBUTTON", irr::KEY_LBUTTON},	// Left mouse button
	{"KEY_RBUTTON", irr::KEY_RBUTTON},	// Right mouse button
	{"KEY_CANCEL", irr::KEY_CANCEL},	// Control-break processing
	{"KEY_MBUTTON", irr::KEY_MBUTTON},	// Middle mouse button (three-button mouse)
	{"KEY_XBUTTON1", irr::KEY_XBUTTON1},	// Windows 2000/XP: X1 mouse button
	{"KEY_XBUTTON2", irr::KEY_XBUTTON2},	// Windows 2000/XP: X2 mouse button
	{"KEY_BACK", irr::KEY_BACK},		// BACKSPACE key
	{"KEY_TAB", irr::KEY_TAB},		// TAB key
	{"KEY_CLEAR", irr::KEY_CLEAR},		// CLEAR key
	{"KEY_RETURN", irr::KEY_RETURN },	// ENTER key
	{"KEY_SHIFT", irr::KEY_SHIFT},		// SHIFT key
	{"KEY_CONTROL", irr::KEY_CONTROL},	// CTRL key
	{"KEY_MENU", irr::KEY_MENU},		// ALT key
	{"KEY_PAUSE", irr::KEY_PAUSE},		// PAUSE key
	{"KEY_CAPITAL", irr::KEY_CAPITAL},	// CAPS LOCK key
	{"KEY_KANA", irr::KEY_KANA},		// IME Kana mode
	{"KEY_HANGUEL", irr::KEY_HANGUEL},	// IME Hanguel mode (maintained for compatibility use {"KEY_", irr::KEY_HANGUL)
	{"KEY_HANGUL", irr::KEY_HANGUL},	// IME Hangul mode
	{"KEY_JUNJA", irr::KEY_JUNJA},		// IME Junja mode
	{"KEY_FINAL", irr::KEY_FINAL},		// IME final mode
	{"KEY_HANJA", irr::KEY_HANJA},		// IME Hanja mode
	{"KEY_KANJI", irr::KEY_KANJI},		// IME Kanji mode
	{"KEY_ESCAPE", irr::KEY_ESCAPE },	// ESC key
	{"KEY_ESCAPE", irr::KEY_CONVERT},	// IME convert
	{"KEY_NONCONVERT", irr::KEY_NONCONVERT },	// IME nonconvert
	{"KEY_ACCEPT", irr::KEY_ACCEPT },	// IME accept
	{"KEY_MODECHANGE", irr::KEY_MODECHANGE },	// IME mode change request
	{"KEY_SPACE", irr::KEY_SPACE},		// SPACEBAR
	{"KEY_PRIOR", irr::KEY_PRIOR},		// PAGE UP key
	{"KEY_NEXT", irr::KEY_NEXT},		// PAGE DOWN key
	{"KEY_END", irr::KEY_END},		// END key
	{"KEY_HOME", irr::KEY_HOME},		// HOME key
	{"KEY_LEFT", irr::KEY_LEFT},		// LEFT ARROW key
	{"KEY_UP", irr::KEY_UP },		// UP ARROW key
	{"KEY_RIGHT", irr::KEY_RIGHT},		// RIGHT ARROW key
	{"KEY_DOWN", irr::KEY_DOWN},		// DOWN ARROW key
	{"KEY_SELECT", irr::KEY_SELECT },	// SELECT key
	{"KEY_PRINT", irr::KEY_PRINT},		// PRINT key
	{"KEY_EXECUT", irr::KEY_EXECUT },	// EXECUTE key
	{"KEY_SNAPSHOT", irr::KEY_SNAPSHOT},	// PRINT SCREEN key
	{"KEY_INSERT", irr::KEY_INSERT },	// INS key
	{"KEY_DELETE", irr::KEY_DELETE },	// DEL key
	{"KEY_HELP", irr::KEY_HELP},		// HELP key
	{"KEY_KEY_0", irr::KEY_KEY_0},		// 0 key
	{"KEY_KEY_1", irr::KEY_KEY_1},		// 1 key
	{"KEY_KEY_2", irr::KEY_KEY_2},		// 2 key
	{"KEY_KEY_3", irr::KEY_KEY_3},		// 3 key
	{"KEY_KEY_4", irr::KEY_KEY_4},		// 4 key
	{"KEY_KEY_5", irr::KEY_KEY_5},		// 5 key
	{"KEY_KEY_6", irr::KEY_KEY_6},		// 6 key
	{"KEY_KEY_7", irr::KEY_KEY_7},		// 7 key
	{"KEY_KEY_8", irr::KEY_KEY_8},		// 8 key
	{"KEY_KEY_9", irr::KEY_KEY_9},		// 9 key
	{"KEY_KEY_A", irr::KEY_KEY_A},		// A key
	{"KEY_KEY_B", irr::KEY_KEY_B},		// B key
	{"KEY_KEY_C", irr::KEY_KEY_C},		// C key
	{"KEY_KEY_D", irr::KEY_KEY_D},		// D key
	{"KEY_KEY_E", irr::KEY_KEY_E},		// E key
	{"KEY_KEY_F", irr::KEY_KEY_F},		// F key
	{"KEY_KEY_G", irr::KEY_KEY_G},		// G key
	{"KEY_KEY_H", irr::KEY_KEY_H},		// H key
	{"KEY_KEY_I", irr::KEY_KEY_I},		// I key
	{"KEY_KEY_J", irr::KEY_KEY_J},		// J key
	{"KEY_KEY_K", irr::KEY_KEY_K},		// K key
	{"KEY_KEY_L", irr::KEY_KEY_L},		// L key
	{"KEY_KEY_M", irr::KEY_KEY_M},		// M key
	{"KEY_KEY_N", irr::KEY_KEY_N},		// N key
	{"KEY_KEY_O", irr::KEY_KEY_O},		// O key
	{"KEY_KEY_P", irr::KEY_KEY_P},		// P key
	{"KEY_KEY_Q", irr::KEY_KEY_Q},		// Q key
	{"KEY_KEY_R", irr::KEY_KEY_R},		// R key
	{"KEY_KEY_S", irr::KEY_KEY_S},		// S key
	{"KEY_KEY_T", irr::KEY_KEY_T},		// T key
	{"KEY_KEY_U", irr::KEY_KEY_U},		// U key
	{"KEY_KEY_V", irr::KEY_KEY_V},		// V key
	{"KEY_KEY_W", irr::KEY_KEY_W},		// W key
	{"KEY_KEY_X", irr::KEY_KEY_X},		// X key
	{"KEY_KEY_Y", irr::KEY_KEY_Y},		// Y key
	{"KEY_KEY_Z", irr::KEY_KEY_Z},		// Z key
	{"KEKEY_LWINY_", irr::KEY_LWIN},	// Left Windows key (Microsoft� Natural� keyboard)
	{"KEY_RWIN", irr::KEY_RWIN},		// Right Windows key (Natural keyboard)
	{"KEY_APPS", irr::KEY_APPS},		// Applications key (Natural keyboard)
	{"KEY_SLEEP", irr::KEY_SLEEP},		// Computer Sleep key
	{"KEY_NUMPAD0", irr::KEY_NUMPAD0},	// Numeric keypad 0 key
	{"KEY_NUMPAD1", irr::KEY_NUMPAD1},	// Numeric keypad 1 key
	{"KEY_NUMPAD2", irr::KEY_NUMPAD2},	// Numeric keypad 2 key
	{"KEY_NUMPAD3", irr::KEY_NUMPAD3},	// Numeric keypad 3 key
	{"KEY_NUMPAD4", irr::KEY_NUMPAD4},	// Numeric keypad 4 key
	{"KEY_NUMPAD5", irr::KEY_NUMPAD5},	// Numeric keypad 5 key
	{"KEY_NUMPAD6", irr::KEY_NUMPAD6},	// Numeric keypad 6 key
	{"KEY_NUMPAD7", irr::KEY_NUMPAD7},	// Numeric keypad 7 key
	{"KEY_NUMPAD8", irr::KEY_NUMPAD8},	// Numeric keypad 8 key
	{"KEY_NUMPAD9", irr::KEY_NUMPAD9},	// Numeric keypad 9 key
	{"KEY_MULTIPLY", irr::KEY_MULTIPLY},	// Multiply key
	{"KEY_ADD", irr::KEY_ADD},		// Add key
	{"KEY_SEPARATOR", irr::KEY_SEPARATOR},	// Separator key
	{"KEY_SUBTRACT", irr::KEY_SUBTRACT},	// Subtract key
	{"KEY_DECIMAL", irr::KEY_DECIMAL},	// Decimal key
	{"KEY_DIVIDE", irr::KEY_DIVIDE },	// Divide key
	{"KEY_F1", irr::KEY_F1 },		// F1 key
	{"KEY_F2", irr::KEY_F2 },		// F2 key
	{"KEY_F3", irr::KEY_F3 },		// F3 key
	{"KEY_F4", irr::KEY_F4 },		// F4 key
	{"KEY_F5", irr::KEY_F5 },		// F5 key
	{"KEY_F6", irr::KEY_F6 },		// F6 key
	{"KEY_F7", irr::KEY_F7 },		// F7 key
	{"KEY_F8", irr::KEY_F8 },		// F8 key
	{"KEY_F9", irr::KEY_F9 },		// F9 key
	{"KEY_F10", irr::KEY_F10},		// F10 key
	{"KEY_F11", irr::KEY_F11},		// F11 key
	{"KEY_F12", irr::KEY_F12},		// F12 key
	{"KEY_F13", irr::KEY_F13},		// F13 key
	{"KEY_F14", irr::KEY_F14},		// F14 key
	{"KEY_F15", irr::KEY_F15},		// F15 key
	{"KEY_F16", irr::KEY_F16},		// F16 key
	{"KEY_F17", irr::KEY_F17},		// F17 key
	{"KEY_F18", irr::KEY_F18},		// F18 key
	{"KEY_F19", irr::KEY_F19},		// F19 key
	{"KEY_F20", irr::KEY_F20},		// F20 key
	{"KEY_F21", irr::KEY_F21},		// F21 key
	{"KEY_F22", irr::KEY_F22},		// F22 key
	{"KEY_F23", irr::KEY_F23},		// F23 key
	{"KEY_F24", irr::KEY_F24},		// F24 key
	{"KEY_NUMLOCK", irr::KEY_NUMLOCK},	// NUM LOCK key
	{"KEY_SCROLL", irr::KEY_SCROLL},	// SCROLL LOCK key
	{"KEY_LSHIFT", irr::KEY_LSHIFT},	// Left SHIFT key
	{"KEY_RSHIFT", irr::KEY_RSHIFT},	// Right SHIFT key
	{"KEY_LCONTROL", irr::KEY_LCONTROL},	// Left CONTROL key
	{"KEY_RCONTROL", irr::KEY_RCONTROL},	// Right CONTROL key
	{"KEY_LMENU", irr::KEY_LMENU},		// Left MENU key
	{"KEY_RMENU", irr::KEY_RMENU},		// Right MENU key
	{"KEY_OEM_1", irr::KEY_OEM_1},		// for US ";:"
	{"KEY_PLUS", irr::KEY_PLUS},		// Plus Key"+"
	{"KEY_COMMA", irr::KEY_COMMA},		// Comma Key","
	{"KEY_MINUS", irr::KEY_MINUS},		// Minus Key"-"
	{"KEY_PERIOD", irr::KEY_PERIOD},	// Period Key "."
	{"KEY_OEM_2", irr::KEY_OEM_2},		// for US "/?"
	{"KEY_OEM_3", irr::KEY_OEM_3},		// for US "`~"
	{"KEY_OEM_4", irr::KEY_OEM_4},		// for US "[{"
	{"KEY_OEM_5", irr::KEY_OEM_5},		// for US "\|"
	{"KEY_OEM_6", irr::KEY_OEM_6},		// for US "]}"
	{"KEY_OEM_7", irr::KEY_OEM_7},		// for US "'""
	{"KEY_OEM_8", irr::KEY_OEM_8},		// None
	{"KEY_OEM_AX", irr::KEY_OEM_AX },	// for Japan "AX"
	{"KEY_OEM_102", irr::KEY_OEM_102},	// "<>" or "\|"
	{"KEY_ATTN", irr::KEY_ATTN},		// Attn key
	{"KEY_CRSEL", irr::KEY_CRSEL},		// CrSel key
	{"KEY_EXSEL", irr::KEY_EXSEL},		// ExSel key
	{"KEY_EREOF", irr::KEY_EREOF},		// Erase EOF key
	{"KEY_PLAY", irr::KEY_PLAY},		// Play key
	{"KEY_ZOOM", irr::KEY_ZOOM},		// Zoom key
	{"KEY_PA1", irr::KEY_PA1},		// PA1 key
	{"KEY_OEM_CLEAR", irr::KEY_OEM_CLEAR},	// Clear key
	{"KEY_KEY_CODES_COUNT", irr::KEY_KEY_CODES_COUNT},	// this is not a key, but the amount of keycodes there are.
};
