CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(exceptionslib)

ADD_COMPILE_OPTIONS(-std=c++11)

INCLUDE_DIRECTORIES(include)


SET(exception
	./source/ExceptionNoInstall.cpp
	./source/ExceptionNoPath.cpp
	./source/ExceptionNoMethod.cpp
	./source/ExceptionVelocity.cpp
	./source/ExceptionNoFile.cpp
	./source/ExceptionGame.cpp
)

ADD_LIBRARY(exceptionslib STATIC ${exception})


TARGET_INCLUDE_DIRECTORIES(exceptionslib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

