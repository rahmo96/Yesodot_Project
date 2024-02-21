cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Yesodot_Project
        Field.h
        main.cpp
        Player.cpp
        Player.h
        Date.h
        MyMain.h
        Date.cpp
        MyMain.cpp
        Field.cpp
        User.h
        User.cpp
        Field_manager.h
        Field_manager.cpp)
