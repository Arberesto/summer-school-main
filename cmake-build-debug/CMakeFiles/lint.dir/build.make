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

# Utility rule file for lint.

# Include the progress variables for this target.
include CMakeFiles/lint.dir/progress.make

CMakeFiles/lint: ../src/Coin.cpp
CMakeFiles/lint: ../src/Coin.h
CMakeFiles/lint: ../src/FileManager.cpp
CMakeFiles/lint: ../src/FileManager.h
CMakeFiles/lint: ../src/Floor.cpp
CMakeFiles/lint: ../src/Floor.h
CMakeFiles/lint: ../src/Game.cpp
CMakeFiles/lint: ../src/Game.h
CMakeFiles/lint: ../src/GameRender.cpp
CMakeFiles/lint: ../src/GameRender.h
CMakeFiles/lint: ../src/InputController.cpp
CMakeFiles/lint: ../src/InputController.h
CMakeFiles/lint: ../src/LevelManager.cpp
CMakeFiles/lint: ../src/LevelManager.h
CMakeFiles/lint: ../src/Player.cpp
CMakeFiles/lint: ../src/Player.h
CMakeFiles/lint: ../src/ScoreBoard.cpp
CMakeFiles/lint: ../src/ScoreBoard.h
CMakeFiles/lint: ../src/Utility.cpp
CMakeFiles/lint: ../src/Utility.h
CMakeFiles/lint: ../src/Wall.cpp
CMakeFiles/lint: ../src/Wall.h
CMakeFiles/lint: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linting lint"
	/usr/bin/cmake -E chdir /home/arcades/CLionProjects/dmitrij-bagaev-main-game /usr/bin/python /home/arcades/CLionProjects/dmitrij-bagaev-main-game/misc/cpplint/cpplint.py --filter=-whitespace/ending_newline,-build/namespaces,-build/header_guard,-readability/todo,-readability/namespace,-legal/copyright, --counting=detailed --linelength=120 /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Coin.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Coin.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/FileManager.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/FileManager.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Floor.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Floor.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Game.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Game.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/GameRender.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/GameRender.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/InputController.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/InputController.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/LevelManager.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/LevelManager.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Player.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Player.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/ScoreBoard.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/ScoreBoard.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Utility.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Utility.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Wall.cpp /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/Wall.h /home/arcades/CLionProjects/dmitrij-bagaev-main-game/src/main.cpp

lint: CMakeFiles/lint
lint: CMakeFiles/lint.dir/build.make

.PHONY : lint

# Rule to build all files generated by this target.
CMakeFiles/lint.dir/build: lint

.PHONY : CMakeFiles/lint.dir/build

CMakeFiles/lint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lint.dir/clean

CMakeFiles/lint.dir/depend:
	cd /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arcades/CLionProjects/dmitrij-bagaev-main-game /home/arcades/CLionProjects/dmitrij-bagaev-main-game /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug /home/arcades/CLionProjects/dmitrij-bagaev-main-game/cmake-build-debug/CMakeFiles/lint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lint.dir/depend

