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
include test/CMakeFiles/raw_decode.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/raw_decode.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/raw_decode.dir/flags.make

test/CMakeFiles/raw_decode.dir/raw_decode.c.o: test/CMakeFiles/raw_decode.dir/flags.make
test/CMakeFiles/raw_decode.dir/raw_decode.c.o: ../test/raw_decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/raw_decode.dir/raw_decode.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/raw_decode.dir/raw_decode.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/raw_decode.c

test/CMakeFiles/raw_decode.dir/raw_decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/raw_decode.dir/raw_decode.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/raw_decode.c > CMakeFiles/raw_decode.dir/raw_decode.c.i

test/CMakeFiles/raw_decode.dir/raw_decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/raw_decode.dir/raw_decode.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/raw_decode.c -o CMakeFiles/raw_decode.dir/raw_decode.c.s

# Object files for target raw_decode
raw_decode_OBJECTS = \
"CMakeFiles/raw_decode.dir/raw_decode.c.o"

# External object files for target raw_decode
raw_decode_EXTERNAL_OBJECTS =

test/raw_decode: test/CMakeFiles/raw_decode.dir/raw_decode.c.o
test/raw_decode: test/CMakeFiles/raw_decode.dir/build.make
test/raw_decode: libtiff/libtiff.so.5.3.0
test/raw_decode: port/libport.a
test/raw_decode: /usr/lib/x86_64-linux-gnu/libm.so
test/raw_decode: /usr/lib/x86_64-linux-gnu/libz.so
test/raw_decode: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/raw_decode: /usr/lib/x86_64-linux-gnu/libjbig.so
test/raw_decode: /usr/lib/x86_64-linux-gnu/liblzma.so
test/raw_decode: test/CMakeFiles/raw_decode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable raw_decode"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raw_decode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/raw_decode.dir/build: test/raw_decode

.PHONY : test/CMakeFiles/raw_decode.dir/build

test/CMakeFiles/raw_decode.dir/clean:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/raw_decode.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/raw_decode.dir/clean

test/CMakeFiles/raw_decode.dir/depend:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test/CMakeFiles/raw_decode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/raw_decode.dir/depend

