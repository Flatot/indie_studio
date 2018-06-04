//
// EPITECH PROJECT, 2018
// IEntity.hpp
// File description:
// IEntity interface
//

#pragma once

#include <iostream>

#include "IMeshSceneNode.h"

namespace bbm {
	class Match;

	enum Entities{
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
		IEntity(Match &match, float x, float z, bool isTraversable);
		~IEntity();
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		int getIdEntity();

		void setCoefs(float coefX, float coefY, float coefZ);
		void setMesh(irr::scene::IMeshSceneNode *mesh);
		void setTexturePath(std::string &path);
		irr::scene::IMeshSceneNode *getMesh();
	protected:


		Match &_match;
		bool _isTraversable;
		float _x;
		float _z;
		std::string _meshPath;
		std::string _texturePath;
		float _coefX;
		float _coefY;
		float _coefZ;
		irr::scene::IMeshSceneNode *_mesh;
		Entities _idEntity;
	};
}
