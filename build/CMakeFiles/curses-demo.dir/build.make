# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rileyfischer/Documents/dev/school/TetrisNCurses

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rileyfischer/Documents/dev/school/TetrisNCurses/build

# Include any dependencies generated for this target.
include CMakeFiles/curses-demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/curses-demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/curses-demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/curses-demo.dir/flags.make

CMakeFiles/curses-demo.dir/src/main.cpp.o: CMakeFiles/curses-demo.dir/flags.make
CMakeFiles/curses-demo.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/curses-demo.dir/src/main.cpp.o: CMakeFiles/curses-demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/curses-demo.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/curses-demo.dir/src/main.cpp.o -MF CMakeFiles/curses-demo.dir/src/main.cpp.o.d -o CMakeFiles/curses-demo.dir/src/main.cpp.o -c /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/main.cpp

CMakeFiles/curses-demo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curses-demo.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/main.cpp > CMakeFiles/curses-demo.dir/src/main.cpp.i

CMakeFiles/curses-demo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curses-demo.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/main.cpp -o CMakeFiles/curses-demo.dir/src/main.cpp.s

CMakeFiles/curses-demo.dir/src/game.cpp.o: CMakeFiles/curses-demo.dir/flags.make
CMakeFiles/curses-demo.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/curses-demo.dir/src/game.cpp.o: CMakeFiles/curses-demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/curses-demo.dir/src/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/curses-demo.dir/src/game.cpp.o -MF CMakeFiles/curses-demo.dir/src/game.cpp.o.d -o CMakeFiles/curses-demo.dir/src/game.cpp.o -c /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/game.cpp

CMakeFiles/curses-demo.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curses-demo.dir/src/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/game.cpp > CMakeFiles/curses-demo.dir/src/game.cpp.i

CMakeFiles/curses-demo.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curses-demo.dir/src/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/game.cpp -o CMakeFiles/curses-demo.dir/src/game.cpp.s

CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o: CMakeFiles/curses-demo.dir/flags.make
CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o: ../src/tetrimino.cpp
CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o: CMakeFiles/curses-demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o -MF CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o.d -o CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o -c /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/tetrimino.cpp

CMakeFiles/curses-demo.dir/src/tetrimino.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curses-demo.dir/src/tetrimino.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/tetrimino.cpp > CMakeFiles/curses-demo.dir/src/tetrimino.cpp.i

CMakeFiles/curses-demo.dir/src/tetrimino.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curses-demo.dir/src/tetrimino.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/tetrimino.cpp -o CMakeFiles/curses-demo.dir/src/tetrimino.cpp.s

CMakeFiles/curses-demo.dir/src/L.cpp.o: CMakeFiles/curses-demo.dir/flags.make
CMakeFiles/curses-demo.dir/src/L.cpp.o: ../src/L.cpp
CMakeFiles/curses-demo.dir/src/L.cpp.o: CMakeFiles/curses-demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/curses-demo.dir/src/L.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/curses-demo.dir/src/L.cpp.o -MF CMakeFiles/curses-demo.dir/src/L.cpp.o.d -o CMakeFiles/curses-demo.dir/src/L.cpp.o -c /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/L.cpp

CMakeFiles/curses-demo.dir/src/L.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curses-demo.dir/src/L.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/L.cpp > CMakeFiles/curses-demo.dir/src/L.cpp.i

CMakeFiles/curses-demo.dir/src/L.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curses-demo.dir/src/L.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rileyfischer/Documents/dev/school/TetrisNCurses/src/L.cpp -o CMakeFiles/curses-demo.dir/src/L.cpp.s

# Object files for target curses-demo
curses__demo_OBJECTS = \
"CMakeFiles/curses-demo.dir/src/main.cpp.o" \
"CMakeFiles/curses-demo.dir/src/game.cpp.o" \
"CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o" \
"CMakeFiles/curses-demo.dir/src/L.cpp.o"

# External object files for target curses-demo
curses__demo_EXTERNAL_OBJECTS =

curses-demo: CMakeFiles/curses-demo.dir/src/main.cpp.o
curses-demo: CMakeFiles/curses-demo.dir/src/game.cpp.o
curses-demo: CMakeFiles/curses-demo.dir/src/tetrimino.cpp.o
curses-demo: CMakeFiles/curses-demo.dir/src/L.cpp.o
curses-demo: CMakeFiles/curses-demo.dir/build.make
curses-demo: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libcurses.tbd
curses-demo: /Library/Developer/CommandLineTools/SDKs/MacOSX12.3.sdk/usr/lib/libform.tbd
curses-demo: CMakeFiles/curses-demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable curses-demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/curses-demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/curses-demo.dir/build: curses-demo
.PHONY : CMakeFiles/curses-demo.dir/build

CMakeFiles/curses-demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/curses-demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/curses-demo.dir/clean

CMakeFiles/curses-demo.dir/depend:
	cd /Users/rileyfischer/Documents/dev/school/TetrisNCurses/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rileyfischer/Documents/dev/school/TetrisNCurses /Users/rileyfischer/Documents/dev/school/TetrisNCurses /Users/rileyfischer/Documents/dev/school/TetrisNCurses/build /Users/rileyfischer/Documents/dev/school/TetrisNCurses/build /Users/rileyfischer/Documents/dev/school/TetrisNCurses/build/CMakeFiles/curses-demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/curses-demo.dir/depend
