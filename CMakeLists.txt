cmake_minimum_required(VERSION 3.21)
project(LionProjects)

set(CMAKE_CXX_STANDARD 23)

add_executable(LionProjects "Source files/main.cpp" "Source files/Core.cpp" "Headers/Core.h" "Source files/Neuron.cpp" "Headers/Neuron.h" "Source files/Tests.cpp" "Headers/Tests.h")
