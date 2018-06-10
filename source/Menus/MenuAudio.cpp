//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu audio
//

#include "MenuAudio.hpp"
#include "Corners.hpp"

bbm::MenuAudio::MenuAudio(bbm::Game &Game, bool scene) : IMenu(Game)
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.
	Width / 6, screenSize.Height / 10};

	setupButtons(screenSize, buttonSize);
	_background = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/background.jpg");
	_white = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/white.png");
	_scene = scene;
}

bbm::MenuAudio::~MenuAudio()
{
}

void	bbm::MenuAudio::setupButtons(
	const irr::core::dimension2du& screenSize,
	const irr::core::dimension2du& buttonSize)
{
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/generalgray.png",
	"./assets/menus/buttons/generalblue.png",
	"./assets/menus/buttons/generalred.png",
	bbm::GUI_BUTTON_SOUNDS, bbm::Corners::getCenteredAudio(screenSize,
	{0, 2, 0, 3}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/effectsgray.png",
	"./assets/menus/buttons/effectsblue.png",
	"./assets/menus/buttons/effectsred.png",
	bbm::GUI_BUTTON_EFFECTS, bbm::Corners::getCenteredAudio(screenSize,
	{0, 2, 1, 3}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/backgray.png",
	"./assets/menus/buttons/backblue.png",
	"./assets/menus/buttons/backred.png",
	bbm::GUI_BUTTON_BACK, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 2, 3}, buttonSize), _game));
	enableButtons(false);
}

bool	bbm::MenuAudio::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_BACK)
		goBack();
	return true;
}

bool	bbm::MenuAudio::changeVolume()
{
	if (isKeyPressed(irr::KEY_RIGHT, NONE) && _game.getGraphic().
	getGuienv()->hasFocus(_btns[_focused]->getButton())) {
		if (_btns[_focused]->getId() == bbm::GUI_BUTTON_SOUNDS) {
			_game.getConfig().setVolumeGeneral(_game.getConfig().
			getVolumeGeneral() + 1);
			_game.getAudio().setGeneralVolume(
					_game.getConfig().getVolumeGeneral());
		}
		else if (_btns[_focused]->getId() == bbm::GUI_BUTTON_EFFECTS) {
			_game.getConfig().setVolumeEffect(_game.getConfig().
			getVolumeEffect() + 1);
			_game.getAudio().setEffectVolume(
					_game.getConfig().getVolumeEffect());
		}
		return true;
	} else if (isKeyPressed(irr::KEY_LEFT, NONE) && _game.getGraphic().
	getGuienv()->hasFocus(_btns[_focused]->getButton())) {
		if (_btns[_focused]->getId() == bbm::GUI_BUTTON_SOUNDS) {
			_game.getConfig().setVolumeGeneral(_game.getConfig().
			getVolumeGeneral() - 1);
			_game.getAudio().setGeneralVolume(
					_game.getConfig().getVolumeGeneral());
		} else if (_btns[_focused]->getId() == bbm::GUI_BUTTON_EFFECTS) {
			_game.getConfig().setVolumeEffect(_game.getConfig().
			getVolumeEffect() - 1);	
			_game.getAudio().setGeneralVolume(
					_game.getConfig().getVolumeGeneral());
		}
		return true;
	}
	return false;
}

void	bbm::MenuAudio::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuAudio::keysHandling(const irr::SEvent &event)
{
	if (isKeyPressed(irr::KEY_ESCAPE, NONE)) {
		goBack();
		resetKeys();
		return true;
	}
	if (isKeyPressed(irr::KEY_TAB, NONE)
	|| isKeyPressed(irr::KEY_DOWN, NONE)) {
		nextOne();
		return true;
	} else if (isKeyPressed(irr::KEY_TAB, SHIFT)
	|| isKeyPressed(irr::KEY_UP, NONE)) {
		previousOne();
		return true;
	}
	return changeVolume();
}

bool	bbm::MenuAudio::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - MenuAudio]" << std::endl;
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuAudio::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

bool	bbm::MenuAudio::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	std::cout << "Menu audio run" << std::endl;
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.getDriver()->beginScene(true, true,
		irr::video::SColor(255, 100, 101, 140));
		draw();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	enableButtons(false);
	_game.getConfig().saveConfig();
	return true;
}

void	bbm::MenuAudio::drawScaleSound(bbm::ButtonInfos &corners, int volume)
{
	_game.getGraphic().getDriver()->draw2DImage(_white,
	irr::core::dimension2d<irr::s32>(corners.startX, corners.startY),
	irr::core::rect<irr::s32>(corners.startX, corners.startY,
	corners.endX, corners.endY),
	0, irr::video::SColor(255, 100, 100, 100), true);
	_game.getGraphic().getDriver()->draw2DImage(_white,
	irr::core::dimension2d<irr::s32>(corners.startX, corners.startY),
	irr::core::rect<irr::s32>(corners.startX, corners.startY,
	corners.startX + (corners.endX - corners.startX) * (static_cast
	<float>(volume) / static_cast
	<float>(100)), corners.endY),
	0, irr::video::SColor(255, 60, 140, 100), true);
	_game.getGraphic().getDriver()->draw2DImage(_white,
	irr::core::dimension2d<irr::s32>(corners.startX - 20 + (corners.
	endX - corners.startX) * (static_cast<float>(volume) / static_cast
	<float>(100)), corners.startY - 20),
	irr::core::rect<irr::s32>(0, corners.startY,
	40, corners.endY + 40),
	0, irr::video::SColor(255, 210, 210, 230), true);
}

void	bbm::MenuAudio::drawSounds(const irr::core::dimension2du& screenSize)
{
	bbm::ButtonInfos	corners;
	const irr::core::dimension2du& buttonSize = {screenSize.
	Width / 3, 60};

	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 2, 0, 3},
	buttonSize);
	drawScaleSound(corners, _game.getConfig().getVolumeGeneral());
	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 2, 1, 3},
	buttonSize);
	drawScaleSound(corners, _game.getConfig().getVolumeEffect());
}

void	bbm::MenuAudio::drawSceneBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getScene()->drawAll();
	_game.getGraphic().getDriver()->draw2DRectangle(
		irr::video::SColor(110, 150, 150, 150),
		irr::core::rect<irr::s32>(0, 0, screenSize.Width,
		screenSize.Height));
}

void	bbm::MenuAudio::drawBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getDriver()->enableMaterial2D();
	_game.getGraphic().getDriver()->draw2DImage(_background,
	irr::core::rect<irr::s32>(0,
	0, screenSize.Width, screenSize.Height),
	irr::core::rect<irr::s32>(0, 0, _background->
	getSize().Width, _background->getSize().Height));
	_game.getGraphic().getDriver()->enableMaterial2D(false);
}

void	bbm::MenuAudio::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();

	if (_scene)
		drawSceneBackground(screenSize);
	else
		drawBackground(screenSize);
	drawSounds(screenSize);
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		if (_game.getGraphic().getGuienv()->
		hasFocus((*it)->getButton()))
			(*it)->setFocusImage();
		else
			(*it)->setStandardImage();
	}
	_game.getGraphic().getGuienv()->drawAll();
}
