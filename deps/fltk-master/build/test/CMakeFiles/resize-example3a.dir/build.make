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
include test/CMakeFiles/resize-example3a.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/resize-example3a.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/resize-example3a.dir/flags.make

test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o: test/CMakeFiles/resize-example3a.dir/flags.make
test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o: ../test/resize-example3a.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-example3a.cxx

test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/resize-example3a.dir/resize-example3a.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-example3a.cxx > CMakeFiles/resize-example3a.dir/resize-example3a.cxx.i

test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/resize-example3a.dir/resize-example3a.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-example3a.cxx -o CMakeFiles/resize-example3a.dir/resize-example3a.cxx.s

test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o: test/CMakeFiles/resize-example3a.dir/flags.make
test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o: ../test/resize-arrows.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-arrows.cxx

test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/resize-example3a.dir/resize-arrows.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-arrows.cxx > CMakeFiles/resize-example3a.dir/resize-arrows.cxx.i

test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/resize-example3a.dir/resize-arrows.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/resize-arrows.cxx -o CMakeFiles/resize-example3a.dir/resize-arrows.cxx.s

# Object files for target resize-example3a
resize__example3a_OBJECTS = \
"CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o" \
"CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o"

# External object files for target resize-example3a
resize__example3a_EXTERNAL_OBJECTS =

bin/test/resize-example3a: test/CMakeFiles/resize-example3a.dir/resize-example3a.cxx.o
bin/test/resize-example3a: test/CMakeFiles/resize-example3a.dir/resize-arrows.cxx.o
bin/test/resize-example3a: test/CMakeFiles/resize-example3a.dir/build.make
bin/test/resize-example3a: lib/libfltk.a
bin/test/resize-example3a: /usr/lib/x86_64-linux-gnu/libdl.so
bin/test/resize-example3a: /usr/lib/x86_64-linux-gnu/libSM.so
bin/test/resize-example3a: /usr/lib/x86_64-linux-gnu/libICE.so
bin/test/resize-example3a: /usr/lib/x86_64-linux-gnu/libX11.so
bin/test/resize-example3a: /usr/lib/x86_64-linux-gnu/libXext.so
bin/test/resize-example3a: test/CMakeFiles/resize-example3a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/test/resize-example3a"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/resize-example3a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/resize-example3a.dir/build: bin/test/resize-example3a

.PHONY : test/CMakeFiles/resize-example3a.dir/build

test/CMakeFiles/resize-example3a.dir/clean:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/resize-example3a.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/resize-example3a.dir/clean

test/CMakeFiles/resize-example3a.dir/depend:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Downloads/fltk-master_oh/fltk-master /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/CMakeFiles/resize-example3a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/resize-example3a.dir/depend

