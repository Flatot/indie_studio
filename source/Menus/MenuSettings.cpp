//
// EPITECH PROJECT, 2018
// indie
// File description:
// settings menu
//

#include "MenuSettings.hpp"
#include "Corners.hpp"

bbm::MenuSettings::MenuSettings(bbm::Game &Game) : IMenu(Game)
{
	std::cout << "Menu Settings constructor" << std::endl;
}

bbm::MenuSettings::~MenuSettings()
{
	std::cout << "Menu Settings destructor" << std::endl;
}

bool	bbm::MenuSettings::OnEvent(const irr::SEvent &event)
{
	std::cout << "Settings onevent" << std::endl;
	return true;
}

bool	bbm::MenuSettings::run()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.Width / 5, 100};
	bbm::ButtonInfos	corners;

	corners = bbm::Corners::getCenteredVertical(screenSize, {0, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_VIDEO, L"Video"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	_game.getGraphic().getGuienv()->setFocus(_buttons[_buttons.size() - 1]);
	corners = bbm::Corners::getCenteredVertical(screenSize, {1, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_AUDIO, L"Audio"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	corners = bbm::Corners::getCenteredVertical(screenSize, {2, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_CONTROLS, L"Controls"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	corners = bbm::Corners::getCenteredVertical(screenSize, {3, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_BACK, L"Back"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	std::cout << "Menu SETTINGS run" << std::endl;
	return true;
}

void	bbm::MenuSettings::draw()
{
	std::cout << "draw settings menu" << std::endl;
}
