# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arcades/CLionProjects/dmitrij-bagaev-main-game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dmitrij-bagaev-main-game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dmitrij-bagaev-main-game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/main.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/main.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/main.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o: ../src/GameRender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/GameRender.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/GameRender.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/GameRender.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o: ../src/InputController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/InputController.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/InputController.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/InputController.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o: ../src/LevelManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/LevelManager.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/LevelManager.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/LevelManager.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o: ../src/Utility.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Utility.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Utility.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Utility.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o: ../src/ScoreBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/ScoreBoard.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/ScoreBoard.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/ScoreBoard.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o: ../src/FileManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/FileManager.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/FileManager.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/FileManager.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Player.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Player.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Player.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o: ../src/Coin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Coin.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Coin.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Coin.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o: ../src/Floor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Floor.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Floor.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Floor.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o: ../src/Wall.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Wall.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Wall.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Wall.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o


CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o: CMakeFiles/dmitrij-bagaev-main-game.dir/flags.make
CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o -c /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Game.cpp

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Game.cpp > CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.i

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Game.cpp -o CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.s

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.requires:

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.requires

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.provides: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/dmitrij-bagaev-main-game.dir/build.make CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.provides.build
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.provides

CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.provides.build: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o


# Object files for target dmitrij-bagaev-main-game
dmitrij__bagaev__main__game_OBJECTS = \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o" \
"CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o"

# External object files for target dmitrij-bagaev-main-game
dmitrij__bagaev__main__game_EXTERNAL_OBJECTS =

dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/build.make
dmitrij-bagaev-main-game: /usr/lib/x86_64-linux-gnu/libcurses.so
dmitrij-bagaev-main-game: CMakeFiles/dmitrij-bagaev-main-game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable dmitrij-bagaev-main-game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dmitrij-bagaev-main-game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dmitrij-bagaev-main-game.dir/build: dmitrij-bagaev-main-game

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/build

CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/main.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/GameRender.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/InputController.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/LevelManager.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Utility.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/ScoreBoard.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/FileManager.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Player.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Coin.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Floor.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Wall.cpp.o.requires
CMakeFiles/dmitrij-bagaev-main-game.dir/requires: CMakeFiles/dmitrij-bagaev-main-game.dir/src/Game.cpp.o.requires

.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/requires

CMakeFiles/dmitrij-bagaev-main-game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dmitrij-bagaev-main-game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/clean

CMakeFiles/dmitrij-bagaev-main-game.dir/depend:
	cd /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arcades/CLionProjects/dmitrij-bagaev-main-game /home/arcades/CLionProjects/dmitrij-bagaev-main-game /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles/dmitrij-bagaev-main-game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dmitrij-bagaev-main-game.dir/depend

