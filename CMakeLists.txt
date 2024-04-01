cmake_minimum_required(VERSION 3.27)
project(Yesodot_Project)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

Include(FetchContent)

FetchContent_Declare(
Catch2
GIT_REPOSITORY https://github.com/catchorg/Catch2.git
GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)
add_executable(tests UnitTests/test.cpp UnitTests/test.cpp
User.h User.cpp MyMain.cpp MyMain.h Field.h Field.cpp Date.h Date.cpp Player.h Player.cpp Favorites.h Favorites.cpp Field_manager.h Field_manager.cpp Booked.h Booked.cpp
sqlite3.h sqlite3.c Functions.h Functions.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)



include_directories(.)

add_executable(Yesodot_Project
        Functions.h
        User.h
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
        Booked.cpp
        Booked.h
)
