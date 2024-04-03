cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)
set(PROJECT_HEADERS
        Functions.h
        User.h
        Date.h
        Field.h
        MyMain.h
        Player.h
        Favorites.h
        Field_manager.h
        sqlite3.h
        Booked.h
)
set(PROJECT_SOURCES
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
        Booked.cpp
        Clear_Screen.cpp
)

add_executable(Yesodot_Project ${PROJECT_SOURCES} ${PROJECT_HEADERS})
