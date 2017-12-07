CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(test_evaluate)

INCLUDE_DIRECTORIES(../include)
ADD_COMPILE_OPTIONS(-std=c++11)

FILE(COPY "../RGB.json" DESTINATION ./)
FILE(COPY "../render.txt" DESTINATION ./)

SET(src_program 
		TestEvaluate.cpp 
		../source/RgbTool.cpp
		../source/Evaluate.cpp 
		../source/Mapping.cpp
		../source/Resize.cpp	
	)

ADD_EXECUTABLE(test_evaluate ${src_program})




