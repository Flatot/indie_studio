//
// EPITECH PROJECT, 2018
// Config.cpp
// File description:
// Config implementation
//

#include "Config.hpp"

bbm::Config::Config() :

	_fullscreen(false),
	_screenWidth(1280),
	_screenHeight(720),
	_volumeGeneral(50),
	_volumeEffect(50)
{
	_playerConfig.push_back(PlayerConfig(bbm::Entities::PLAYER_1));
	_playerConfig.push_back(PlayerConfig(bbm::Entities::PLAYER_2));
	_playerConfig.push_back(PlayerConfig(bbm::Entities::PLAYER_3));
	_playerConfig.push_back(PlayerConfig(bbm::Entities::PLAYER_4));
	loadConfig();
	saveConfig();
}

void bbm::Config::saveConfig()
{
	std::ofstream myfile;
	myfile.open("Config.cfg");
	if (myfile.is_open() == false)
		return;
	myfile << *this;
	myfile.close();
}

void bbm::Config::loadConfig()
{
	std::ifstream file("Config.cfg");
	std::string line;
	std::string delimiter = ":";

	if (!file)
		return;
	while (std::getline(file, line))
		this->handleLine(line, delimiter);
	_playerConfig[0].loadConfig();
	_playerConfig[1].loadConfig();
	_playerConfig[2].loadConfig();
	_playerConfig[3].loadConfig();
}

void bbm::Config::handleLine(std::string line, std::string delimiter)
{
	size_t pos = 0;
	std::string firstTok;
	std::string token;
	std::string::size_type sz;

	pos = line.find(delimiter);
	token = line.substr(0, pos);
	firstTok = token;
	line.erase(0, pos + delimiter.length());
	doWithTokens(firstTok, line);
}

void bbm::Config::doWithTokens(std::string tok1, std::string tok2)
{
	std::string::size_type sz;

	if (tok1.compare("FULLSCREEN") == 0)
		_fullscreen = tok2.compare("false");
	if (tok1.compare("SCREEN_WIDTH") == 0)
		_screenWidth = std::stoi(tok2, &sz);
	if (tok1.compare("SCREEN_HEIGHT") == 0)
		_screenHeight = std::stoi(tok2, &sz);
	if (tok1.compare("VOLUME_GENERAL") == 0)
		_volumeGeneral = std::stoi(tok2, &sz);
	if (tok1.compare("VOLUME_EFFECT") == 0)
		_volumeEffect = std::stoi(tok2, &sz);
}

int bbm::Config::getScreenWidth() const
{
	return _screenWidth;
}

int bbm::Config::getScreenHeight() const
{
	return _screenHeight;
}

int bbm::Config::getVolumeEffect() const
{
	return _volumeEffect;
}

int bbm::Config::getVolumeGeneral() const
{
	return _volumeGeneral;
}

bbm::PlayerConfig bbm::Config::getPlayerConfig(int idx) const
{
	return _playerConfig[idx];
}

bbm::PlayerConfig &bbm::Config::getPlayerConfig(int idx)
{
	return _playerConfig[idx];
}

bool bbm::Config::getFullscreen() const
{
	return _fullscreen;
}

std::ostream& operator<< (std::ostream& stream, bbm::Config const& conf)
{
	stream << "Config" << std::endl;
	stream << "FULLSCREEN:" << std::boolalpha << conf.getFullscreen() << std::endl;
	stream << "SCREEN_WIDTH:" << std::to_string(conf.getScreenWidth()) << std::endl;
	stream << "SCREEN_HEIGHT:" << std::to_string(conf.getScreenHeight()) << std::endl;
	stream << "VOLUME_GENERAL:" << std::to_string(conf.getVolumeGeneral()) << std::endl;
	stream << "VOLUME_EFFECT:" << std::to_string(conf.getVolumeEffect()) << std::endl;
	stream << conf.getPlayerConfig(0);
	stream << conf.getPlayerConfig(1);
	stream << conf.getPlayerConfig(2);
	stream << conf.getPlayerConfig(3);
	return stream;
}
