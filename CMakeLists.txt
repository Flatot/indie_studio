cmake_minimum_required(VERSION 3.2)
project(Bomberman)

set(BINARY_NAME bomberman)

set(CMAKE_CXX_STANDARD 14)

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
		source/Graphic.cpp
		source/IMyEventReceiver.cpp
		source/EventManager.cpp
		source/Config.cpp
		source/Menus/MenuMain.cpp
		source/Menus/MenuInGame.cpp
		source/Menus/MenuSettings.cpp
		source/Menus/MenuAudio.cpp
		source/Menus/Corners.cpp
		source/Floor.cpp
		)

# CREATE THE BINARY
add_executable(${BINARY_NAME} ${SRCS})

# GIVE THE LIBRARIES DEPENDENCIES TO THE BINARY
target_link_libraries(${BINARY_NAME} Irrlicht GL X11 Xxf86vm)
