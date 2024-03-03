cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(.)

add_executable(Yesodot_Project
        Functions.h
        User.h

        Date.h
        Field.h
        FieldManager.h
        Player.h
        Favorites.h
        Field_manager.h
        User.cpp
        Functions.cpp
        Date.cpp
        Field.cpp
        FieldManager.cpp
        Player.cpp
        Favorites.cpp
        Field_manager.cpp
        main.cpp
        sqlite3.c
        sqlite3.h
        Booked.cpp
        Booked.h

)
