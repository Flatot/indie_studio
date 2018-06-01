//
// EPITECH PROJECT, 2018
// Ia.hpp
// File description:
// ia class
//

#pragma once

#include <vector>
#include "IPlayer.hpp"
#include "Match.hpp"

namespace bbm {
	class Ia : public IPlayer {
	public:
		Ia(Match &match, float x, float y);
		~IA();
		virtual void spawn() override;
		virtual void die() override;
		virtual void update() override;
	protected:
		void	analysMap();
	private:
		std::vector<std::vector<int> >	_direction;
		
	};
}
