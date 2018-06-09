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
		int	getScreenWidth() const;
		int	getScreenHeight() const;
		void	setScreenWidth(int);
		void	setScreenHeight(int);
		bool getFullscreen();
		int	getVolumeGeneral() const;
		void	setVolumeGeneral(int);
		int	getVolumeEffect() const;
		void	setVolumeEffect(int);

	private:
		bool _fullscreen;
		int _screenWidth;
		int _screenHeight;
		int _volumeGeneral;
		int _volumeEffect;
		//PlayerConfig _playerConfig[4]
	};
}
