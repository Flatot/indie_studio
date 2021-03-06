//
// EPITECH PROJECT, 2018
// IndieStudio
// File description:
// IPlayer.cpp
//

#include "IPlayer.hpp"
#include "Match.hpp"

bbm::IPlayer::IPlayer(Match &match, float z, float x, Entities playerNum,
		TeamColor team) :
	IEntity(match, x, z, true),
	_move(0),
	_timePoint(std::chrono::steady_clock::now()),
	_speed(0),
	_power(1),
	_bombCount(1),
	_passWall(false),
	_team(team)
{
	_idEntity = playerNum;
	_match.getMap().addEntity(this);
	getTexture();
	setCoefs(.15f, .15f, .15f);
	auto position = irr::core::vector3df(_x, 0.5f, _z);
	auto rotation = irr::core::vector3df(0, 0, 0);
	auto scale = irr::core::vector3df(_coefX, _coefY, _coefZ);
	auto scene = _match.getGraphic().getScene();
	auto mesh = scene->getMesh("./assets/model3D/player/ninja.b3d");
	if (!mesh) {
		std::cerr << "IPlayer constructor, "
			"scene->getMesh return nullptr" << std::endl;
		exit(84);
	}
	_mesh = scene->addAnimatedMeshSceneNode(mesh, 0, -1, position,
			rotation, scale);
	_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_mesh->setMaterialTexture(0, _match.getGraphic()
		.getDriver()->getTexture(_texture.c_str()));
}

bbm::IPlayer::~IPlayer()
{
	_match.getMap().removeEntity(this);
	_match.removePlayer(this);
}

void bbm::IPlayer::setFrameMyLoop(int begin, int end)
{
	auto animatedMesh = static_cast<
		irr::scene::IAnimatedMeshSceneNode *>(_mesh);
	if (animatedMesh->getStartFrame() != begin &&
		animatedMesh->getEndFrame() != end)
		animatedMesh->setFrameLoop(begin, end);
}

void bbm::IPlayer::analyseMap()
{
	this->analyseMap();
}

void bbm::IPlayer::die()
{
	_mesh->setVisible(false);
	delete this;
}

void bbm::IPlayer::getBonus()
{
	auto entity = _match.getMap().getEntity(_z, _x, BONUS);

	if (!entity)
		return;
	switch (entity->getType()) {
	case WALLPASS:
		_passWall = true;
		break;
	case BOMBUP:
		incBombCount();
		break;
	case SPEEDUP:
		_speed += 1;
		break;
	case FIREUP:
		++_power;
	}
	entity->die();
}

void bbm::IPlayer::move()
{
	auto timePoint = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::nanoseconds>
		(timePoint - _timePoint);

	if (diff.count() < 10000000)
		return;
	_timePoint = std::chrono::steady_clock::now();
	if (_move & LEFT)
		moveLeft();
	if (_move & RIGHT)
		moveRight();
	if (1) {
		if (_move & TOP)
			moveTop();
		if (_move & BOTTOM)
			moveBottom();
	}
	getBonus();
	(_move == 0) ? setFrameMyLoop(206, 250) : setFrameMyLoop(0, 13);
}

void	bbm::IPlayer::moveLeft()
{
	auto &map = _match.getMap();
	float new_x = _x - (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, -90.f, 0.f));
	if (std::floor(_x) != std::floor(new_x)) {
		if (!checkCollision(_z, new_x))
			return;
		map.removeEntity(this);
		_x = new_x;
		map.addEntity(this);
	} else
		_x = new_x;
}

void	bbm::IPlayer::moveRight()
{
	auto &map = _match.getMap();
	float new_x = _x + (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, 90.f, 0.f));
	if (std::floor(_x) != std::floor(new_x)) {
		if (!checkCollision(_z, new_x))
			return;
		map.removeEntity(this);
		_x = new_x;
		map.addEntity(this);
	} else
		_x = new_x;
}

void	bbm::IPlayer::moveTop()
{
	auto &map = _match.getMap();
	float new_z = _z + (0.1f + (0.01f * _speed));;

	_mesh->setRotation(irr::core::vector3df(0.f, 0.f, 0.f));
	if (std::floor(_z) != std::floor(new_z)) {
		if (!checkCollision(new_z, _x))
			return;
		map.removeEntity(this);
		_z = new_z;
		map.addEntity(this);
	} else
		_z = new_z;
}

void	bbm::IPlayer::moveBottom()
{
	auto &map = _match.getMap();
	float new_z = _z - (0.1f + (0.01f * _speed));

	_mesh->setRotation(irr::core::vector3df(0.f, 180.f, 0.f));
	if (std::floor(_z) != std::floor(new_z)) {
		if (!checkCollision(new_z, _x))
			return;
		map.removeEntity(this);
		_z = new_z;
		map.addEntity(this);
	} else
		_z = new_z;
}

void	bbm::IPlayer::putBomb()
{
	int idEntities = _match.getMap().getEntitiesFromPos(_z, _x);

	if (_bombCount <= 0 || (idEntities & BOMB) ||
			(idEntities & BREAKABLE_BLOCK))
		return;
	decBombCount();
	IEntity *bomb = new Bomb(_match, _z, _x, this);
	_match.addBomb(static_cast<Bomb *>(bomb));
	_match.getMap().addEntity(bomb);
}

int bbm::IPlayer::getPower()
{
	return _power;
}

void bbm::IPlayer::setPower(int power)
{
	_power = power;
}

void bbm::IPlayer::incPower()
{
	++_power;
}

void bbm::IPlayer::decPower()
{
	--_power;
}

int bbm::IPlayer::getBombCount() const
{
	return _bombCount;
}

void bbm::IPlayer::setBombCount(int bombCount)
{
	_bombCount = bombCount;
}


void bbm::IPlayer::incBombCount()
{
	++_bombCount;
}

void bbm::IPlayer::decBombCount()
{
	--_bombCount;
}

int bbm::IPlayer::getSpeed() const
{
	return _speed;
}

void bbm::IPlayer::setSpeed(int speed)
{
	_speed = speed;
}

void bbm::IPlayer::incSpeed()
{
	++_speed;
}

void bbm::IPlayer::decSpeed()
{
	--_speed;
}

bool bbm::IPlayer::getWallPass() const
{
	return _passWall;
}

void bbm::IPlayer::setWallPass(bool wallPass)
{
	_passWall = wallPass;
}

bbm::PlayerType bbm::IPlayer::getType() const
{
	return _type;
}

bbm::TeamColor bbm::IPlayer::getTeam()
{
	return _team;
}

bool bbm::IPlayer::checkCollision(int new_z, int new_x)
{
	int entities = _match.getMap().getEntitiesFromPos(new_z, new_x);

	if (entities & UNBREAKABLE_BLOCK)
		return false;
	if ((entities & BREAKABLE_BLOCK) || (entities & BOMB))
		return _passWall;
	return true;
}

std::string bbm::IPlayer::typeToStr()
{
	if (_type == PlayerType::AI)
		return "IA";
	return "PLAYER";
}

std::string bbm::IPlayer::entitiesToInt()
{
	switch(this->getIdEntity()) {
	case 4:
		return "0";
	case 8:
		return "1";
	case 16:
		return "2";
	case 32:
		return "3";
	default:
		return "0";
	}
}

std::string bbm::IPlayer::teamToStr()
{
	switch(this->getTeam()) {
	case TEAM_BLUE:
		return "TEAM_BLUE";
	case TEAM_GREEN:
		return "TEAM_GREEN";
	case TEAM_PURPLE:
		return "TEAM_PURPLE";
	case TEAM_RED:
		return "TEAM_RED";
	default:
		return "TEAM_RED";
	}
}

void bbm::IPlayer::getTexture()
{
	switch (_team) {
	case TeamColor::TEAM_BLUE:
		_texture = "assets/model3D/player/blue.jpg";
		break;
	case TeamColor::TEAM_RED:
		_texture = "assets/model3D/player/red.jpg";
		break;
	case TeamColor::TEAM_GREEN:
		_texture = "assets/model3D/player/green.jpg";
		break;
	case TeamColor::TEAM_PURPLE:
		_texture = "assets/model3D/player/purple.jpg";
		break;
	}
}

std::ostream& operator<< (std::ostream& stream, bbm::IPlayer *player)
{
	stream << player->entitiesToInt() << ":"
		<< player->typeToStr() << ":";
	stream << player->getPosX() << ":" << player->getPosZ()
		<< ":" << player->teamToStr() << std::endl;
	stream << "SPEED:" << std::to_string(player->getSpeed()) << std::endl;
	stream << "POWER:" << std::to_string(player->getPower()) << std::endl;
	stream << "BOMB_COUNT:" << std::to_string(player->getBombCount())
		<< std::endl;
	stream << "WALLPASS:" << std::boolalpha << player->getWallPass()
		<< std::endl;
	return stream;
}
