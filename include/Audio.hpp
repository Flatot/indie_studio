//
// EPITECH PROJECT, 2018
// Audio.hpp
// File description:
// Audio class
//

#pragma once

#include "SFML/Audio.hpp"

namespace bbm {
	class Audio {
	public:
		Audio();
	private:
		sf::SoundBuffer bMenus;
		sf::SoundBuffer bInGame;
		sf::SoundBuffer bBombExplode;
		sf::SoundBuffer bPlayerDie;
		sf::SoundBuffer bError;
		sf::SoundBuffer bVolumeUp;
		sf::SoundBuffer bVolumeDown;

		sf::Sound soundGeneral;
		sf::Sound soundEffect;
	};
}
