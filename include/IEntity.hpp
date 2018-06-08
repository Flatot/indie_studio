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
		EXPLOSION = 128,
		BONUS = 256
	};

	enum Type {
		WALLPASS = 1,
		SPEEDUP = 2,
		BOMBUP = 4,
		FIREUP = 8
	};

	class IEntity {
	public:
		IEntity(Match &match, float z, float x, bool isTraversable);
		virtual ~IEntity();
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		int getIdEntity() const;
		int getPosX() const;
		int getPosZ() const;
		bool is(Entities entity) const;

		void setCoefs(float coefX, float coefY, float coefZ);
		void setMesh(irr::scene::ISceneNode *mesh);
		void setTexturePath(std::string &path);
		Type getType() const;
		irr::scene::ISceneNode *getMesh();

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
		irr::scene::ISceneNode *_mesh;
		Entities _idEntity;
		Type _type;
	};
}
