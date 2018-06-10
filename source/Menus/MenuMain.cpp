//
// EPITECH PROJECT, 2018
// indie
// File description:
// main menu cpp
//

#include "MenuMain.hpp"
#include "Corners.hpp"

bbm::MenuMain::MenuMain(bbm::Game &Game) :
	IMenu(Game),
	_settingsMenu(new bbm::MenuSettings(Game)),
	_newGameMenu(new bbm::MenuNewGame(Game)),
	_gameToLoad(false)
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.
	Width / 6, screenSize.Height / 10};

	_evManager->addEventReceiver(_settingsMenu->getEventManager());
	_evManager->addEventReceiver(_newGameMenu->getEventManager());
	initLoadImages();
	setupButtons(screenSize, buttonSize);
	_background = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/background.jpg");
	_white = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/white.png");
	_bomberman = _game.getGraphic().getDriver()->
	getTexture("./assets/menus/player.png");
	std::cout << "Menu Main constructor" << std::endl;
}

bbm::MenuMain::~MenuMain()
{
	std::cout << "Menu Main destructor" << std::endl;
}

void	bbm::MenuMain::setupLoadButton()
{
	if (_gameToLoad) {
		_btns[1]->setStandard(_loadImgs[0]);
		_btns[1]->setFocus(_loadImgs[1]);
		_btns[1]->setClick(_loadImgs[2]);
		_btns[1]->getButton()->setPressedImage(_loadImgs[2]);
	} else {
		_btns[1]->setStandard(_loadImgs[3]);
		_btns[1]->setFocus(_loadImgs[4]);
		_btns[1]->setClick(_loadImgs[5]);
		_btns[1]->getButton()->setPressedImage(_loadImgs[5]);
	}
}

void	bbm::MenuMain::initLoadImages()
{
	irr::io::path	folder("./assets/menus/buttons/");

	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "loadgamegray.png"));
	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "loadgameblue.png"));
	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "loadgamered.png"));
	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "cannotloadgamegray.png"));
	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "cannotloadgameblue.png"));
	_loadImgs.push_back(_game.getGraphic().getDriver()->
	getTexture(folder + "cannotloadgamered.png"));
}

void	bbm::MenuMain::setupButtons(const irr::core::dimension2du& screenSize,
const irr::core::dimension2du& buttonSize)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_btns.push_back(new bbm::Button(folder + "newgamegray.png",
	folder + "newgameblue.png", folder + "newgamered.png",
	bbm::GUI_BUTTON_NEWGAME, bbm::Corners::getCenteredVertical(screenSize,
	{0, 4}, buttonSize), _game));
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_btns.push_back(new bbm::Button(_loadImgs[0],
	_loadImgs[1], _loadImgs[2],
	bbm::GUI_BUTTON_CONTINUE, bbm::Corners::getCenteredVertical(screenSize,
	{1, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "settingsgray.png",
	folder + "settingsblue.png", folder + "settingsred.png",
	bbm::GUI_BUTTON_SETTINGS, bbm::Corners::getCenteredVertical(screenSize,
	{2, 4}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "quitgray.png",
	folder + "quitblue.png", folder + "quitred.png",
	bbm::GUI_BUTTON_QUIT, bbm::Corners::getCenteredVertical(screenSize,
	{3, 4}, buttonSize), _game));
	enableButtons(false);
}

bool	bbm::MenuMain::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_QUIT)
		quitGame();
	if (id == bbm::GUI_BUTTON_SETTINGS) {
		runSettings();
		_game.getGraphic().getGuienv()->
		setFocus(_btns[0]->getButton());
		_focused = 0;
	}
	if (id == bbm::GUI_BUTTON_NEWGAME) {
		runNewGame();
		_game.getGraphic().getGuienv()->
		setFocus(_btns[0]->getButton());
		_focused = 0;
	}
	if (id == bbm::GUI_BUTTON_CONTINUE)
		continueGame();
	return true;
}

void	bbm::MenuMain::continueGame()
{
	_gameToLoad = _game.hasSave();
	if (_gameToLoad) {
		_game.getMatch().load();
		_game.getMatch().run();
	} else {
		std::cout << "IL N'Y A PAS DE GAME A LOAD {{lancer un son}}" << std::endl;
	}
}

void	bbm::MenuMain::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuMain::keysHandling(const irr::SEvent &event)
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

bool	bbm::MenuMain::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - MenuMain]" << std::endl;
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuMain::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

void	bbm::MenuMain::runSettings(void)
{
	enableButtons(false);
	deactivate();
	_settingsMenu->run();
	activate();
	enableButtons(true);
}

void	bbm::MenuMain::runNewGame(void)
{
	enableButtons(false);
	deactivate();
	_newGameMenu->run();
	_gameToLoad = _game.hasSave();
	activate();
	enableButtons(true);
}

void	bbm::MenuMain::quitGame(void)
{
	_game.getGraphic().getDevice()->closeDevice();
}

bool	bbm::MenuMain::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	_gameToLoad = _game.hasSave();
	setupLoadButton();
	enableButtons(true);
	std::cout << "Menu MAIN run" << std::endl;
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

void	bbm::MenuMain::drawBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getDriver()->enableMaterial2D();
	_game.getGraphic().getDriver()->draw2DImage(_background,
	irr::core::rect<irr::s32>(0,
	0, screenSize.Width, screenSize.Height),
	irr::core::rect<irr::s32>(0, 0, _background->
	getSize().Width, _background->getSize().Height));
	_game.getGraphic().getDriver()->draw2DImage(_bomberman,
	irr::core::rect<irr::s32>(screenSize.Width / 12,
	screenSize.Height / 7, screenSize.Width / 2 - screenSize.Width / 12,
	screenSize.Height - screenSize.Height / 7),
	irr::core::rect<irr::s32>(0, 0, _bomberman->
	getSize().Width, _bomberman->getSize().Height), 0, 0, true);
	_game.getGraphic().getDriver()->enableMaterial2D(false);
}

void	bbm::MenuMain::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();

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
