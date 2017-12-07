project(thinker)
cmake_minimum_required(VERSION 2.8.9)

add_compile_options(-std=c++11)

include_directories(include)
include_directories(thirdParty/jsonlib)

set(libthinker_SRCS 
	./src/Perceptron.cpp 
	./src/NeuralNetworkDTO.cpp
	./src/PerceptronDTO.cpp
	./src/TransitionByStep.cpp 
	./src/TransitionSoftMax.cpp
	./src/TransitionHiperbolicTangent.cpp
	./src/TransitionSigmoid.cpp
	./src/BrainPersistence.cpp
	./src/Layer.cpp
	./src/NeuralNetwork.cpp
	./src/Data.cpp
	./src/Normalization.cpp

)

add_library(thinker STATIC
    ${libthinker_SRCS}
)

target_include_directories(thinker PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# set(main main.cpp)

# add_executable(Neural
#     ${main}
#  )
# target_link_libraries(Neural
#     thinker
# )

