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
include test/CMakeFiles/gl_overlay.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/gl_overlay.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/gl_overlay.dir/flags.make

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o: test/CMakeFiles/gl_overlay.dir/flags.make
test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o: ../test/gl_overlay.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o -c /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/gl_overlay.cxx

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gl_overlay.dir/gl_overlay.cxx.i"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/gl_overlay.cxx > CMakeFiles/gl_overlay.dir/gl_overlay.cxx.i

test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gl_overlay.dir/gl_overlay.cxx.s"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test/gl_overlay.cxx -o CMakeFiles/gl_overlay.dir/gl_overlay.cxx.s

# Object files for target gl_overlay
gl_overlay_OBJECTS = \
"CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o"

# External object files for target gl_overlay
gl_overlay_EXTERNAL_OBJECTS =

bin/test/gl_overlay: test/CMakeFiles/gl_overlay.dir/gl_overlay.cxx.o
bin/test/gl_overlay: test/CMakeFiles/gl_overlay.dir/build.make
bin/test/gl_overlay: lib/libfltk_gl.a
bin/test/gl_overlay: lib/libfltk.a
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libGL.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libdl.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libSM.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libICE.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libX11.so
bin/test/gl_overlay: /usr/lib/x86_64-linux-gnu/libXext.so
bin/test/gl_overlay: test/CMakeFiles/gl_overlay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test/gl_overlay"
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gl_overlay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/gl_overlay.dir/build: bin/test/gl_overlay

.PHONY : test/CMakeFiles/gl_overlay.dir/build

test/CMakeFiles/gl_overlay.dir/clean:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/gl_overlay.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/gl_overlay.dir/clean

test/CMakeFiles/gl_overlay.dir/depend:
	cd /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Downloads/fltk-master_oh/fltk-master /home/emilejbm/Downloads/fltk-master_oh/fltk-master/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test /home/emilejbm/Downloads/fltk-master_oh/fltk-master/build/test/CMakeFiles/gl_overlay.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/gl_overlay.dir/depend

