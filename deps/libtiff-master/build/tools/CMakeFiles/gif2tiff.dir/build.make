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
CMAKE_SOURCE_DIR = /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build

# Include any dependencies generated for this target.
include tools/CMakeFiles/gif2tiff.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/gif2tiff.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/gif2tiff.dir/flags.make

tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.o: tools/CMakeFiles/gif2tiff.dir/flags.make
tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.o: ../tools/gif2tiff.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gif2tiff.dir/gif2tiff.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/tools/gif2tiff.c

tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gif2tiff.dir/gif2tiff.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/tools/gif2tiff.c > CMakeFiles/gif2tiff.dir/gif2tiff.c.i

tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gif2tiff.dir/gif2tiff.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/tools/gif2tiff.c -o CMakeFiles/gif2tiff.dir/gif2tiff.c.s

# Object files for target gif2tiff
gif2tiff_OBJECTS = \
"CMakeFiles/gif2tiff.dir/gif2tiff.c.o"

# External object files for target gif2tiff
gif2tiff_EXTERNAL_OBJECTS =

tools/gif2tiff: tools/CMakeFiles/gif2tiff.dir/gif2tiff.c.o
tools/gif2tiff: tools/CMakeFiles/gif2tiff.dir/build.make
tools/gif2tiff: libtiff/libtiff.so.5.3.0
tools/gif2tiff: port/libport.a
tools/gif2tiff: /usr/lib/x86_64-linux-gnu/libm.so
tools/gif2tiff: /usr/lib/x86_64-linux-gnu/libz.so
tools/gif2tiff: /usr/lib/x86_64-linux-gnu/libjpeg.so
tools/gif2tiff: /usr/lib/x86_64-linux-gnu/libjbig.so
tools/gif2tiff: /usr/lib/x86_64-linux-gnu/liblzma.so
tools/gif2tiff: tools/CMakeFiles/gif2tiff.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable gif2tiff"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gif2tiff.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/gif2tiff.dir/build: tools/gif2tiff

.PHONY : tools/CMakeFiles/gif2tiff.dir/build

tools/CMakeFiles/gif2tiff.dir/clean:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools && $(CMAKE_COMMAND) -P CMakeFiles/gif2tiff.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/gif2tiff.dir/clean

tools/CMakeFiles/gif2tiff.dir/depend:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/tools /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/tools/CMakeFiles/gif2tiff.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/gif2tiff.dir/depend

