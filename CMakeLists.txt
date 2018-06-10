cmake_minimum_required(VERSION 3.2)
project(Bomberman)

set(BINARY_NAME bomberman)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-ggdb)

# CREATE IRRLICHT STATIC LIB FOR LINUX
set(IRRLICHT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Irrlicht)
add_custom_target(build_irrlicht ALL 
	COMMAND make 
	WORKING_DIRECTORY ${IRRLICHT_DIR}/source)
add_library(irrlicht STATIC IMPORTED)
add_dependencies(irrlicht build_irrlicht)

# GIVE LIB AND INCLUDE FOLDERS
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(${INCLUDE_DIR} ${INCLUDE_DIR}/irrlicht ${INCLUDE_DIR}/Menus)


# SOURCES FILES
set(SRCS 	source/main.cpp
		source/Game.cpp
		source/IMenu.cpp
		source/Match.cpp
		source/IEntity.cpp
		source/IBlock.cpp
		source/IPlayer.cpp
		source/Map.cpp
		source/Player.cpp
		source/Ia.cpp
		source/Graphic.cpp
		source/IMyEventReceiver.cpp
		source/EventManager.cpp
		source/Floor.cpp
		source/MapGenerator.cpp
		source/UnbreakableBlock.cpp
		source/BreakableBlock.cpp
		source/IBonus.cpp
		source/BombUp.cpp
		source/SpeedUp.cpp
		source/WallPass.cpp
		source/FireUp.cpp
		source/Config.cpp
		source/Bomb.cpp
		source/Explosion.cpp
		source/PlayerConfig.cpp
		source/Config.cpp
		source/Menus/MenuMain.cpp
		source/Menus/MenuInGame.cpp
		source/Menus/MenuSettings.cpp
		source/Menus/MenuAudio.cpp
		source/Menus/MenuVideo.cpp
		source/Menus/MenuNewGame.cpp
		source/Menus/MenuControls.cpp
		source/Menus/Corners.cpp
		source/Menus/Button.cpp
		)

# CREATE THE BINARY
add_executable(${BINARY_NAME} ${SRCS})

# GIVE THE LIBRARIES DEPENDENCIES TO THE BINARY
#target_link_libraries(${BINARY_NAME} Irrlicht GL X11 Xxf86vm IrrKlang)
target_link_libraries(${BINARY_NAME} Irrlicht GL X11 Xxf86vm sfml-audio)

install(TARGETS ${BINARY_NAME}
	RUNTIME DESTINATION .)
install(DIRECTORY assets
	DESTINATION .)
