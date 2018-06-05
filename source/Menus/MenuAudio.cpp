//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu audio
//

#include "MenuAudio.hpp"
#include "Corners.hpp"

bbm::MenuAudio::MenuAudio(bbm::Game &Game) : IMenu(Game)
{
}

bbm::MenuAudio::~MenuAudio()
{
}

bool	bbm::MenuAudio::OnEvent(const irr::SEvent &event)
{
	std::cout << "audio onevent" << std::endl;
	return true;
}

bool	bbm::MenuAudio::run()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.Width / 5, 100};
	bbm::ButtonInfos	corners;

	// corners = bbm::Corners::getCenteredVertical(screenSize, {0, 4}, buttonSize);
	// _buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_RESUME, L"Resume"));
	// _buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	// _buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	// _buttons[_buttons.size() - 1]->setScaleImage();
	// _game.getGraphic().getGuienv()->setFocus(_buttons[_buttons.size() - 1]);
	// corners = bbm::Corners::getCenteredVertical(screenSize, {1, 4}, buttonSize);
	// _buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_SETTINGS, L"Settings"));
	// _buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	// _buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	// _buttons[_buttons.size() - 1]->setScaleImage();
	// corners = bbm::Corners::getCenteredVertical(screenSize, {2, 4}, buttonSize);
	// _buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_SAVEQUIT, L"Save and Quit"));
	// _buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	// _buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	// _buttons[_buttons.size() - 1]->setScaleImage();
	// corners = bbm::Corners::getCenteredVertical(screenSize, {3, 4}, buttonSize);
	// _buttons.push_back(_game.getGraphic().getGuienv()->addButton(irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.endX, corners.endY), 0, bbm::GUI_BUTTON_END, L"End Game"));
	// _buttons[_buttons.size() - 1]->setImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/no-image.png"));
	// _buttons[_buttons.size() - 1]->setPressedImage(_game.getGraphic().getDriver()->getTexture("../assets/menus/click.jpg"));
	// _buttons[_buttons.size() - 1]->setScaleImage();
	std::cout << "Menu audio run" << std::endl;
	return true;
}

void	bbm::MenuAudio::draw()
{
	std::cout << "draw audio menu" << std::endl;
}