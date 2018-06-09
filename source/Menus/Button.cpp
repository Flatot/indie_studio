//
// EPITECH PROJECT, 2018
// indie
// File description:
// button gui
//

#include "Button.hpp"
#include "Game.hpp"

bbm::Button::Button(const irr::io::path& standard, const irr::io::path& focus,
const irr::io::path& click, bbm::IdButton id, bbm::ButtonInfos corners,
bbm::Game &game) :
	_standard(game.getGraphic().getDriver()->getTexture(standard)),
	_focus(game.getGraphic().getDriver()->getTexture(focus)),
	_click(game.getGraphic().getDriver()->getTexture(click)),
	_id(id)
{
	_button = game.getGraphic().getGuienv()->
	addButton(irr::core::rect<irr::s32>(corners.startX,
	corners.startY, corners.endX, corners.endY), 0, id);
	_button->setPressedImage(_click);
	setStandardImage();
	_button->setScaleImage();
	_button->setUseAlphaChannel(true);
	_button->setDrawBorder(0);
}

bbm::Button::Button(irr::video::ITexture *standard,
irr::video::ITexture *focus, irr::video::ITexture *click,
bbm::IdButton id, bbm::ButtonInfos corners,
bbm::Game &game) :
	_standard(standard),
	_focus(focus),
	_click(click),
	_id(id)
{
	_button = game.getGraphic().getGuienv()->
	addButton(irr::core::rect<irr::s32>(corners.startX,
	corners.startY, corners.endX, corners.endY), 0, id);
	_button->setPressedImage(_click);
	setStandardImage();
	_button->setScaleImage();
	_button->setUseAlphaChannel(true);
	_button->setDrawBorder(0);
}

bbm::Button::~Button()
{
}

void	bbm::Button::setStandard(irr::video::ITexture *standard)
{
	_standard = standard;
}

void	bbm::Button::setFocus(irr::video::ITexture *focus)
{
	_focus = focus;
}

void	bbm::Button::setClick(irr::video::ITexture *click)
{
	_click = click;
}

void	bbm::Button::setFocusImage()
{
	_button->setImage(_focus);
}

void	bbm::Button::setStandardImage()
{
	_button->setImage(_standard);
}

irr::gui::IGUIButton	*bbm::Button::getButton() const
{
	return _button;
}

bbm::IdButton	bbm::Button::getId() const
{
	return _id;
}
