//
// EPITECH PROJECT, 2018
// indie
// File description:
// menu video
//

#include "MenuVideo.hpp"
#include "Corners.hpp"

bbm::MenuVideo::MenuVideo(bbm::Game &Game, bool scene) :
	IMenu(Game),
	_idxres(0)
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
	_resolutions.push_back(std::pair<int, int>(1280, 720));
	_resolutions.push_back(std::pair<int, int>(1920, 1080));
	setupResolution(screenSize);
	_scene = scene;
	lookForResolution();
}

bbm::MenuVideo::~MenuVideo()
{
}

void	bbm::MenuVideo::lookForResolution()
{
	int	i = 0;

	for (auto it = _resolutions.begin(); it != _resolutions.end(); ++it) {
		if ((*it).first == _game.getConfig().getScreenWidth()
		&& (*it).second == _game.getConfig().getScreenHeight())
			_idxres = i;
		i++;
	}
}

void	bbm::MenuVideo::setupResolution(const irr::core::dimension2du&
screenSize)
{
	bbm::ButtonInfos corners = bbm::Corners::getCenteredAudio(
	screenSize, {1, 2, 0, 3}, {300, 80});
	irr::gui::IGUIFont *font = _game.getGraphic().
	getGuienv()->getFont("./assets/menus/font/font_indie.xml");

	_res = _game.getGraphic().getGuienv()->addStaticText(L"1280*720",
	irr::core::rect<irr::s32>(corners.startX, corners.startY,
	corners.endX, corners.endY), false, true, 0, -1, true);
	_res->setOverrideFont(font);
	_res->setVisible(false);
	_res->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
	corners = bbm::Corners::getCenteredAudio(
	screenSize, {1, 2, 1, 3}, {300, 80});
	_full = _game.getGraphic().getGuienv()->addStaticText(L"OFF",
	irr::core::rect<irr::s32>(corners.startX, corners.startY,
	corners.endX, corners.endY), false, true, 0, -1, true);
	_full->setOverrideFont(font);
	_full->setVisible(false);
	_full->setTextAlignment(irr::gui::EGUIA_CENTER,
	irr::gui::EGUIA_CENTER);
}

void	bbm::MenuVideo::setupButtons(
	const irr::core::dimension2du& screenSize,
	const irr::core::dimension2du& buttonSize)
{
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/screengray.png",
	"./assets/menus/buttons/screenblue.png",
	"./assets/menus/buttons/screenred.png",
	bbm::GUI_BUTTON_RESOLUTION, bbm::Corners::getCenteredAudio(screenSize,
	{0, 2, 0, 3}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/fullscreengray.png",
	"./assets/menus/buttons/fullscreenblue.png",
	"./assets/menus/buttons/fullscreenred.png",
	bbm::GUI_BUTTON_FULLSCREEN, bbm::Corners::getCenteredAudio(screenSize,
	{0, 2, 1, 3}, buttonSize), _game));
	_btns.push_back(new bbm::Button(
	"./assets/menus/buttons/backgray.png",
	"./assets/menus/buttons/backblue.png",
	"./assets/menus/buttons/backred.png",
	bbm::GUI_BUTTON_BACK, bbm::Corners::getCenteredAudio(screenSize,
	{1, 3, 2, 3}, buttonSize), _game));
	enableButtons(false);
}

bool	bbm::MenuVideo::takeActions(irr::s32 id)
{
	if (id == bbm::GUI_BUTTON_BACK)
		goBack();
	if (id == bbm::GUI_BUTTON_RESOLUTION) {
		updateResolution();
	}
	if (id == bbm::GUI_BUTTON_FULLSCREEN) {
		_game.getConfig().setFullscreen(
			!_game.getConfig().getFullscreen());
	}
	return true;
}

void	bbm::MenuVideo::goBack()
{
	deactivate();
	enableButtons(false);
	_res->setVisible(false);
	_full->setVisible(false);
}

void	bbm::MenuVideo::updateResolution()
{
	_game.getGraphic().setWidth(_resolutions[_idxres].first);
	_game.getGraphic().setHeight(_resolutions[_idxres].second);
	_game.getConfig().setScreenWidth(_resolutions[_idxres].first);
	_game.getConfig().setScreenHeight(_resolutions[_idxres].second);
	_game.getConfig().saveConfig();
}

bool	bbm::MenuVideo::changeResolution()
{
	if (isKeyPressed(irr::KEY_RIGHT, NONE)) {
		if (_focused == 0) {
			_idxres = _idxres + 1 >= _resolutions.size() ?
			0 : _idxres + 1;
		} else if (_focused == 1)
			_game.getConfig().setFullscreen(
				!_game.getConfig().getFullscreen());
		return true;
	}
	if (isKeyPressed(irr::KEY_LEFT, NONE)) {
		if (_focused == 0) {
			_idxres = _idxres - 1 < 0 ? _resolutions.size() - 1 :
			_idxres - 1;
		} else if (_focused == 1)
			_game.getConfig().setFullscreen(
				!_game.getConfig().getFullscreen());
		return true;
	}
	return false;
}

bool	bbm::MenuVideo::keysHandling(const irr::SEvent &event)
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
	return changeResolution();
}

bool	bbm::MenuVideo::OnEvent(const irr::SEvent &event)
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

void	bbm::MenuVideo::enableButtons(bool enabled)
{
	for(std::vector<bbm::Button *>::iterator it = _btns.
	begin(); it != _btns.end(); ++it) {
		(*it)->getButton()->setEnabled(enabled);
		(*it)->getButton()->setTabStop(enabled);
		(*it)->getButton()->setVisible(enabled);
	}
}

bool	bbm::MenuVideo::run()
{
	activate();
	_game.getGraphic().getGuienv()->setFocus(_btns[0]->getButton());
	_focused = 0;
	enableButtons(true);
	_res->setVisible(true);
	_full->setVisible(true);
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.getDriver()->beginScene(true, true,
		irr::video::SColor(255, 100, 101, 140));
		draw();
		_graphic.getDriver()->endScene();
	}
	deactivate();
	enableButtons(false);
	updateResolution();
	return true;
}

void	bbm::MenuVideo::drawRes(const irr::core::dimension2du& screenSize)
{
	wchar_t	text[100];

	swprintf(text, 100, L"%d * %d", _resolutions[_idxres].first,
	_resolutions[_idxres].second);
	_res->setText(text);
	_full->setText(_game.getConfig().getFullscreen() ? L"ON" : L"OFF");
}

void	bbm::MenuVideo::drawSceneBackground(const irr::core::dimension2du&
screenSize)
{
	_game.getGraphic().getScene()->drawAll();
	_game.getGraphic().getDriver()->draw2DRectangle(
		irr::video::SColor(110, 150, 150, 150),
		irr::core::rect<irr::s32>(0, 0, screenSize.Width,
		screenSize.Height));
}

void	bbm::MenuVideo::drawBackground(const irr::core::dimension2du&
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

void	bbm::MenuVideo::draw()
{
	const irr::core::dimension2du& screenSize = _game.getGraphic().
	getDriver()->getScreenSize();

	if (_scene)
		drawSceneBackground(screenSize);
	else
		drawBackground(screenSize);
	drawRes(screenSize);
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
