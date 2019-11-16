cmake_minimum_required(VERSION 3.10)
project(NeuralNetworkSecondAttempt)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
add_executable(NeuralNetworkSecondAttempt main.cpp myVector.cpp myVector.h myMatrix.cpp myMatrix.h)