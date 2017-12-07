CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(newbie)

ADD_COMPILE_OPTIONS(-g -std=c++11)

FILE(COPY "poc/RGBTool/RGB.json" DESTINATION ./)
FILE(COPY "Configuration" DESTINATION ./)

FIND_PACKAGE(X11 REQUIRED)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(thirdParty/jsonlib)
INCLUDE_DIRECTORIES(thirdParty/gym-http-api/binding-cpp/include/gym)
INCLUDE_DIRECTORIES(thirdParty/listenkey/include)
INCLUDE_DIRECTORIES(Exceptions/include)
#INCLUDE_DIRECTORIES(libs/optionparser/include)
INCLUDE_DIRECTORIES(thirdParty/CImg)
INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})
INCLUDE_DIRECTORIES(poc/RGBTool/include)

ADD_SUBDIRECTORY(libs/optionparser)
ADD_SUBDIRECTORY(Exceptions)
ADD_SUBDIRECTORY(libs/thinker)
ADD_SUBDIRECTORY(thirdParty/gym-http-api/binding-cpp)
ADD_SUBDIRECTORY(thirdParty/listenkey)
ADD_SUBDIRECTORY(poc/RGBTool)

SET(src_program 
		thirdParty/jsonlib/json.hpp	
		source/Str2Image.cpp
		source/main.cpp 
		source/Newbie.cpp 
		source/NewbieDTO.cpp
		source/Persistence.cpp
		source/LevelVelocity.cpp
		source/Player.cpp
		source/Agent.cpp
		source/BrainThinker.cpp
		source/ActionPacman.cpp
		source/SourceRAM.cpp
		source/SourceRGB.cpp
		source/Filter.cpp
		source/Trainner.cpp
		source/SourceRAM.cpp
		source/SourceRGB.cpp
		source/SourceFullRAM.cpp
		source/treeRam.cpp
		source/StepPacman.cpp
		source/GameModelPacman.cpp
		source/Pacman.cpp
		source/Ghost.cpp
		source/Wall.cpp
		source/Way.cpp
		source/Controller.cpp
		source/CommandTrain.cpp
		source/CommandEvaluate.cpp
		source/CommandPlay.cpp
		source/CommandInstall.cpp
		source/CommandNewbie.cpp
		source/ControllerKey.cpp
	)

ADD_EXECUTABLE(newbie ${src_program})

TARGET_LINK_LIBRARIES(newbie optionparserlib)
TARGET_LINK_LIBRARIES(newbie bindinglib)
TARGET_LINK_LIBRARIES(newbie listenkeylib)
TARGET_LINK_LIBRARIES(newbie ${X11_LIBRARIES})
TARGET_LINK_LIBRARIES(newbie thinker)
TARGET_LINK_LIBRARIES(newbie exceptionslib)
TARGET_LINK_LIBRARIES(newbie poclib)
