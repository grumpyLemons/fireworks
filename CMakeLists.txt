cmake_minimum_required(VERSION 3.19)
project(Simple_game)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

file(GLOB SAMPLE_HEADERS
        *.h
        ai/*.h
        audio/*.h
        core/*.h
        graphics/*.h
        input/*.h
        logic/*.h
        physics/*.h)

file(GLOB SAMPLE_SOURCES
        *.cpp
        ai/*.cpp
        audio/*.cpp
        core/*.cpp
        graphics/*.cpp
        input/*.cpp
        logic/*.cpp
        physics/*.cpp)
add_executable(Simple_game ${SAMPLE_HEADERS} ${SAMPLE_SOURCES})
target_link_libraries(Simple_game sfml-graphics sfml-audio)
target_include_directories(Simple_game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
