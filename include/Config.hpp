//
// EPITECH PROJECT, 2018
// Config.hpp
// File description:
// Config class
//

#pragma once

namespace bbm {
	class Config {
	public:
		Config();
		void loadConfig();
		int getScreenWidth();
		int getScreenHeight();
		bool getFullscreen();

	private:
		bool _fullscreen;
		int _screenWidth;
		int _screenHeight;
		int _volumeGeneral;
		int _volumeEffect;
		//PlayerConfig _playerConfig[4]
	};
}
