//
// EPITECH PROJECT, 2018
// indie
// File description:
// defining many structs and enums
//

#pragma once

namespace bbm {
	struct	ButtonInfos {
		int	startX;
		int	startY;
		int	endX;
		int	endY;
	};

	struct Position {
		int	index;
		int	total;
	};

	struct PositionMultiple {
		int	index;
		int	total;
		int	topIndex;
		int	topTotal;
	};

	enum IdButton {
		GUI_BUTTON_QUIT = 101,
		GUI_BUTTON_SAVEQUIT,
		GUI_BUTTON_SETTINGS,
		GUI_BUTTON_VIDEO,
		GUI_BUTTON_CONTROLS,
		GUI_BUTTON_AUDIO,
		GUI_BUTTON_RESUME,
		GUI_BUTTON_END,
		GUI_BUTTON_CONTINUE,
		GUI_BUTTON_NEWGAME,
		GUI_BUTTON_BACK,
		GUI_BUTTON_SOUNDS,
		GUI_BUTTON_EFFECTS,
		GUI_BUTTON_RESOLUTION,
		GUI_BUTTON_PLAYER,
		GUI_BUTTON_FULLSCREEN,
		GUI_BUTTON_FORWARD,
		GUI_BUTTON_BACKWARD,
		GUI_BUTTON_LEFT,
		GUI_BUTTON_RIGHT,
		GUI_BUTTON_BOMB,
		GUI_BUTTON_P1,
		GUI_BUTTON_P2,
		GUI_BUTTON_P3,
		GUI_BUTTON_P4,
		GUI_BUTTON_START
	};

	enum AttrEntity {
		ATTR_NONE,
		ATTR_PLAYER,
		ATTR_AI
	};

	enum TeamColor {
		TEAM_BLUE,
		TEAM_RED,
		TEAM_GREEN,
		TEAM_PURPLE
	};

	struct pkeys {
		const wchar_t	text[14];
		irr::EKEY_CODE	code;
	};

	struct playerctrl {
		irr::EKEY_CODE	forward;
		irr::EKEY_CODE	left;
		irr::EKEY_CODE	backward;
		irr::EKEY_CODE	right;
		irr::EKEY_CODE	bomb;
	};
}

const bbm::pkeys	keymsg[] = {
	{L"LBUTTON", irr::KEY_LBUTTON},
	{L"RBUTTON", irr::KEY_RBUTTON},
	{L"CANCEL", irr::KEY_CANCEL},
	{L"MBUTTON", irr::KEY_MBUTTON},
	{L"XBUTTON1", irr::KEY_XBUTTON1},
	{L"XBUTTON2", irr::KEY_XBUTTON2},
	{L"BACK", irr::KEY_BACK},
	{L"TAB", irr::KEY_TAB},
	{L"CLEAR", irr::KEY_CLEAR},
	{L"RETURN", irr::KEY_RETURN},
	{L"SHIFT", irr::KEY_SHIFT},
	{L"CONTROL", irr::KEY_CONTROL},
	{L"MENU", irr::KEY_MENU},
	{L"PAUSE", irr::KEY_PAUSE},
	{L"CAPITAL", irr::KEY_CAPITAL},
	{L"KANA", irr::KEY_KANA},
	{L"HANGUEL", irr::KEY_HANGUEL},
	{L"HANGUL", irr::KEY_HANGUL},
	{L"JUNJA", irr::KEY_JUNJA},
	{L"FINAL", irr::KEY_FINAL},
	{L"HANJA", irr::KEY_HANJA},
	{L"KANJI", irr::KEY_KANJI},
	{L"ESCAPE", irr::KEY_ESCAPE},
	{L"CONVERT", irr::KEY_CONVERT},
	{L"NONCONVERT", irr::KEY_NONCONVERT},
	{L"ACCEPT", irr::KEY_ACCEPT},
	{L"MODECHANGE", irr::KEY_MODECHANGE},
	{L"SPACE", irr::KEY_SPACE},
	{L"PRIOR", irr::KEY_PRIOR},
	{L"NEXT", irr::KEY_NEXT},
	{L"END", irr::KEY_END},
	{L"HOME", irr::KEY_HOME},
	{L"LEFT", irr::KEY_LEFT},
	{L"UP", irr::KEY_UP},
	{L"RIGHT", irr::KEY_RIGHT},
	{L"DOWN", irr::KEY_DOWN},
	{L"SELECT", irr::KEY_SELECT},
	{L"PRINT", irr::KEY_PRINT},
	{L"EXECUT", irr::KEY_EXECUT},
	{L"SNAPSHOT", irr::KEY_SNAPSHOT},
	{L"INSERT", irr::KEY_INSERT},
	{L"DELETE", irr::KEY_DELETE},
	{L"HELP", irr::KEY_HELP},
	{L"KEY_0", irr::KEY_KEY_0},
	{L"KEY_1", irr::KEY_KEY_1},
	{L"KEY_2", irr::KEY_KEY_2},
	{L"KEY_3", irr::KEY_KEY_3},
	{L"KEY_4", irr::KEY_KEY_4},
	{L"KEY_5", irr::KEY_KEY_5},
	{L"KEY_6", irr::KEY_KEY_6},
	{L"KEY_7", irr::KEY_KEY_7},
	{L"KEY_8", irr::KEY_KEY_8},
	{L"KEY_9", irr::KEY_KEY_9},
	{L"KEY_A", irr::KEY_KEY_A},
	{L"KEY_B", irr::KEY_KEY_B},
	{L"KEY_C", irr::KEY_KEY_C},
	{L"KEY_D", irr::KEY_KEY_D},
	{L"KEY_E", irr::KEY_KEY_E},
	{L"KEY_F", irr::KEY_KEY_F},
	{L"KEY_G", irr::KEY_KEY_G},
	{L"KEY_H", irr::KEY_KEY_H},
	{L"KEY_I", irr::KEY_KEY_I},
	{L"KEY_J", irr::KEY_KEY_J},
	{L"KEY_K", irr::KEY_KEY_K},
	{L"KEY_L", irr::KEY_KEY_L},
	{L"KEY_M", irr::KEY_KEY_M},
	{L"KEY_N", irr::KEY_KEY_N},
	{L"KEY_O", irr::KEY_KEY_O},
	{L"KEY_P", irr::KEY_KEY_P},
	{L"KEY_Q", irr::KEY_KEY_Q},
	{L"KEY_R", irr::KEY_KEY_R},
	{L"KEY_S", irr::KEY_KEY_S},
	{L"KEY_T", irr::KEY_KEY_T},
	{L"KEY_U", irr::KEY_KEY_U},
	{L"KEY_V", irr::KEY_KEY_V},
	{L"KEY_W", irr::KEY_KEY_W},
	{L"KEY_X", irr::KEY_KEY_X},
	{L"KEY_Y", irr::KEY_KEY_Y},
	{L"KEY_Z", irr::KEY_KEY_Z},
	{L"LWIN", irr::KEY_LWIN},
	{L"RWIN", irr::KEY_RWIN},
	{L"APPS", irr::KEY_APPS},
	{L"SLEEP", irr::KEY_SLEEP},
	{L"NUMPAD0", irr::KEY_NUMPAD0},
	{L"NUMPAD1", irr::KEY_NUMPAD1},
	{L"NUMPAD2", irr::KEY_NUMPAD2},
	{L"NUMPAD3", irr::KEY_NUMPAD3},
	{L"NUMPAD4", irr::KEY_NUMPAD4},
	{L"NUMPAD5", irr::KEY_NUMPAD5},
	{L"NUMPAD6", irr::KEY_NUMPAD6},
	{L"NUMPAD7", irr::KEY_NUMPAD7},
	{L"NUMPAD8", irr::KEY_NUMPAD8},
	{L"NUMPAD9", irr::KEY_NUMPAD9},
	{L"MULTIPLY", irr::KEY_MULTIPLY},
	{L"ADD", irr::KEY_ADD},
	{L"SEPARATOR", irr::KEY_SEPARATOR},
	{L"SUBTRACT", irr::KEY_SUBTRACT},
	{L"DECIMAL", irr::KEY_DECIMAL},
	{L"DIVIDE", irr::KEY_DIVIDE},
	{L"F1", irr::KEY_F1},
	{L"F2", irr::KEY_F2},
	{L"F3", irr::KEY_F3},
	{L"F4", irr::KEY_F4},
	{L"F5", irr::KEY_F5},
	{L"F6", irr::KEY_F6},
	{L"F7", irr::KEY_F7},
	{L"F8", irr::KEY_F8},
	{L"F9", irr::KEY_F9},
	{L"F10", irr::KEY_F10},
	{L"F11", irr::KEY_F11},
	{L"F12", irr::KEY_F12},
	{L"F13", irr::KEY_F13},
	{L"F14", irr::KEY_F14},
	{L"F15", irr::KEY_F15},
	{L"F16", irr::KEY_F16},
	{L"F17", irr::KEY_F17},
	{L"F18", irr::KEY_F18},
	{L"F19", irr::KEY_F19},
	{L"F20", irr::KEY_F20},
	{L"F21", irr::KEY_F21},
	{L"F22", irr::KEY_F22},
	{L"F23", irr::KEY_F23},
	{L"F24", irr::KEY_F24},
	{L"NUMLOCK", irr::KEY_NUMLOCK},
	{L"SCROLL", irr::KEY_SCROLL},
	{L"LSHIFT", irr::KEY_LSHIFT},
	{L"RSHIFT", irr::KEY_RSHIFT},
	{L"LCONTROL", irr::KEY_LCONTROL},
	{L"RCONTROL", irr::KEY_RCONTROL},
	{L"LMENU", irr::KEY_LMENU},
	{L"RMENU", irr::KEY_RMENU},
	{L"OEM_1", irr::KEY_OEM_1},
	{L"PLUS", irr::KEY_PLUS},
	{L"COMMA", irr::KEY_COMMA},
	{L"MINUS", irr::KEY_MINUS},
	{L"PERIOD", irr::KEY_PERIOD},
	{L"OEM_2", irr::KEY_OEM_2},
	{L"OEM_3", irr::KEY_OEM_3},
	{L"OEM_4", irr::KEY_OEM_4},
	{L"OEM_5", irr::KEY_OEM_5},
	{L"OEM_6", irr::KEY_OEM_6},
	{L"OEM_7", irr::KEY_OEM_7},
	{L"OEM_8", irr::KEY_OEM_8},
	{L"OEM_AX", irr::KEY_OEM_AX},
	{L"OEM_102", irr::KEY_OEM_102},
	{L"ATTN", irr::KEY_ATTN},
	{L"CRSEL", irr::KEY_CRSEL},
	{L"EXSEL", irr::KEY_EXSEL},
	{L"EREOF", irr::KEY_EREOF},
	{L"PLAY", irr::KEY_PLAY},
	{L"ZOOM", irr::KEY_ZOOM},
	{L"PA1", irr::KEY_PA1},
	{L"OEM_CLEAR", irr::KEY_OEM_CLEAR},
	{L"", irr::KEY_KEY_CODES_COUNT}
};
