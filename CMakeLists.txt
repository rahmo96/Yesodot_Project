cmake_minimum_required(VERSION 3.24)
project(Yesodot_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Yesodot_Project
        Date.cpp
        Date.h
        Field.cpp
        Field.h
        main.cpp
        MyMain.cpp
        MyMain.h
        player.cpp
        player.h User.cpp)
