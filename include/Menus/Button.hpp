//
// EPITECH PROJECT, 2018
// indie
// File description:
// button header
//

#pragma once

#include "irrlicht.h"
#include "Definer.hpp"

namespace bbm {
	class Game;
	class Button {
		public:
			Button(const irr::io::path& standard,
			const irr::io::path& focus,
			const irr::io::path& click,
			bbm::IdButton id,
			bbm::ButtonInfos corners,
			bbm::Game &game);
			Button(irr::video::ITexture *,
			irr::video::ITexture *,
			irr::video::ITexture *,
			bbm::IdButton id,
			bbm::ButtonInfos corners,
			bbm::Game &game);
			~Button();
			void	setFocusImage();
			void	setStandardImage();
			irr::gui::IGUIButton	*getButton() const;
			IdButton	getId() const;
			void	setStandard(irr::video::ITexture *standard);
			void	setFocus(irr::video::ITexture *focus);
			void	setClick(irr::video::ITexture *click);

		protected:
		private:
			irr::video::ITexture	*_standard;
			irr::video::ITexture	*_focus;
			irr::video::ITexture	*_click;
			irr::gui::IGUIButton	*_button;
			bbm::IdButton	_id;
	};
}
