//
// EPITECH PROJECT, 2018
// indie
// File description:
// corners calculation
//

#pragma once

#include "IMenu.hpp"

namespace bbm {
	class Corners {
		public:
			static ButtonInfos getCenteredVertical(const irr::core::dimension2du& screenSize, bbm::Position pos, const irr::core::dimension2du& buttonSize);
			static ButtonInfos getCenteredHorizontal(const irr::core::dimension2du& screenSize, bbm::Position pos, const irr::core::dimension2du& buttonSize);
			static ButtonInfos getCenteredAudio(const irr::core::dimension2du& screenSize, bbm::PositionMultiple pos, const irr::core::dimension2du& buttonSize);

		protected:
		private:
	};
}
