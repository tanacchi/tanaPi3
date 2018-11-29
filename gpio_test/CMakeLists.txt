cmake_minimum_required(VERSION 3.5.1)

project(
  led
  VERSION 0.0.0
  LANGUAGES CXX
)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}.out
  led.cpp
)
target_link_libraries(${PROJECT_NAME}.out wiringPi)
add_definitions(-lwiringPi )

