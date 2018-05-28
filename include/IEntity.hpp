//
// EPITECH PROJECT, 2018
// IEntity.hpp
// File description:
// IEntity interface
//

#pragma once

namespace bbm {
	class Match;

	enum Entites{
		BLANK = 0,
		PLAYER_1 = 1,
		PLAYER_2 = 2,
		PLAYER_3 = 4,
		PLAYER_4 = 8,
		UNBREAKABLE_BLOCK = 16,
		BREAKABLE_BLOCK = 32,
		BOMB = 64,
		BONUS = 128
	};

	class IEntity {
	public:
		IEntity(Match &match, float x, float y);
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
