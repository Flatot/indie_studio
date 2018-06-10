//
// EPITECH PROJECT, 2018
// indie
// File description:
// settings menu
//

#include "MenuSettings.hpp"
#include "Corners.hpp"

bbm::MenuSettings::MenuSettings(bbm::Game &Game, bool scene) :
	IMenu(Game),
	_audioMenu(new bbm::MenuAudio(Game, scene)),
	_videoMenu(new bbm::MenuVideo(Game, scene)),
	_controlsMenu(new bbm::MenuControls(Game, scene))
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.
	Width / 6, screenSize.Height / 10};

	_evManager->addEventReceiver(_audioMenu->getEventManager());
	_evManager->addEventReceiver(_videoMenu->getEventManager());
	_evManager->addEventReceiver(_controlsMenu->getEventManager());
	setupButtons(screenSize, buttonSize);
	_background = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/background.jpg");
	_white = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/white.png");
	_bomberman = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/player.png");
	_scene = scene;
	std::cout << "Menu Settings constructor" << std::endl;
}

bbm::MenuSettings::~MenuSettings()
{
	std::cout << "Menu Settings destructor" << std::endl;
}

void	bbm::MenuSettings::setupButtons(
	const irr::core::dimension2du& screenSize,
	const irr::core::dimension2du& buttonSize)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_btns.push_back(new bbm::Button(folder + "videogray.png",
	folder + "videoblue.png", folder + "videored.png",
	bbm::GUI_BUTTON_VIDEO, bbm::Corners::getCenteredVertical(screenSize,
	{0, 4}, buttonSize), _game));
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_btns.push_back(new bbm::Button(folder + "audiogray.png",
	folder + "audioblue.png", folder + "audiored.png",
	bbm::GUI_BUTTON_AUDIO, bbm::Corners::getCenteredVertical(screenSize,
	{1, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "controlsgray.png",
	folder + "controlsblue.png", folder + "controlsred.png",
	bbm::GUI_BUTTON_CONTROLS, bbm::Corners::getCenteredVertical(screenSize,
	{2, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "backgray.png",
	folder + "backblue.png", folder + "backred.png",
	bbm::GUI_BUTTON_BACK, bbm::Corners::getCenteredVertical(screenSize,
	{3, 4}, buttonSize), _game));
	enableButtons(false);
}

bool	bbm::MenuSettings::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_BACK)
		goBack();
	if (id == bbm::GUI_BUTTON_AUDIO || id == bbm::GUI_BUTTON_VIDEO ||
	id == bbm::GUI_BUTTON_CONTROLS) {
		deactivate();
		enableButtons(false);
		if (id == bbm::GUI_BUTTON_AUDIO)
			_audioMenu->run();
		else if (id == bbm::GUI_BUTTON_VIDEO)
			_videoMenu->run();
		else if (id == bbm::GUI_BUTTON_CONTROLS)
			_controlsMenu->run();
		enableButtons(true);
		activate();
		_game.getGraphic().getGuienv()->
		setFocus(_btns[0]->getButton());
		_focused = 0;
	}
	return true;
}

void	bbm::MenuSettings::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuSettings::keysHandling(const irr::SEvent &event)
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

bool	bbm::MenuSettings::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - MenuSettings]" << std::endl;
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuSettings::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

bool	bbm::MenuSettings::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	std::cout << "Menu SETTINGS run" << std::endl;
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.getDriver()->beginScene(true, true,
		irr::video::SColor(255, 100, 101, 140));
		draw();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	enableButtons(false);
	return true;
}

void	bbm::MenuSettings::drawSceneBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getScene()->drawAll();
	_game.getGraphic().getDriver()->draw2DRectangle(
		irr::video::SColor(110, 150, 150, 150),
		irr::core::rect<irr::s32>(0, 0, screenSize.Width,
		screenSize.Height));
}

void	bbm::MenuSettings::drawBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getDriver()->enableMaterial2D();
	_game.getGraphic().getDriver()->draw2DImage(_background,
	irr::core::rect<irr::s32>(0,
	0, screenSize.Width, screenSize.Height),
	irr::core::rect<irr::s32>(0, 0, _background->
	getSize().Width, _background->getSize().Height));
	_game.getGraphic().getDriver()->draw2DImage(_bomberman,
	irr::core::rect<irr::s32>(screenSize.Width / 20,
	screenSize.Height / 7, screenSize.Width / 2 - screenSize.Width / 20,
	screenSize.Height - screenSize.Height / 7),
	irr::core::rect<irr::s32>(0, 0, _bomberman->
	getSize().Width, _bomberman->getSize().Height), 0, 0, true);
	_game.getGraphic().getDriver()->enableMaterial2D(false);
}

void	bbm::MenuSettings::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();

	if (_scene)
		drawSceneBackground(screenSize);
	else
		drawBackground(screenSize);
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
