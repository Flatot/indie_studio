//
// EPITECH PROJECT, 2018
// indie
// File description:
// corners calculation
//

#pragma once

#include <iostream>
#include "irrlicht.h"
#include "Definer.hpp"

namespace bbm {
	class Corners {
		public:
			static ButtonInfos getCenteredVertical(const
			irr::core::dimension2du&, bbm::Position,
			const irr::core::dimension2du&);
			static ButtonInfos getCenteredHorizontal(const
			irr::core::dimension2du&, bbm::Position,
			const irr::core::dimension2du&);
			static ButtonInfos getCenteredAudio(const
			irr::core::dimension2du&, bbm::PositionMultiple,
			const irr::core::dimension2du&);

		protected:
		private:
	};
}
