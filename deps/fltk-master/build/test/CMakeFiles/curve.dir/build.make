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
include test/CMakeFiles/curve.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/curve.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/curve.dir/flags.make

test/CMakeFiles/curve.dir/curve.cxx.o: test/CMakeFiles/curve.dir/flags.make
test/CMakeFiles/curve.dir/curve.cxx.o: ../test/curve.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/curve.dir/curve.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/curve.dir/curve.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/curve.cxx

test/CMakeFiles/curve.dir/curve.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/curve.dir/curve.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/curve.cxx > CMakeFiles/curve.dir/curve.cxx.i

test/CMakeFiles/curve.dir/curve.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/curve.dir/curve.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/curve.cxx -o CMakeFiles/curve.dir/curve.cxx.s

# Object files for target curve
curve_OBJECTS = \
"CMakeFiles/curve.dir/curve.cxx.o"

# External object files for target curve
curve_EXTERNAL_OBJECTS =

bin/test/curve: test/CMakeFiles/curve.dir/curve.cxx.o
bin/test/curve: test/CMakeFiles/curve.dir/build.make
bin/test/curve: lib/libfltk.a
bin/test/curve: /usr/lib/x86_64-linux-gnu/libdl.so
bin/test/curve: /usr/lib/x86_64-linux-gnu/libSM.so
bin/test/curve: /usr/lib/x86_64-linux-gnu/libICE.so
bin/test/curve: /usr/lib/x86_64-linux-gnu/libX11.so
bin/test/curve: /usr/lib/x86_64-linux-gnu/libXext.so
bin/test/curve: test/CMakeFiles/curve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test/curve"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/curve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/curve.dir/build: bin/test/curve

.PHONY : test/CMakeFiles/curve.dir/build

test/CMakeFiles/curve.dir/clean:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/curve.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/curve.dir/clean

test/CMakeFiles/curve.dir/depend:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Downloads/fltk-master_oh/fltk-master /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/CMakeFiles/curve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/curve.dir/depend

