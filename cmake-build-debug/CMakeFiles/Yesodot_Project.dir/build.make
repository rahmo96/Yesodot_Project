# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/haikarmi/CLionProjects/Yesodot_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Yesodot_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Yesodot_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Yesodot_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yesodot_Project.dir/flags.make

CMakeFiles/Yesodot_Project.dir/User.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/User.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/User.cpp
CMakeFiles/Yesodot_Project.dir/User.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Yesodot_Project.dir/User.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/User.cpp.o -MF CMakeFiles/Yesodot_Project.dir/User.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/User.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/User.cpp

CMakeFiles/Yesodot_Project.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/User.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/User.cpp > CMakeFiles/Yesodot_Project.dir/User.cpp.i

CMakeFiles/Yesodot_Project.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/User.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/User.cpp -o CMakeFiles/Yesodot_Project.dir/User.cpp.s

CMakeFiles/Yesodot_Project.dir/Functions.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Functions.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Functions.cpp
CMakeFiles/Yesodot_Project.dir/Functions.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Yesodot_Project.dir/Functions.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Functions.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Functions.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Functions.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Functions.cpp

CMakeFiles/Yesodot_Project.dir/Functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Functions.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Functions.cpp > CMakeFiles/Yesodot_Project.dir/Functions.cpp.i

CMakeFiles/Yesodot_Project.dir/Functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Functions.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Functions.cpp -o CMakeFiles/Yesodot_Project.dir/Functions.cpp.s

CMakeFiles/Yesodot_Project.dir/Date.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Date.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Date.cpp
CMakeFiles/Yesodot_Project.dir/Date.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Yesodot_Project.dir/Date.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Date.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Date.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Date.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Date.cpp

CMakeFiles/Yesodot_Project.dir/Date.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Date.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Date.cpp > CMakeFiles/Yesodot_Project.dir/Date.cpp.i

CMakeFiles/Yesodot_Project.dir/Date.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Date.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Date.cpp -o CMakeFiles/Yesodot_Project.dir/Date.cpp.s

CMakeFiles/Yesodot_Project.dir/Field.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Field.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Field.cpp
CMakeFiles/Yesodot_Project.dir/Field.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Yesodot_Project.dir/Field.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Field.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Field.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Field.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Field.cpp

CMakeFiles/Yesodot_Project.dir/Field.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Field.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Field.cpp > CMakeFiles/Yesodot_Project.dir/Field.cpp.i

CMakeFiles/Yesodot_Project.dir/Field.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Field.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Field.cpp -o CMakeFiles/Yesodot_Project.dir/Field.cpp.s

CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/MyMain.cpp
CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o -MF CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/MyMain.cpp

CMakeFiles/Yesodot_Project.dir/MyMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/MyMain.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/MyMain.cpp > CMakeFiles/Yesodot_Project.dir/MyMain.cpp.i

CMakeFiles/Yesodot_Project.dir/MyMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/MyMain.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/MyMain.cpp -o CMakeFiles/Yesodot_Project.dir/MyMain.cpp.s

CMakeFiles/Yesodot_Project.dir/Player.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Player.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Player.cpp
CMakeFiles/Yesodot_Project.dir/Player.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Yesodot_Project.dir/Player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Player.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Player.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Player.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Player.cpp

CMakeFiles/Yesodot_Project.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Player.cpp > CMakeFiles/Yesodot_Project.dir/Player.cpp.i

CMakeFiles/Yesodot_Project.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Player.cpp -o CMakeFiles/Yesodot_Project.dir/Player.cpp.s

CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Favorites.cpp
CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Favorites.cpp

CMakeFiles/Yesodot_Project.dir/Favorites.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Favorites.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Favorites.cpp > CMakeFiles/Yesodot_Project.dir/Favorites.cpp.i

CMakeFiles/Yesodot_Project.dir/Favorites.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Favorites.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Favorites.cpp -o CMakeFiles/Yesodot_Project.dir/Favorites.cpp.s

CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/Field_manager.cpp
CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o -MF CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/Field_manager.cpp

CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/Field_manager.cpp > CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.i

CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/Field_manager.cpp -o CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.s

CMakeFiles/Yesodot_Project.dir/main.cpp.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/main.cpp.o: /Users/haikarmi/CLionProjects/Yesodot_Project/main.cpp
CMakeFiles/Yesodot_Project.dir/main.cpp.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Yesodot_Project.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/main.cpp.o -MF CMakeFiles/Yesodot_Project.dir/main.cpp.o.d -o CMakeFiles/Yesodot_Project.dir/main.cpp.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/main.cpp

CMakeFiles/Yesodot_Project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Yesodot_Project.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/main.cpp > CMakeFiles/Yesodot_Project.dir/main.cpp.i

CMakeFiles/Yesodot_Project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Yesodot_Project.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/main.cpp -o CMakeFiles/Yesodot_Project.dir/main.cpp.s

CMakeFiles/Yesodot_Project.dir/sqlite3.c.o: CMakeFiles/Yesodot_Project.dir/flags.make
CMakeFiles/Yesodot_Project.dir/sqlite3.c.o: /Users/haikarmi/CLionProjects/Yesodot_Project/sqlite3.c
CMakeFiles/Yesodot_Project.dir/sqlite3.c.o: CMakeFiles/Yesodot_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/Yesodot_Project.dir/sqlite3.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Yesodot_Project.dir/sqlite3.c.o -MF CMakeFiles/Yesodot_Project.dir/sqlite3.c.o.d -o CMakeFiles/Yesodot_Project.dir/sqlite3.c.o -c /Users/haikarmi/CLionProjects/Yesodot_Project/sqlite3.c

CMakeFiles/Yesodot_Project.dir/sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Yesodot_Project.dir/sqlite3.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/haikarmi/CLionProjects/Yesodot_Project/sqlite3.c > CMakeFiles/Yesodot_Project.dir/sqlite3.c.i

CMakeFiles/Yesodot_Project.dir/sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Yesodot_Project.dir/sqlite3.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/haikarmi/CLionProjects/Yesodot_Project/sqlite3.c -o CMakeFiles/Yesodot_Project.dir/sqlite3.c.s

# Object files for target Yesodot_Project
Yesodot_Project_OBJECTS = \
"CMakeFiles/Yesodot_Project.dir/User.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Functions.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Date.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Field.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Player.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/main.cpp.o" \
"CMakeFiles/Yesodot_Project.dir/sqlite3.c.o"

# External object files for target Yesodot_Project
Yesodot_Project_EXTERNAL_OBJECTS =

Yesodot_Project: CMakeFiles/Yesodot_Project.dir/User.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Functions.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Date.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Field.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/MyMain.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Player.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Favorites.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/Field_manager.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/main.cpp.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/sqlite3.c.o
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/build.make
Yesodot_Project: CMakeFiles/Yesodot_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Yesodot_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Yesodot_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yesodot_Project.dir/build: Yesodot_Project
.PHONY : CMakeFiles/Yesodot_Project.dir/build

CMakeFiles/Yesodot_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Yesodot_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Yesodot_Project.dir/clean

CMakeFiles/Yesodot_Project.dir/depend:
	cd /Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/haikarmi/CLionProjects/Yesodot_Project /Users/haikarmi/CLionProjects/Yesodot_Project /Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug /Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug /Users/haikarmi/CLionProjects/Yesodot_Project/cmake-build-debug/CMakeFiles/Yesodot_Project.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Yesodot_Project.dir/depend
