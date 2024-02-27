cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Yesodot_Project
        User.h
        Functions.h
        Date.h
        Field.h
        MyMain.h
        Player.h
        Favorites.h
        Field_manager.h
        User.cpp
        Functions.cpp
        Date.cpp
        Field.cpp
        MyMain.cpp
        Player.cpp
        Favorites.cpp
        Field_manager.cpp
        main.cpp
        sqlite3.c
        sqlite3.h

)
