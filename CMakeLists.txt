cmake_minimum_required(VERSION 3.12)

project(TestTasks)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

file(GLOB 2GIS_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/2gis/*.cpp)
file(GLOB ASTARTA_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/Astarta/*.cpp)

add_executable(2gisTest ${2GIS_TEST_SRC})
add_executable(AstartaTest ${ASTARTA_TEST_SRC})