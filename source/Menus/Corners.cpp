//
// EPITECH PROJECT, 2018
// indie
// File description:
// corners calculation
//

#include "Corners.hpp"

bbm::ButtonInfos	bbm::Corners::getCenteredVertical(
	const irr::core::dimension2du& screenSize,
	bbm::Position pos,
	const irr::core::dimension2du& buttonSize)
{
	bbm::ButtonInfos	ret;

	ret.startX = (screenSize.Width / 2) + (screenSize.Width / 4) - (buttonSize.Width / 2);
	ret.startY = (screenSize.Height / pos.total * pos.
	index) + (screenSize.Height / pos.total / 2) - (buttonSize.Height / 2);
	ret.endX = (screenSize.Width / 2) + (screenSize.Width / 4) + (buttonSize.Width / 2);
	ret.endY = (screenSize.Height / pos.total * pos.
	index) + (screenSize.Height / pos.total / 2) + (buttonSize.Height / 2);
	return ret;
}

bbm::ButtonInfos	bbm::Corners::getCenteredHorizontal(
	const irr::core::dimension2du& screenSize,
	bbm::Position pos,
	const irr::core::dimension2du& buttonSize)
{
	bbm::ButtonInfos	ret;

	ret.startX = (screenSize.Width / pos.total * pos.
	index) + (screenSize.Width / pos.total / 2) - (buttonSize.Width / 2);
	ret.startY = (screenSize.Height / 2) - (buttonSize.Height / 2);
	ret.endX = (screenSize.Width / pos.total * pos.
	index) + (screenSize.Width / pos.total / 2) + (buttonSize.Width / 2);
	ret.endY = (screenSize.Height / 2) + (buttonSize.Height / 2);
	return ret;
}

bbm::ButtonInfos	bbm::Corners::getCenteredAudio(
	const irr::core::dimension2du& screenSize,
	bbm::PositionMultiple pos,
	const irr::core::dimension2du& buttonSize)
{
	bbm::ButtonInfos	ret;

	ret.startX = (screenSize.Width / pos.total * pos.index) + (screenSize.
	Width / pos.total / 2) - (buttonSize.Width / 2);
	ret.startY = (screenSize.Height / pos.topTotal * pos.
	topIndex) + (screenSize.Height / pos.topTotal / 2) - (buttonSize.
	Height / 2);
	ret.endX = (screenSize.Width / pos.total * pos.
	index) + (screenSize.Width / pos.total / 2) + (buttonSize.Width / 2);
	ret.endY = (screenSize.Height / pos.topTotal * pos.
	topIndex) + (screenSize.Height / pos.topTotal / 2) + (buttonSize.
	Height / 2);
	return ret;
}