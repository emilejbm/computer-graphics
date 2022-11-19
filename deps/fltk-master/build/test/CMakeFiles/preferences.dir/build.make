# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/emilejbm/Downloads/fltk-master_oh/fltk-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build

# Include any dependencies generated for this target.
include test/CMakeFiles/preferences.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/preferences.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/preferences.dir/flags.make

test/preferences.cxx: ../test/preferences.fl
test/preferences.cxx: ../test/preferences.fl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating preferences.cxx, preferences.h"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && ../bin/fluid -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/preferences.fl

test/preferences.h: test/preferences.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate test/preferences.h

test/CMakeFiles/preferences.dir/preferences.cxx.o: test/CMakeFiles/preferences.dir/flags.make
test/CMakeFiles/preferences.dir/preferences.cxx.o: test/preferences.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/preferences.dir/preferences.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/preferences.dir/preferences.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/preferences.cxx

test/CMakeFiles/preferences.dir/preferences.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/preferences.dir/preferences.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/preferences.cxx > CMakeFiles/preferences.dir/preferences.cxx.i

test/CMakeFiles/preferences.dir/preferences.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/preferences.dir/preferences.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/preferences.cxx -o CMakeFiles/preferences.dir/preferences.cxx.s

# Object files for target preferences
preferences_OBJECTS = \
"CMakeFiles/preferences.dir/preferences.cxx.o"

# External object files for target preferences
preferences_EXTERNAL_OBJECTS =

bin/test/preferences: test/CMakeFiles/preferences.dir/preferences.cxx.o
bin/test/preferences: test/CMakeFiles/preferences.dir/build.make
bin/test/preferences: lib/libfltk.a
bin/test/preferences: /usr/lib/x86_64-linux-gnu/libdl.so
bin/test/preferences: /usr/lib/x86_64-linux-gnu/libSM.so
bin/test/preferences: /usr/lib/x86_64-linux-gnu/libICE.so
bin/test/preferences: /usr/lib/x86_64-linux-gnu/libX11.so
bin/test/preferences: /usr/lib/x86_64-linux-gnu/libXext.so
bin/test/preferences: test/CMakeFiles/preferences.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/test/preferences"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/preferences.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/preferences.dir/build: bin/test/preferences

.PHONY : test/CMakeFiles/preferences.dir/build

test/CMakeFiles/preferences.dir/clean:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/preferences.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/preferences.dir/clean

test/CMakeFiles/preferences.dir/depend: test/preferences.cxx
test/CMakeFiles/preferences.dir/depend: test/preferences.h
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Downloads/fltk-master_oh/fltk-master /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/CMakeFiles/preferences.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/preferences.dir/depend

