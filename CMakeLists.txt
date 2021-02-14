cmake_minimum_required(VERSION 2.8)

project(boost_archive CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wc++11-extensions")

# we will use static libs
set(Boost_USE_STATIC_LIBS ON)

SET(Boost_USE_MULTITHREAD ON)

# Boost::log required Boost version >= 1.54.0 
find_package(Boost 1.54.0 REQUIRED COMPONENTS context coroutine date_time thread system program_options regex log)

find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(SRC_FILES
    src/main.cpp src/server.cpp src/server.h)

add_executable(boost_archive ${SRC_FILES})
target_link_libraries(boost_archive ${Boost_LIBRARIES}
        )
