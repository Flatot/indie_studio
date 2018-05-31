//
// EPITECH PROJECT, 2018
// main.cpp
// File description:
// main
//

#include "irrlicht.h"
#include "Game.hpp"

int main()
{
	irr::IrrlichtDevice *device = irr::createDevice(
					irr::video::EDT_SOFTWARE, 
					irr::core::dimension2d<irr::u32>(640, 480), 
					32, false, false, false, 0
					);
	irr::video::IVideoDriver *driver = device->getVideoDriver();
	irr::scene::ISceneManager *smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment *guienv = device->getGUIEnvironment();

	device->setWindowCaption(L"Bomberman");
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
			irr::core::rect<irr::s32>(10,10,260,22), false);
	// bbm::Game game;
	auto camera = smgr->addCameraSceneNode (0, irr::core::vector3df(-0.259f, 4.27f, -1.4f), irr::core::vector3df (0,0,0));
	/* CAMERA */
    
	// irr::SKeyMap keyMap[5];                    // re-assigne les commandes
	// keyMap[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
	// keyMap[0].KeyCode = irr::KEY_KEY_W;        // w
	// keyMap[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
	// keyMap[1].KeyCode = irr::KEY_KEY_S;        // s
	// keyMap[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
	// keyMap[2].KeyCode = irr::KEY_KEY_A;        // a
	// keyMap[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
	// keyMap[3].KeyCode = irr::KEY_KEY_D;        // d
	// keyMap[4].Action = irr::EKA_JUMP_UP;       // saut
	// keyMap[4].KeyCode = irr::KEY_SPACE;        // barre espace

	// auto camera = smgr->addCameraSceneNodeFPS(       // ajout de la camera FPS
	// 	0,                                     // pas de noeud parent
	// 	100.0f,                                // vitesse de rotation
	// 	0.01f,                                  // vitesse de deplacement
	// 	-1,                                    // pas de numero d'ID
	// 	keyMap,                                // on change la keymap
	// 	3);                                    // avec une taille de 5

	irr::scene::IAnimatedMeshSceneNode *bomberman =
    	smgr->addAnimatedMeshSceneNode (smgr->getMesh("../assets/model3D/bomb/Bomb_3ds/Bomb.3ds"));

	bomberman->setMaterialFlag(
	irr::video::EMF_LIGHTING, false);
	bomberman->setMaterialTexture(0, driver->getTexture("../assets/model3D/bomb/Bomb_3ds/Rough.png"));
 	
	bomberman->setMD2Animation(irr::scene::EMAT_STAND);

	irr::core::vector3df posCam;

	while(device->run()) {
		driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
		posCam = camera->getPosition();
		wchar_t titre[100];
		swprintf(titre, 100, L"X : %f Y : %f Z : %f", posCam.X, posCam.Y, posCam.Z);
		device->setWindowCaption(titre);

		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
	device->drop();

	return 0;
}
