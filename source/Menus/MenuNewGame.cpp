//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu new game
//

#include "MenuNewGame.hpp"
#include "Corners.hpp"

bbm::MenuNewGame::MenuNewGame(bbm::Game &Game) : IMenu(Game),
	_lobby(new bbm::MenuLobby(Game))
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
		getDriver()->getScreenSize();
	const irr::core::dimension2du& buttonSize = {screenSize.
		Width / 6, screenSize.Height / 10};

	_background = _game.getGraphic().getDriver()->
		getTexture("./assets/menus/background.jpg");
	_white = _game.getGraphic().getDriver()->
		getTexture("./assets/menus/white.png");
	setupAttrs();
	setupButtons(screenSize, buttonSize);
	setupTeams();
}

bbm::MenuNewGame::~MenuNewGame()
{
}

void	bbm::MenuNewGame::setupTeams()
{
	_teams.push_back(bbm::TEAM_BLUE);
	_teams.push_back(bbm::TEAM_RED);
	_teams.push_back(bbm::TEAM_GREEN);
	_teams.push_back(bbm::TEAM_PURPLE);
}

void	bbm::MenuNewGame::setupAttrs()
{
	_attrs.push_back(bbm::ATTR_PLAYER);
	_attrs.push_back(bbm::ATTR_NONE);
	_attrs.push_back(bbm::ATTR_NONE);
	_attrs.push_back(bbm::ATTR_NONE);
	_attrimgs.push_back(std::pair<bbm::AttrEntity,
			irr::video::ITexture *>(bbm::ATTR_NONE, _game.getGraphic().
				getDriver()->getTexture("./assets/menus/none.png")));
	_attrimgs.push_back(std::pair<bbm::AttrEntity,
			irr::video::ITexture *>(bbm::ATTR_PLAYER, _game.getGraphic().
				getDriver()->getTexture("./assets/menus/player.png")));
	_attrimgs.push_back(std::pair<bbm::AttrEntity,
			irr::video::ITexture *>(bbm::ATTR_AI, _game.getGraphic().
				getDriver()->getTexture("./assets/menus/ai.png")));
}

void	bbm::MenuNewGame::setupOtherButtons(
		const irr::core::dimension2du& screenSize,
		const irr::core::dimension2du& buttonSize)
{
	_btns.push_back(new bbm::Button(
				"./assets/menus/buttons/player4gray.png",
				"./assets/menus/buttons/player4blue.png",
				"./assets/menus/buttons/player4red.png",
				bbm::GUI_BUTTON_P4, bbm::Corners::getCenteredAudio(screenSize,
					{0, 3, 3, 6}, buttonSize), _game));
	_btns.push_back(new bbm::Button("./assets/menus/buttons/startgray.png",
				"./assets/menus/buttons/startblue.png",
				"./assets/menus/buttons/startred.png",
				bbm::GUI_BUTTON_START, bbm::Corners::getCenteredAudio(screenSize,
					{1, 3, 4, 6}, buttonSize), _game));
	_btns.push_back(new bbm::Button("./assets/menus/buttons/backgray.png",
				"./assets/menus/buttons/backblue.png",
				"./assets/menus/buttons/backred.png",
				bbm::GUI_BUTTON_BACK, bbm::Corners::getCenteredAudio(screenSize,
					{1, 3, 5, 6}, buttonSize), _game));
}

void	bbm::MenuNewGame::setupButtons(
		const irr::core::dimension2du& screenSize,
		const irr::core::dimension2du& buttonSize)
{
	_btns.push_back(new bbm::Button(
				"./assets/menus/buttons/player1gray.png",
				"./assets/menus/buttons/player1blue.png",
				"./assets/menus/buttons/player1red.png",
				bbm::GUI_BUTTON_P1, bbm::Corners::getCenteredAudio(screenSize,
					{0, 3, 0, 6}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
				"./assets/menus/buttons/player2gray.png",
				"./assets/menus/buttons/player2blue.png",
				"./assets/menus/buttons/player2red.png",
				bbm::GUI_BUTTON_P2, bbm::Corners::getCenteredAudio(screenSize,
					{0, 3, 1, 6}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
				"./assets/menus/buttons/player3gray.png",
				"./assets/menus/buttons/player3blue.png",
				"./assets/menus/buttons/player3red.png",
				bbm::GUI_BUTTON_P3, bbm::Corners::getCenteredAudio(screenSize,
					{0, 3, 2, 6}, buttonSize), _game));
	setupOtherButtons(screenSize, buttonSize);
	enableButtons(false);
}

bool	bbm::MenuNewGame::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_BACK)
		goBack();
	if (id == bbm::GUI_BUTTON_START)
		startGame();
	return true;
}

void	bbm::MenuNewGame::startGame()
{
	deactivate();
	enableButtons(false);
	_lobby->setVisible(false);
	std::cout << "avant" << std::endl;
	_game.launchMatch(_attrs, _teams);
	std::cout << "apres" << std::endl;
	_lobby->setVisible(true);
	enableButtons(true);
	activate();
	resetKeys();
	_game.getGraphic().getGuienv()->setFocus(_btns[4]->getButton());
	_focused = 4;
}

irr::video::ITexture	*bbm::MenuNewGame::getImageByAttr(bbm::AttrEntity attr)
{
	for(auto it = _attrimgs.begin(); it != _attrimgs.end(); ++it) {
		if ((*it).first == attr)
			return (*it).second;
	}
	return NULL;
}

bool	bbm::MenuNewGame::changeAttr()
{
	if (isKeyPressed(irr::KEY_RIGHT, NONE)) {
		if (_focused < 4)
			_attrs[_focused] = _attrs[_focused] + 1 > 2 ? 
				static_cast<bbm::AttrEntity>(0) : 
				static_cast<bbm::AttrEntity>(_attrs[_focused] + 1);
		return true;
	}
	if (isKeyPressed(irr::KEY_LEFT, NONE)) {
		if (_focused < 4)
			_attrs[_focused] = _attrs[_focused] - 1 < 0 ? 
				static_cast<bbm::AttrEntity>(2) : 
				static_cast<bbm::AttrEntity>(_attrs[_focused] - 1);
		return true;
	}
	return false;
}

void	bbm::MenuNewGame::goBack()
{
	deactivate();
	enableButtons(false);
}

bool	bbm::MenuNewGame::keysHandling(const irr::SEvent &event)
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
	if (isKeyPressed(irr::KEY_RETURN, NONE) && _focused < 4) {
		_teams[_focused] = _teams[_focused] + 1 >=
			_teams.size() ? static_cast<bbm::TeamColor>(0) :
			static_cast<bbm::TeamColor>(_teams[_focused] + 1);
		return true;
	}
	return changeAttr();
}

bool	bbm::MenuNewGame::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - MenuNewGame]" << std::endl;
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
			return takeActions(id);
	}
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		return keysHandling(event);
	return false;
}

void	bbm::MenuNewGame::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.begin(); 
			it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

bool	bbm::MenuNewGame::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	std::cout << "Menu new game run" << std::endl;
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

void	bbm::MenuNewGame::drawImage(bbm::ButtonInfos &corners,
		irr::video::ITexture *img)
{
	_game.getGraphic().getDriver()->enableMaterial2D();
	_game.getGraphic().getDriver()->draw2DImage(img,
			irr::core::rect<irr::s32>(corners.startX, corners.startY, corners.
				endX, corners.endY), irr::core::rect<irr::s32>(0, 0, img->getSize().
					Width,img->getSize().Height), 0, 0, true);
	_game.getGraphic().getDriver()->enableMaterial2D(false);
}

void	bbm::MenuNewGame::drawTeamColor(int idx, bbm::ButtonInfos &corners)
{
	if (_teams[idx] == bbm::TEAM_BLUE)
		_game.getGraphic().getDriver()->draw2DRectangle(
				irr::video::SColor(210, 0, 0, 255), irr::core::rect<irr::s32>(
					corners.startX, corners.startY, corners.endX, corners.endY));
	if (_teams[idx] == bbm::TEAM_RED)
		_game.getGraphic().getDriver()->draw2DRectangle(
				irr::video::SColor(210, 255, 0, 0), irr::core::rect<irr::s32>(
					corners.startX, corners.startY, corners.endX, corners.endY));
	if (_teams[idx] == bbm::TEAM_GREEN)
		_game.getGraphic().getDriver()->draw2DRectangle(
				irr::video::SColor(210, 0, 255, 0), irr::core::rect<irr::s32>(
					corners.startX, corners.startY, corners.endX, corners.endY));
	if (_teams[idx] == bbm::TEAM_PURPLE)
		_game.getGraphic().getDriver()->draw2DRectangle(
				irr::video::SColor(210, 75, 0, 130), irr::core::rect<irr::s32>(
					corners.startX, corners.startY, corners.endX, corners.endY));
}

void	bbm::MenuNewGame::drawTeams(const irr::core::dimension2du& screenSize)
{
	bbm::ButtonInfos	corners;
	const irr::core::dimension2du& imageSize = {200, screenSize.
		Height / 8};

	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 3, 0, 6},
			imageSize);
	drawTeamColor(0, corners);
	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 3, 1, 6},
			imageSize);
	drawTeamColor(1, corners);
	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 3, 2, 6},
			imageSize);
	drawTeamColor(2, corners);
	corners = bbm::Corners::getCenteredAudio(screenSize, {1, 3, 3, 6},
			imageSize);
	drawTeamColor(3, corners);
}

void	bbm::MenuNewGame::drawAttr(const irr::core::dimension2du& screenSize)
{
	bbm::ButtonInfos	corners;
	const irr::core::dimension2du& imageSize = {200, screenSize.
		Height / 8};

	corners = bbm::Corners::getCenteredAudio(screenSize, {2, 3, 0, 6},
			imageSize);
	drawImage(corners, getImageByAttr(_attrs[0]));
	corners = bbm::Corners::getCenteredAudio(screenSize, {2, 3, 1, 6},
			imageSize);
	drawImage(corners, getImageByAttr(_attrs[1]));
	corners = bbm::Corners::getCenteredAudio(screenSize, {2, 3, 2, 6},
			imageSize);
	drawImage(corners, getImageByAttr(_attrs[2]));
	corners = bbm::Corners::getCenteredAudio(screenSize, {2, 3, 3, 6},
			imageSize);
	drawImage(corners, getImageByAttr(_attrs[3]));
	drawTeams(screenSize);
}

void	bbm::MenuNewGame::drawBackground(const irr::core::dimension2du&
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

void	bbm::MenuNewGame::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
		getDriver()->getScreenSize();

	drawBackground(screenSize);
	_lobby->draw(_attrs, _teams);
	drawAttr(screenSize);
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
