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
include test/CMakeFiles/custom_dir.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/custom_dir.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/custom_dir.dir/flags.make

test/CMakeFiles/custom_dir.dir/custom_dir.c.o: test/CMakeFiles/custom_dir.dir/flags.make
test/CMakeFiles/custom_dir.dir/custom_dir.c.o: ../test/custom_dir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/custom_dir.dir/custom_dir.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom_dir.dir/custom_dir.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/custom_dir.c

test/CMakeFiles/custom_dir.dir/custom_dir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom_dir.dir/custom_dir.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/custom_dir.c > CMakeFiles/custom_dir.dir/custom_dir.c.i

test/CMakeFiles/custom_dir.dir/custom_dir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom_dir.dir/custom_dir.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/custom_dir.c -o CMakeFiles/custom_dir.dir/custom_dir.c.s

# Object files for target custom_dir
custom_dir_OBJECTS = \
"CMakeFiles/custom_dir.dir/custom_dir.c.o"

# External object files for target custom_dir
custom_dir_EXTERNAL_OBJECTS =

test/custom_dir: test/CMakeFiles/custom_dir.dir/custom_dir.c.o
test/custom_dir: test/CMakeFiles/custom_dir.dir/build.make
test/custom_dir: libtiff/libtiff.so.5.3.0
test/custom_dir: port/libport.a
test/custom_dir: /usr/lib/x86_64-linux-gnu/libm.so
test/custom_dir: /usr/lib/x86_64-linux-gnu/libz.so
test/custom_dir: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/custom_dir: /usr/lib/x86_64-linux-gnu/libjbig.so
test/custom_dir: /usr/lib/x86_64-linux-gnu/liblzma.so
test/custom_dir: test/CMakeFiles/custom_dir.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable custom_dir"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/custom_dir.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/custom_dir.dir/build: test/custom_dir

.PHONY : test/CMakeFiles/custom_dir.dir/build

test/CMakeFiles/custom_dir.dir/clean:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/custom_dir.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/custom_dir.dir/clean

test/CMakeFiles/custom_dir.dir/depend:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test/CMakeFiles/custom_dir.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/custom_dir.dir/depend

