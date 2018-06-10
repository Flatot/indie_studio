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
		Audio(int generalVolume, int effectVolume);

		void playMenuMusic();
		void stopMenuMusic();
		void playInGameMusic();
		void stopInGameMusic();

		void playBombeExplode();
		void playPlayerDie();
		void playError();
		void playVolumeUp();
		void playVolumeDown();

		int getEffectVolume();
		int getGeneralVolume();
		void setEffectVolume(int volume);
		void setGeneralVolume(int volume);


	private:
		sf::Music _menuPlayer;
		sf::Music _inGamePlayer;
		sf::SoundBuffer _bBombExplode;
		sf::SoundBuffer _bPlayerDie;
		sf::SoundBuffer _bError;
		sf::SoundBuffer _bVolumeUp;
		sf::SoundBuffer _bVolumeDown;

		sf::Sound _soundEffect;
	};
}
