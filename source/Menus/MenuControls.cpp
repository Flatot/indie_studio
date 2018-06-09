//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu controls
//

#include "MenuControls.hpp"
#include "Corners.hpp"

bbm::MenuControls::MenuControls(bbm::Game &Game, bool scene) :
	IMenu(Game),
	_player(0),
	_changing(false)
{
	irr::video::IVideoDriver *driver = _game.getGraphic().getDriver();
	const irr::core::dimension2du& buttonSize = {driver->getScreenSize().
		Width / 6, driver->getScreenSize().Height / 10};

	_background = driver->getTexture("./assets/menus/background.jpg");
	_white = driver->getTexture("./assets/menus/white.png");
	pimgInitialize(driver);
	setupButtons(driver->getScreenSize(), buttonSize);
	setupControls(driver->getScreenSize());
	initializeControls();
	_scene = scene;
}

bbm::MenuControls::~MenuControls()
{
}

void	bbm::MenuControls::pimgInitialize(irr::video::IVideoDriver *driver)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_pimg.push_back(driver->getTexture(folder + "player1gray.png"));
	_pimg.push_back(driver->getTexture(folder + "player1blue.png"));
	_pimg.push_back(driver->getTexture(folder + "player1red.png"));
	_pimg.push_back(driver->getTexture(folder + "player2gray.png"));
	_pimg.push_back(driver->getTexture(folder + "player2blue.png"));
	_pimg.push_back(driver->getTexture(folder + "player2red.png"));
	_pimg.push_back(driver->getTexture(folder + "player3gray.png"));
	_pimg.push_back(driver->getTexture(folder + "player3blue.png"));
	_pimg.push_back(driver->getTexture(folder + "player3red.png"));
	_pimg.push_back(driver->getTexture(folder + "player4gray.png"));
	_pimg.push_back(driver->getTexture(folder + "player4blue.png"));
	_pimg.push_back(driver->getTexture(folder + "player4red.png"));
}

void	bbm::MenuControls::setupPlayerButton()
{
	_btns[5]->setStandard(_pimg[_player * 3 + 0]);
	_btns[5]->setFocus(_pimg[_player * 3 + 1]);
	_btns[5]->setClick(_pimg[_player * 3 + 2]);
	_btns[5]->getButton()->setPressedImage(_pimg[_player * 3 + 2]);
}

void	bbm::MenuControls::setupOtherButtons(
		const irr::core::dimension2du& screenSize,
		const irr::core::dimension2du& buttonSize)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_btns.push_back(new bbm::Button(folder + "rightgray.png",
				folder + "rightblue.png", folder + "rightred.png",
				bbm::GUI_BUTTON_RIGHT, bbm::Corners::getCenteredAudio(screenSize,
					{0, 2, 3, 7}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "bombgray.png",
				folder + "bombblue.png", folder + "bombred.png",
				bbm::GUI_BUTTON_BOMB, bbm::Corners::getCenteredAudio(screenSize,
					{0, 2, 4, 7}, buttonSize), _game));
	_btns.push_back(new bbm::Button(_pimg[0], _pimg[1], _pimg[2],
				bbm::GUI_BUTTON_PLAYER, bbm::Corners::getCenteredAudio(screenSize,
					{1, 3, 5, 7}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "backgray.png",
				folder + "backblue.png", folder + "backred.png",
				bbm::GUI_BUTTON_BACK, bbm::Corners::getCenteredAudio(screenSize,
					{1, 3, 6, 7}, buttonSize), _game));
	setupPlayerButton();
}

void	bbm::MenuControls::setupButtons(
		const irr::core::dimension2du& screenSize,
		const irr::core::dimension2du& buttonSize)
{
	irr::io::path	folder("./assets/menus/buttons/");

	_btns.push_back(new bbm::Button(folder + "forwardgray.png",
				folder + "forwardblue.png", folder + "forwardred.png",
				bbm::GUI_BUTTON_FORWARD, bbm::Corners::getCenteredAudio(screenSize,
					{0, 2, 0, 7}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "leftgray.png",
				folder + "leftblue.png", folder + "leftred.png",
				bbm::GUI_BUTTON_LEFT, bbm::Corners::getCenteredAudio(screenSize,
					{0, 2, 1, 7}, buttonSize), _game));
	_btns.push_back(new bbm::Button(folder + "backwardgray.png",
				folder + "backwardblue.png", folder + "backwardred.png",
				bbm::GUI_BUTTON_BACKWARD, bbm::Corners::getCenteredAudio(screenSize,
					{0, 2, 2, 7}, buttonSize), _game));
	setupOtherButtons(screenSize, buttonSize);
	_btns[0]->getButton()->setIsPushButton();
	_btns[1]->getButton()->setIsPushButton();
	_btns[2]->getButton()->setIsPushButton();
	_btns[3]->getButton()->setIsPushButton();
	_btns[4]->getButton()->setIsPushButton();
	enableButtons(false);
}

int	bbm::MenuControls::getIndexById(irr::s32 id)
{
	int	i = 0;

	for(std::vector<bbm::Button *>::iterator it = _btns.
			begin(); it != _btns.end(); ++it) {
		if ((*it)->getId() == id)
			return i;
		i++;
	}
	return -1;
}

bool	bbm::MenuControls::takeActions(irr::s32 id)
{
	int	idx = getIndexById(id);

	if (idx != -1 && idx != _focused) {
		_btns[_focused]->getButton()->setPressed(false);
		_focused = idx;
	}
	if (id == bbm::GUI_BUTTON_BACK)
		goBack();
	if (!_changing && (id == bbm::GUI_BUTTON_FORWARD ||
				id == bbm::GUI_BUTTON_BACKWARD ||
				id == bbm::GUI_BUTTON_LEFT ||
				id == bbm::GUI_BUTTON_RIGHT ||
				id == bbm::GUI_BUTTON_BOMB))
		_changing = true;
	return true;
}

bool	bbm::MenuControls::changePlayer()
{
	if (isKeyPressed(irr::KEY_RIGHT, NONE) && _game.getGraphic().
			getGuienv()->hasFocus(_btns[_focused]->getButton())) {
		if (_btns[_focused]->getId() == bbm::GUI_BUTTON_PLAYER) {
			_player = _player + 1 >= _pimg.size() / 3 ? 0 :
				_player + 1;
			setupPlayerButton();
		}
		return true;
	} else if (isKeyPressed(irr::KEY_LEFT, NONE) && _game.getGraphic().
			getGuienv()->hasFocus(_btns[_focused]->getButton())) {
		if (_btns[_focused]->getId() == bbm::GUI_BUTTON_PLAYER) {
			_player = _player - 1 < 0 ? _pimg.size() / 3 - 1 :
				_player - 1;
			setupPlayerButton();
		}
		return true;
	}
	return false;
}

void	bbm::MenuControls::changeControl(const irr::SEvent &event)
{
	if (!isKeyPressed(irr::KEY_ESCAPE, NONE)) {
		if (_focused == 0)
			_pctrl[_player].forward = event.KeyInput.Key;
		if (_focused == 1)
			_pctrl[_player].left = event.KeyInput.Key;
		if (_focused == 2)
			_pctrl[_player].backward = event.KeyInput.Key;
		if (_focused == 3)
			_pctrl[_player].right = event.KeyInput.Key;
		if (_focused == 4)
			_pctrl[_player].bomb = event.KeyInput.Key;
	}
}

void	bbm::MenuControls::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuControls::keysHandling(const irr::SEvent &event)
{
	if (!_changing && isKeyPressed(irr::KEY_ESCAPE, NONE)) {
		goBack();
		resetKeys();
		return true;
	} else if (_changing) {
		changeControl(event);
		_btns[_focused]->getButton()->setPressed(false);
		_changing = false;
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
	return changePlayer();
}

bool	bbm::MenuControls::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - MenuControls]" << std::endl;
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuControls::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.begin(); 
			it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

bool	bbm::MenuControls::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	setControlsVisible(true);
	std::cout << "Menu controls run" << std::endl;
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.getDriver()->beginScene(true, true,
				irr::video::SColor(255, 100, 101, 140));
		draw();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	enableButtons(false);
	setControlsVisible(false);
	saveControls();
	return true;
}

void bbm::MenuControls::saveControls()
{
	for (int i = 0; i < 4; ++i) {
		auto &keyMap = _game.getConfig().getPlayerConfig(i).getMap();
		keyMap["PUT_BOMB"] = _pctrl[i].bomb;
		keyMap["UP"] = _pctrl[i].forward;
		keyMap["DOWN"] = _pctrl[i].backward;
		keyMap["LEFT"] = _pctrl[i].left;
		keyMap["RIGHT"] = _pctrl[i].right;
	}
	_game.getConfig().saveConfig();
}

void	bbm::MenuControls::initializeControls()
{
	for (int i = 0; i < 4; ++i) {
		auto &keyMap = _game.getConfig().getPlayerConfig(i).getMap();
		_pctrl.push_back({keyMap["UP"], keyMap["LEFT"], keyMap["DOWN"], 
				keyMap["RIGHT"], keyMap["PUT_BOMB"]});
	}
}

void	bbm::MenuControls::setupControls(const irr::core::dimension2du&
		screenSize)
{
	bbm::ButtonInfos corners;
	irr::gui::IGUIFont *font = _game.getGraphic().
		getGuienv()->getFont("./assets/menus/font/font_indie.xml");

	for (int i = 0; i < 5; i++) {
		corners = bbm::Corners::getCenteredAudio(
				screenSize, {1, 2, i, 7}, {400, 70});
		_controls.push_back(_game.getGraphic().getGuienv()
				->addStaticText(L"NONE", irr::core::rect<irr::s32>(corners.
						startX, corners.startY, corners.endX, corners.endY),
					false, true, 0, -1, true));
		_controls[_controls.size() - 1]->setOverrideFont(font);
		_controls[_controls.size() - 1]->setVisible(false);
		_controls[_controls.size() - 1]->setTextAlignment(
				irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
	}
}

void	bbm::MenuControls::setControlsVisible(bool visible)
{
	for (auto it = _controls.begin(); it != _controls.end(); ++it) {
		(*it)->setVisible(visible);
	}
}

const wchar_t	*bbm::MenuControls::getCharByCode(irr::EKEY_CODE code)
{
	for (int i = 0; keymsg[i].code != irr::KEY_KEY_CODES_COUNT; i++) {
		if (keymsg[i].code == code)
			return keymsg[i].text;
	}
	return NULL;
}

void	bbm::MenuControls::drawControls(const irr::core::dimension2du&
		screenSize)
{
	_controls[0]->setText(getCharByCode(_pctrl[_player].forward));
	_controls[1]->setText(getCharByCode(_pctrl[_player].left));
	_controls[2]->setText(getCharByCode(_pctrl[_player].backward));
	_controls[3]->setText(getCharByCode(_pctrl[_player].right));
	_controls[4]->setText(getCharByCode(_pctrl[_player].bomb));
}

void	bbm::MenuControls::drawSceneBackground(const irr::core::dimension2du&
		screenSize)
{
	_game.getGraphic().getScene()->drawAll();
	_game.getGraphic().getDriver()->draw2DRectangle(
			irr::video::SColor(110, 150, 150, 150),
			irr::core::rect<irr::s32>(0, 0, screenSize.Width,
				screenSize.Height));
}

void	bbm::MenuControls::drawBackground(const irr::core::dimension2du&
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

void	bbm::MenuControls::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
		getDriver()->getScreenSize();

	if (_scene)
		drawSceneBackground(screenSize);
	else
		drawBackground(screenSize);
	drawControls(screenSize);
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
