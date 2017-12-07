CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(test_mapping)

INCLUDE_DIRECTORIES(../include)
ADD_COMPILE_OPTIONS(-std=c++11)

FILE(COPY "../RGB.json" DESTINATION ./)
FILE(COPY "../render.txt" DESTINATION ./)
FILE(COPY "RenderFilesMapping" DESTINATION ./)

SET(src_program 
		TestMaping.cpp		
		../source/RgbTool.cpp
		../source/Evaluate.cpp 
		../source/Mapping.cpp
		../source/Resize.cpp	
	)

ADD_EXECUTABLE(test_mapping ${src_program})




