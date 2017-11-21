CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(Prueba)

ADD_COMPILE_OPTIONS(-g -std=c++11)

#FILE(COPY "poc/RGBTool/RGB.json" DESTINATION ./)
#FILE(COPY "Configuration" DESTINATION ./)

FIND_PACKAGE(X11 REQUIRED)

INCLUDE_DIRECTORIES(include)
#INCLUDE_DIRECTORIES(thirdParty/jsonlib)
#INCLUDE_DIRECTORIES(thirdParty/binding-cpp/include/gym)
#INCLUDE_DIRECTORIES(thirdParty/listenkey/include)
#INCLUDE_DIRECTORIES(Exceptions/include)
#INCLUDE_DIRECTORIES(libs/optionparser/include)
#INCLUDE_DIRECTORIES(thirdParty/CImg)
INCLUDE_DIRECTORIES(${X11_INCLUDE_DIR})

#ADD_SUBDIRECTORY(libs/optionparser)
#ADD_SUBDIRECTORY(Exceptions)
#ADD_SUBDIRECTORY(libs/thinker)
#ADD_SUBDIRECTORY(thirdParty/binding-cpp)
#ADD_SUBDIRECTORY(thirdParty/listenkey)

SET(src_program 
		#thirdParty/jsonlib/json.hpp	
		#source/Str2Image.cpp
		source/main.cpp 

	)
#main el nombre de mi ejecutable
ADD_EXECUTABLE(main ${src_program})

#TARGET_LINK_LIBRARIES(newbie optionparserlib)
#TARGET_LINK_LIBRARIES(newbie bindinglib)
#TARGET_LINK_LIBRARIES(newbie listenkeylib)
#TARGET_LINK_LIBRARIES(newbie ${X11_LIBRARIES})
#TARGET_LINK_LIBRARIES(newbie thinker)
#TARGET_LINK_LIBRARIES(newbie exceptionslib)
