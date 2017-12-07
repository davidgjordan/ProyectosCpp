CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Norm)

ADD_COMPILE_OPTIONS(-std=c++11)

FILE(COPY "Match/template.json" DESTINATION ./)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(thirdParty/jsonlib)

SET(src_program 
		thirdParty/jsonlib/json.hpp	
		source/FileStatus.cpp
		source/JsonFile.cpp 
		source/JsonStatus.cpp 
		source/JsonSteps.cpp
		source/main.cpp
	)

ADD_EXECUTABLE(Norm ${src_program})
