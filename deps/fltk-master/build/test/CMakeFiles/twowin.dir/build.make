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
include test/CMakeFiles/twowin.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/twowin.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/twowin.dir/flags.make

test/CMakeFiles/twowin.dir/twowin.cxx.o: test/CMakeFiles/twowin.dir/flags.make
test/CMakeFiles/twowin.dir/twowin.cxx.o: ../test/twowin.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/twowin.dir/twowin.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/twowin.dir/twowin.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/twowin.cxx

test/CMakeFiles/twowin.dir/twowin.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/twowin.dir/twowin.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/twowin.cxx > CMakeFiles/twowin.dir/twowin.cxx.i

test/CMakeFiles/twowin.dir/twowin.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/twowin.dir/twowin.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/twowin.cxx -o CMakeFiles/twowin.dir/twowin.cxx.s

# Object files for target twowin
twowin_OBJECTS = \
"CMakeFiles/twowin.dir/twowin.cxx.o"

# External object files for target twowin
twowin_EXTERNAL_OBJECTS =

bin/test/twowin: test/CMakeFiles/twowin.dir/twowin.cxx.o
bin/test/twowin: test/CMakeFiles/twowin.dir/build.make
bin/test/twowin: lib/libfltk.a
bin/test/twowin: /usr/lib/x86_64-linux-gnu/libdl.so
bin/test/twowin: /usr/lib/x86_64-linux-gnu/libSM.so
bin/test/twowin: /usr/lib/x86_64-linux-gnu/libICE.so
bin/test/twowin: /usr/lib/x86_64-linux-gnu/libX11.so
bin/test/twowin: /usr/lib/x86_64-linux-gnu/libXext.so
bin/test/twowin: test/CMakeFiles/twowin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test/twowin"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/twowin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/twowin.dir/build: bin/test/twowin

.PHONY : test/CMakeFiles/twowin.dir/build

test/CMakeFiles/twowin.dir/clean:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/twowin.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/twowin.dir/clean

test/CMakeFiles/twowin.dir/depend:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Downloads/fltk-master_oh/fltk-master /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/CMakeFiles/twowin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/twowin.dir/depend

