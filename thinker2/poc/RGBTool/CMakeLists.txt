CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(poclib)

ADD_COMPILE_OPTIONS(-std=c++11)

INCLUDE_DIRECTORIES(include)

SET(libreria_poc
	./source/Evaluate.cpp
	./source/Mapping.cpp
	./source/Resize.cpp
	./source/RgbTool.cpp
)

ADD_LIBRARY(poclib STATIC ${libreria_poc})


TARGET_INCLUDE_DIRECTORIES(poclib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

