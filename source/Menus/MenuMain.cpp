//
// EPITECH PROJECT, 2018
// indie
// File description:
// main menu cpp
//

#include "MenuMain.hpp"
#include "Corners.hpp"

bbm::MenuMain::MenuMain(bbm::Game &Game) : IMenu(Game)
{
	std::cout << "Menu Main constructor" << std::endl;
}

bbm::MenuMain::~MenuMain()
{
	std::cout << "Menu Main destructor" << std::endl;
}

bool	bbm::MenuMain::OnEvent(const irr::SEvent &event)
{
	std::cout << "MainMenu onevent" << std::endl;
	return true;
}

void	bbm::MenuMain::quitGame(void)
{
	_game.getGraphic().getDevice()->closeDevice();
}

bool	bbm::MenuMain::run()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.Width / 5, 100};
	bbm::ButtonInfos	corners;

	corners = bbm::Corners::getCenteredVertical(screenSize, {0, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_NEWGAME, L"New Game"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	_game.getGraphic().getGuienv()->setFocus(_buttons[_buttons.size() - 1]);
	corners = bbm::Corners::getCenteredVertical(screenSize, {1, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_CONTINUE, L"Continue"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	corners = bbm::Corners::getCenteredVertical(screenSize, {2, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_SETTINGS, L"Settings"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	corners = bbm::Corners::getCenteredVertical(screenSize, {3, 4}, buttonSize);
	_buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_QUIT, L"Quit"));
	_buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	_buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	_buttons[_buttons.size() - 1]->setScaleImage();
	std::cout << "Menu MAIN run" << std::endl;
	return true;
}

void	bbm::MenuMain::draw()
{
	std::cout << "menu main draw" << std::endl;
}
