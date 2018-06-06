//
// EPITECH PROJECT, 2018
// Config.hpp
// File description:
// Config class
//

#pragma once
#include <vector>
#include "PlayerConfig.hpp"


namespace bbm {
	class Config {
	public:
		Config();
		void loadConfig();
		void saveConfig();
		int getScreenWidth() const;
		int getScreenHeight() const;
		int getVolumeEffect() const;
		int getVolumeGeneral() const;
		bool getFullscreen() const;
		bbm::PlayerConfig getPlayerConfigs(int idx) const;

	private:
		bool _fullscreen;
		int _screenWidth;
		int _screenHeight;
		int _volumeGeneral;
		int _volumeEffect;
		std::vector<bbm::PlayerConfig> _playerConfig;
		void doWithTokens(std::string tok1, std::string tok2);
		void handleLine(std::string line, std::string delimiter);
	};
}
std::ostream& operator<< (std::ostream& stream, bbm::Config const& conf);

