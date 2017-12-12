CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(listenkeylib)

ADD_COMPILE_OPTIONS(-std=c++11)

INCLUDE_DIRECTORIES(include)


SET(libreria_key
	./source/ListenKey.cpp
)

ADD_LIBRARY(listenkeylib STATIC ${libreria_key})


TARGET_INCLUDE_DIRECTORIES(listenkeylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

