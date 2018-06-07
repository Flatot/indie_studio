//
// EPITECH PROJECT, 2018
// PlayerConfig.cpp
// File description:
// PlayerConfig implementation
//

#include "PlayerConfig.hpp"

bbm::PlayerConfig::PlayerConfig(bbm::Entites entity) : _entity(entity)
{
	switch(entity) {
		case bbm::Entites::PLAYER_1:
			_name = "PLAYER_1";
			_keys["PUT_BOMB"] = irr::KEY_SPACE;
			_keys["UP"] = irr::KEY_UP;
			_keys["DOWN"] = irr::KEY_DOWN;
			_keys["RIGHT"] = irr::KEY_RIGHT;
			_keys["LEFT"] = irr::KEY_LEFT;
			break;
		case bbm::Entites::PLAYER_2:
			_name = "PLAYER_2";
			_keys["PUT_BOMB"] = irr::KEY_KEY_E;
			_keys["UP"] = irr::KEY_KEY_Z;
			_keys["DOWN"] = irr::KEY_KEY_Q;
			_keys["RIGHT"] = irr::KEY_KEY_S;
			_keys["LEFT"] = irr::KEY_KEY_D;
			break;
		case bbm::Entites::PLAYER_3:
			_name = "PLAYER_3";
			_keys["PUT_BOMB"] = irr::KEY_KEY_P;
			_keys["UP"] = irr::KEY_KEY_O;
			_keys["DOWN"] = irr::KEY_KEY_L;
			_keys["RIGHT"] = irr::KEY_KEY_K;
			_keys["LEFT"] = irr::KEY_KEY_M;
			break;
		case bbm::Entites::PLAYER_4:
			_name = "PLAYER_4";
			_keys["PUT_BOMB"] = irr::KEY_KEY_U;
			_keys["UP"] = irr::KEY_KEY_Y;
			_keys["DOWN"] = irr::KEY_KEY_H;
			_keys["RIGHT"] = irr::KEY_KEY_J;
			_keys["LEFT"] = irr::KEY_KEY_G;
			break;
	}
}

void bbm::PlayerConfig::loadConfig()
{
	std::ifstream infile("Config.cfg");
	std::string line;
	std::string delimiter = ":";
	bool start = false;

	while (std::getline(infile, line))
	{
		start = this->handleLine(line, delimiter, start);
	}
}

bool bbm::PlayerConfig::handleLine(std::string line, std::string delimiter, bool start)
{
	size_t pos = 0;
	std::string token;
	std::string firstTok;
	std::string::size_type sz;

	pos = line.find(delimiter);
	token = line.substr(0, pos);
	if (start == false) {
		return (token.compare(this->_name) == 0);
	}
	firstTok = token;
	line.erase(0, pos + delimiter.length());
	if (this->isValuable(firstTok)) {
		this->_keys[firstTok] = this->stringToCode(line);
		return true;
	}
	return false;
}

bool bbm::PlayerConfig::isValuable(std::string str)
{
	for (int i = 0; i < 5; i++) {
		if (valuableControl[i].compare(str) == 0)
			return true;
	}
	return false;
}

std::map<std::string, irr::EKEY_CODE> bbm::PlayerConfig::getMap() const
{
	return _keys;
}

std::string bbm::PlayerConfig::getName() const
{
	return _name;
}

irr::EKEY_CODE bbm::PlayerConfig::stringToCode(std::string str) const
{
	for(int j = 0; keysparse[j].keycode != irr::KEY_KEY_CODES_COUNT; j++) {
		if (keysparse[j].str.compare(str) == 0)
			return keysparse[j].keycode;
	}
	return irr::KEY_KEY_CODES_COUNT;
}

std::string bbm::PlayerConfig::codeToString(irr::EKEY_CODE code) const
{
	for(int j = 0; keysparse[j].keycode != irr::KEY_KEY_CODES_COUNT; j++) {
		if (keysparse[j].keycode == code)
			return keysparse[j].str;
	}
	return "NULL";
}

std::ostream& operator<< (std::ostream& stream, bbm::PlayerConfig const& playerConf) {
	auto confMap = playerConf.getMap();
	stream << playerConf.getName() << ":" << std::endl;
	for (const auto& elem : confMap)
	{
		stream << elem.first << ":" << playerConf.codeToString(elem.second) << std::endl;
	}
	return stream;
}