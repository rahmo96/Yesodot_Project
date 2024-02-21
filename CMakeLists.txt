cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Yesodot_Project
        .idea/.gitignore
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .idea/Yesodot_Project.iml
        Date.cpp
        Date.h
        Field.cpp
        Field.h
        main.cpp
        MyMain.cpp
        MyMain.h
        player.cpp
        player.h
        Favorites.cpp
        Favorites.h)
