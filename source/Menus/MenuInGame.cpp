//
// EPITECH PROJECT, 2018
// indie
// File description:
// in game menu
//

#include "MenuInGame.hpp"
#include "Corners.hpp"

bbm::MenuInGame::MenuInGame(bbm::Game &Game) :
	IMenu(Game),
	_settingsMenu(new bbm::MenuSettings(Game, true)),
	_keepPlaying(true)
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.
	Width / 6, screenSize.Height / 10};

	_evManager->addEventReceiver(_settingsMenu->getEventManager());
	setupButtons(screenSize, buttonSize);
	_background = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/background.jpg");
	_white = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/white.png");
}

bbm::MenuInGame::~MenuInGame()
{
}

void	bbm::MenuInGame::setupButtons(
	const irr::core::dimension2du& screenSize,
	const irr::core::dimension2du& buttonSize)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_btns.push_back(new bbm::Button(folder + "resumegray.png",
	folder + "resumeblue.png", folder + "resumered.png",
	bbm::GUI_BUTTON_RESUME, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 0, 4}, buttonSize), _game));
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_btns.push_back(new bbm::Button(folder + "settingsgray.png",
	folder + "settingsblue.png", folder + "settingsred.png",
	bbm::GUI_BUTTON_SETTINGS, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 1, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "savequitgray.png",
	folder + "savequitblue.png", folder + "savequitred.png",
	bbm::GUI_BUTTON_SAVEQUIT, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 2, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "quitgray.png",
	folder + "quitblue.png", folder + "quitred.png",
	bbm::GUI_BUTTON_QUIT, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 3, 4}, buttonSize), _game));
	enableButtons(false);
}

void	bbm::MenuInGame::actionsClosing(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_RESUME) {
		goBack();
		_keepPlaying = true;
	}
	if (id == bbm::GUI_BUTTON_SAVEQUIT) {
		_game.getMatch().save();
		deactivate();
		enableButtons(false);
		_keepPlaying = false;
	}
	if (id == bbm::GUI_BUTTON_QUIT) {
		deactivate();
		enableButtons(false);
		_keepPlaying = false;
	}
}

bool	bbm::MenuInGame::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_SETTINGS) {
		deactivate();
		enableButtons(false);
		_settingsMenu->run();
		enableButtons(true);
		activate();
		_game.getGraphic().getGuienv()->
		setFocus(_btns[0]->getButton());
		_focused = 0;
	} else
		actionsClosing(id);
	return true;
}

void	bbm::MenuInGame::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuInGame::keysHandling(const irr::SEvent &event)
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
	return false;
}

bool	bbm::MenuInGame::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuInGame::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

void	bbm::MenuInGame::drawSceneBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getScene()->drawAll();
	_game.getGraphic().getDriver()->draw2DRectangle(
		irr::video::SColor(110, 150, 150, 150),
		irr::core::rect<irr::s32>(0, 0, screenSize.Width,
		screenSize.Height));
}

bool	bbm::MenuInGame::run()
{
	activate();
	_keepPlaying = true;
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.getDriver()->beginScene(true, true,
		irr::video::SColor(255, 100, 101, 140));
		draw();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	enableButtons(false);
	return _keepPlaying;
}

void	bbm::MenuInGame::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();

	drawSceneBackground(screenSize);
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
