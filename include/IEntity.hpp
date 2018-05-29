//
// EPITECH PROJECT, 2018
// IEntity.hpp
// File description:
// IEntity interface
//

#pragma once

#include <iostream>

namespace bbm {
	class Match;

	enum Entites{
		BLANK = 0,
		UNBREAKABLE_BLOCK = 1,
		BREAKABLE_BLOCK = 2,
		PLAYER_1 = 4,
		PLAYER_2 = 8,
		PLAYER_3 = 16,
		PLAYER_4 = 32,
		BOMB = 64,
		BONUS = 128
	};

	class IEntity {
	public:
		IEntity(Match &match, float x, float y, bool isTraversable);
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;

	protected:
		Match &_match;
		bool _isTraversable;
		float _x;
		float _y;
	};
}
