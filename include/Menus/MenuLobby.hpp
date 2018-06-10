//
// EPITECH PROJECT, 2018
// indie
// File description:
// lobby menu
//

#pragma once

#include "irrlicht.h"
#include <vector>
#include <iostream>
#include "Definer.hpp"

namespace bbm {
	class Game;

	class MenuLobby {
		public:
			MenuLobby(Game &game);
			~MenuLobby();
			void draw(std::vector<AttrEntity> attrs,
				std::vector<TeamColor> teams);
			void setVisible(bool visible);
			void initPilars();
			void initNinjas();
			void initTextures();

		protected:
		private:
			Game	&_game;
			irr::scene::ICameraSceneNode *_camera;
			std::vector<irr::scene::ISceneNode *> _blocks;
			std::vector<irr::scene::IAnimatedMeshSceneNode *>
				_ninjas;
			std::vector<irr::video::ITexture *> _textures;
			irr::video::ITexture *_skyTexture;
			irr::scene::ISceneNode *_skyBox;
	};
}