/*
** EPITECH PROJECT, 2018
** IndieStudio
** File description:
** Match.cpp
*/

#include <iostream>
#include "Match.hpp"
#include "Game.hpp"
#include "MapGenerator.hpp"
#include "Player.hpp"
#include "Ia.hpp"
#include "BombUp.hpp"
#include "SpeedUp.hpp"
#include "FireUp.hpp"
#include "WallPass.hpp"
#include "Bomb.hpp"

bbm::Match::Match(Game &game) :
	IMyEventReceiver(),
	_game(game),
	_graphic(game.getGraphic()),
	_evManager(new EventManager()),
	_floor(game.getGraphic()),
	_map(*this),
	_bombs(),
	_players(),
	_camera(),
	_counting(false)
{
	_evManager->addEventReceiver(this);
	// irr::SKeyMap keyMap[5];                    // re-assigne les commandes
	// keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
	// keyMap[0].KeyCode = irr::KEY_KEY_I;        // w
	// keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
	// keyMap[1].KeyCode = irr::KEY_KEY_K;        // s
	// keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
	// keyMap[2].KeyCode = irr::KEY_KEY_J;        // a
	// keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
	// keyMap[3].KeyCode = irr::KEY_KEY_L;        // d
	// keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
	// keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace

	// _camera = _graphic.getScene()->addCameraSceneNodeFPS(       // ajout de la camera FPS
	// 	0,                                     // pas de noeud parent
	// 	100.0f,                                // vitesse de rotation
	// 	0.01f,                                  // vitesse de deplacement
	// 	-1,                                    // pas de numero d'ID
	// 	keyMap,                                // on change la keymap
	// 	3);
	_camera = _graphic.getScene()->addCameraSceneNode(0,
			irr::core::vector3df(6.92f, 13.05f, 2.16f),
			irr::core::vector3df(6.94f, -1.82f, 5.70f));
}

void bbm::Match::init(std::vector<bbm::AttrEntity> attrs,
	std::vector<bbm::TeamColor> teams)
{
	std::cout << "begin init" << std::endl;
	_map.loadMap(MapGenerator::generate("./assets/maps/map1"));
	if (attrs[0] == bbm::ATTR_PLAYER)
		addPlayer(new Player(*this, 1.5, 1.5, PLAYER_1));
	else if (attrs[0] == bbm::ATTR_AI)
		addPlayer(new Ia(*this, 1.5, 1.5, PLAYER_1));
	if (attrs[1] == bbm::ATTR_PLAYER)
		addPlayer(new Player(*this, 11.5, 13.5, PLAYER_2));
	else if (attrs[1] == bbm::ATTR_AI)
		addPlayer(new Ia(*this, 11.5, 13.5, PLAYER_2));
	if (attrs[2] == bbm::ATTR_PLAYER)
		addPlayer(new Player(*this, 1.5, 13.5, PLAYER_3));
	else if (attrs[2] == bbm::ATTR_AI)
		addPlayer(new Ia(*this, 1.5, 13.5, PLAYER_3));
	if (attrs[3] == bbm::ATTR_PLAYER)
		addPlayer(new Player(*this, 11.5, 1.5, PLAYER_4));
	else if (attrs[3] == bbm::ATTR_AI)
		addPlayer(new Ia(*this, 11.5, 1.5, PLAYER_4));
	std::cout << _map << std::endl;
	std::cout << "height: " << _map.getHeight() << std::endl;
	std::cout << "width: " << _map.getWidth() << std::endl;
}

bool bbm::Match::OnEvent(const irr::SEvent &event)
{
	IMyEventReceiver::OnEvent(event);

	std::cout << "[OnEvent - Match]" << std::endl;
	if (isKeyPressed(irr::KEY_ESCAPE, NONE) && !_counting) {
		deactivate();
		resetKey(irr::KEY_ESCAPE, NONE);
		_menuReturn = _game.getMenuInGame()->run();
		resetKey(irr::KEY_ESCAPE, NONE);
		if (_menuReturn) {
			drawStarter();
			activate();
		}
		return true;
	}
	return false;
}

void bbm::Match::draw()
{

}

void bbm::Match::print_skybase()
{
	std::string path = "assets/model3D/Sky/brouillard.jpg";
	auto texture = _graphic.getDriver()->getTexture(path.c_str());
	auto skybase = _graphic.getScene()->addSkyBoxSceneNode(texture, 
			texture, texture, texture, texture, texture);
}

void bbm::Match::drawStarterRec(irr::video::ITexture *background)
{
	
}

std::vector<irr::video::ITexture *>	bbm::Match::createCounter()
{
	std::vector<irr::video::ITexture *>	ret;

	ret.push_back(_game.getGraphic().getDriver()->
	getTexture("./assets/gameplay/3.png"));
	ret.push_back(_game.getGraphic().getDriver()->
	getTexture("./assets/gameplay/2.png"));
	ret.push_back(_game.getGraphic().getDriver()->
	getTexture("./assets/gameplay/1.png"));
	ret.push_back(_game.getGraphic().getDriver()->
	getTexture("./assets/gameplay/fight.png"));
	return ret;
}

irr::video::ITexture	*bbm::Match::getCurrentCounter(
	std::vector<irr::video::ITexture *> list, int count)
{
	irr::video::ITexture	*ret = list[0];

	if (count > 0)
		ret = list[0];
	if (count >= 1)
		ret = list[1];
	if (count >= 2)
		ret = list[2];
	if (count >= 3)
		ret = list[3];
	return ret;
}

void bbm::Match::drawImageBack(const irr::core::dimension2du& screenSize,
	irr::video::ITexture *img)
{
	_graphic.getDriver()->beginScene(true, true,
	irr::video::SColor(255, 100, 101, 140));
	_graphic.getScene()->drawAll();
	_graphic.getDriver()->draw2DImage(img,
	irr::core::rect<irr::s32>(screenSize.Width / 5 * 2,
	screenSize.Height / 5 * 2, screenSize.Width / 5 * 3,
	screenSize.Height / 5 * 3),
	irr::core::rect<irr::s32>(0, 0, img->
	getSize().Width, img->getSize().Height), 0, 0, true);
	_graphic.getDriver()->draw2DRectangle(
	irr::video::SColor(110, 150, 150, 150),
	irr::core::rect<irr::s32>(0, 0, screenSize.Width,
	screenSize.Height));
	_graphic.getGuienv()->drawAll();
	_graphic.getDriver()->endScene();
}

void bbm::Match::drawStarter()
{
	const irr::core::dimension2du& screenSize = _graphic.
		getDriver()->getScreenSize();
	auto list = createCounter();
	auto cTime = std::chrono::steady_clock::now();
	auto nTime = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::seconds>
	(nTime - cTime);

	_counting = true;
	print_skybase();
	_graphic.getDriver()->enableMaterial2D();
	while (_graphic.getDevice()->run() && diff.count() < 4) {
		nTime = std::chrono::steady_clock::now();
		diff = std::chrono::duration_cast<std::chrono::seconds>
		(nTime - cTime);
		drawImageBack(screenSize,
			getCurrentCounter(list, diff.count()));
	}
	_graphic.getDriver()->enableMaterial2D(false);
	_counting = false;
}

bool bbm::Match::run()
{
	drawStarter();
	activate();

	print_skybase();
	while(_graphic.getDevice()->run() && isActive()) {
		_graphic.setWindowCaption(_camera->getPosition(), L"Match loop");
		_graphic.getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		// auto lala = _camera->getTarget();
		// std::cout << "x : " << lala.X << " y : " << lala.Y << " z : " << lala.Z << std::endl;
		_graphic.getScene()->drawAll();
		_graphic.getDriver()->endScene();
		update();
	}
	_map.clear();
	_players.clear();
	_bombs.clear();
	deactivate();
	return true;
}

void bbm::Match::update()
{
	int lastSize;

	for (auto it = _players.begin(); it < _players.end(); ++it)
		(*it)->update();
	lastSize = _bombs.size();
	for (int i = 0; i < _bombs.size(); ++i) {
		_bombs[i]->update();
		if (lastSize != _bombs.size()) {
			lastSize = _bombs.size();
			--i;
		}
	}
}

bbm::EventManager *bbm::Match::getEventManager()
{
	return _evManager;
}

bbm::Graphic &bbm::Match::getGraphic()
{
	return _graphic;
}

bbm::Map &bbm::Match::getMap()
{
	return _map;
}

bbm::Game &bbm::Match::getGame()
{
	return _game;
}

void bbm::Match::addBomb(Bomb *bomb)
{
	_bombs.push_back(bomb);
}

void bbm::Match::removeBomb(Bomb *bomb)
{
	for (auto it = _bombs.begin(); it != _bombs.end(); ++it)
		if (*it == bomb)
			_bombs.erase(it--);
}

void bbm::Match::addPlayer(IPlayer *player)
{
	if (!player)
	{
		std::cout << "player null" << std::endl;
		return;
	}
	_players.push_back(player);
}

void bbm::Match::removePlayer(IPlayer *player)
{
	for (auto it = _players.begin(); it != _players.end(); ++it) {
		if (*it == player) {
			_players.erase(it--);
		}
	}
}

void bbm::Match::save()
{
	std::ofstream myfile;

	_map.save();
	myfile.open("PlayerMatch.cfg");
	if (myfile.is_open() == false)
		return;
	for(unsigned int i = 0; i < _players.size(); i++) {
		myfile << _players[i] << std::endl;
	}
	myfile.close();
}

bbm::IPlayer *bbm::Match::createPlayer(std::string line)
{
	size_t pos = 0;
	std::string type;
	std::string x;
	std::string z;
	std::string number;
	std::string delimiter = ":";
	std::string::size_type sz;

	pos = line.find(delimiter);
	number = line.substr(0, pos);
	line.erase(0, pos + delimiter.length());
	pos = line.find(delimiter);
	type = line.substr(0, pos);
	line.erase(0, pos + delimiter.length());
	pos = line.find(delimiter);
	x = line.substr(0, pos);
	line.erase(0, pos + delimiter.length());
	z = line;
	if (type.compare("IA") == 0)
		return (new Ia(*this, stoi(z, &sz), stoi(x, &sz), entities[stoi(number, &sz)]));
	return (new Player(*this, stoi(z, &sz), stoi(x, &sz), entities[stoi(number, &sz)]));
}

void bbm::Match::handleLine(std::string line, int i, bbm::IPlayer **player)
{
	size_t pos = 0;
	std::string firstTok;
	std::string delimiter = ":";
	std::string token;
	std::string::size_type sz;

	pos = line.find(delimiter);
	token = line.substr(0, pos);
	firstTok = token;
	if (this->isValuable(firstTok) && firstTok.compare(valuable[i]) == 0) {
		*player = this->createPlayer(line);
	}
	else if (this->isValuable(firstTok))
		return;
	line.erase(0, pos + delimiter.length());
	doWithTokens(firstTok, line, player);
}

bool bbm::Match::isValuable(std::string str)
{
	for (int i = 0; i < 4; i++) {
		if (valuable[i].compare(str) == 0)
			return true;
	}
	return false;
}

void bbm::Match::doWithTokens(std::string tok1, std::string tok2, bbm::IPlayer **player)
{
	std::string::size_type sz;

	if (tok1.compare("WALLPASS") == 0 && *player)
		(*player)->setWallPass(tok2.compare("false"));
	if (tok1.compare("SPEED") == 0 && (*player))
		(*player)->setSpeed(std::stoi(tok2, &sz));
	if (tok1.compare("BOMB_COUNT") == 0 && (*player))
		(*player)->setBombCount(std::stoi(tok2, &sz));
	if (tok1.compare("POWER") == 0 && (*player))
		(*player)->setPower(std::stoi(tok2, &sz));
}

bool bbm::Match::hasSave()
{
	std::ifstream file("PlayerMatch.cfg");

	if (!file)
		return false;
	file.close();
	return true;
}


bbm::IPlayer *bbm::Match::loadIPlayer(int nbPlayer)
{
	std::ifstream file("PlayerMatch.cfg");
	std::string line;
	bbm::IPlayer *player = nullptr;

	if (!file) {
		std::cout << "file null" << std::endl;
		return player;
	}
	while (std::getline(file, line)) {
		this->handleLine(line, nbPlayer, &player);
	}
	if (player)
	{
		std::cout << "FINAL PLAYER" << std::endl;
		std::cout << player << std::endl;
		std::cout << "FINAL PLAYER FIN" << std::endl;
	}
	return player;
}

void bbm::Match::load()
{
	_map.load();
	for(int i = 0; i < 4; i++) {
		this->addPlayer(this->loadIPlayer(i));
	}
}