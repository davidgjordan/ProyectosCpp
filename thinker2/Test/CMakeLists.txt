CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Newbie_test)

ADD_COMPILE_OPTIONS(-std=c++11)

FILE(COPY "../poc/RGBTool/RGB.json" DESTINATION ./)
FILE(COPY "../poc/RGBTool/render.txt" DESTINATION ./)
FILE(COPY "./partidas" DESTINATION ./)
FILE(COPY "../Configuration" DESTINATION ./)

FIND_PACKAGE(X11 REQUIRED)

ADD_DEFINITIONS(-DGTEST)

INCLUDE_DIRECTORIES(../include)
INCLUDE_DIRECTORIES(../Exceptions/include)
INCLUDE_DIRECTORIES(../thirdParty/jsonlib)
INCLUDE_DIRECTORIES(../thirdParty/gym-http-api/binding-cpp/include/gym)
INCLUDE_DIRECTORIES(../thirdParty/listenkey/include)
INCLUDE_DIRECTORIES(../libs/optionparser/include)
INCLUDE_DIRECTORIES(../thirdParty/CImg)
INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})
INCLUDE_DIRECTORIES(../poc/RGBTool/include)

ADD_SUBDIRECTORY(../thirdParty/googletest-master googletest)
ADD_SUBDIRECTORY(../libs/thinker thinker)
ADD_SUBDIRECTORY(../libs/optionparser  op)
ADD_SUBDIRECTORY(../thirdParty/gym-http-api/binding-cpp biding)
ADD_SUBDIRECTORY(../thirdParty/listenkey  key)
ADD_SUBDIRECTORY(../poc/RGBTool rgbTool)

SET(src_program 
		Main_TestAll.cpp		
		NewbieTest.cpp
		InstallNewbieTest.cpp
		NeuralNetworkTest.cpp
		Normalization_Test.cpp
		TransitionFunctionTest.cpp
		LayerTest.cpp
		MappingRGBTest.cpp
		ResizeRGBTest.cpp
		LevelVelocityTest.cpp
		PerceptronTest.cpp
		NeuralNetworkRGBTest.cpp
		NeuralNetworkRAMTest.cpp
		NeuralNetworkFullRAMTest.cpp
		TestNewbieLoad.cpp
		PlayerPathGameTest.cpp
		../source/Str2Image.cpp
		../source/Newbie.cpp 
		../source/NewbieDTO.cpp
		../source/Persistence.cpp
		../source/LevelVelocity.cpp
		../source/Player.cpp
		../source/Agent.cpp
		../source/BrainThinker.cpp
		../source/ActionPacman.cpp
		../source/SourceRAM.cpp
		../source/SourceFullRAM.cpp
		../source/SourceRGB.cpp
		../source/Trainner.cpp
		../source/SourceFullRAM.cpp
		../source/SourceRAM.cpp
		../source/SourceRGB.cpp
		../source/treeRam.cpp
		../source/StepPacman.cpp
		../source/GameModelPacman.cpp
		../source/Pacman.cpp
		../source/Ghost.cpp
		../source/Wall.cpp
		../source/Way.cpp
		../source/Controller.cpp
		../source/ControllerKey.cpp
		../source/CommandInstall.cpp
		../source/Filter.cpp
		../poc/RGBTool/source/Resize.cpp
		../poc/RGBTool/source/Evaluate.cpp
		../poc/RGBTool/source/Mapping.cpp
		../poc/RGBTool/source/RgbTool.cpp
		../Exceptions/source/ExceptionNoPath.cpp
		../Exceptions/source/ExceptionNoInstall.cpp
		../Exceptions/source/ExceptionNoMethod.cpp
		../Exceptions/source/ExceptionVelocity.cpp
		../Exceptions/source/ExceptionNoFile.cpp
		../Exceptions/source/ExceptionGame.cpp
	    ../libs/thinker/src/Normalization.cpp

		)

SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

ADD_EXECUTABLE(Newbie_test ${src_program})

TARGET_LINK_LIBRARIES(Newbie_test optionparserlib)
TARGET_LINK_LIBRARIES(Newbie_test bindinglib)
TARGET_LINK_LIBRARIES(Newbie_test listenkeylib)
TARGET_LINK_LIBRARIES(Newbie_test ${X11_LIBRARIES})
TARGET_LINK_LIBRARIES(Newbie_test thinker)
TARGET_LINK_LIBRARIES(Newbie_test poclib)
TARGET_LINK_LIBRARIES(Newbie_test gtest gtest_main -lpthread)

ADD_TEST(Newbie_test testi.exe)
