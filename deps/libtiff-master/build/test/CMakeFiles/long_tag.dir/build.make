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
include test/CMakeFiles/long_tag.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/long_tag.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/long_tag.dir/flags.make

test/CMakeFiles/long_tag.dir/long_tag.c.o: test/CMakeFiles/long_tag.dir/flags.make
test/CMakeFiles/long_tag.dir/long_tag.c.o: ../test/long_tag.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/long_tag.dir/long_tag.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/long_tag.dir/long_tag.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/long_tag.c

test/CMakeFiles/long_tag.dir/long_tag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/long_tag.dir/long_tag.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/long_tag.c > CMakeFiles/long_tag.dir/long_tag.c.i

test/CMakeFiles/long_tag.dir/long_tag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/long_tag.dir/long_tag.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/long_tag.c -o CMakeFiles/long_tag.dir/long_tag.c.s

test/CMakeFiles/long_tag.dir/check_tag.c.o: test/CMakeFiles/long_tag.dir/flags.make
test/CMakeFiles/long_tag.dir/check_tag.c.o: ../test/check_tag.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/CMakeFiles/long_tag.dir/check_tag.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/long_tag.dir/check_tag.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/check_tag.c

test/CMakeFiles/long_tag.dir/check_tag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/long_tag.dir/check_tag.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/check_tag.c > CMakeFiles/long_tag.dir/check_tag.c.i

test/CMakeFiles/long_tag.dir/check_tag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/long_tag.dir/check_tag.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test/check_tag.c -o CMakeFiles/long_tag.dir/check_tag.c.s

# Object files for target long_tag
long_tag_OBJECTS = \
"CMakeFiles/long_tag.dir/long_tag.c.o" \
"CMakeFiles/long_tag.dir/check_tag.c.o"

# External object files for target long_tag
long_tag_EXTERNAL_OBJECTS =

test/long_tag: test/CMakeFiles/long_tag.dir/long_tag.c.o
test/long_tag: test/CMakeFiles/long_tag.dir/check_tag.c.o
test/long_tag: test/CMakeFiles/long_tag.dir/build.make
test/long_tag: libtiff/libtiff.so.5.3.0
test/long_tag: port/libport.a
test/long_tag: /usr/lib/x86_64-linux-gnu/libm.so
test/long_tag: /usr/lib/x86_64-linux-gnu/libz.so
test/long_tag: /usr/lib/x86_64-linux-gnu/libjpeg.so
test/long_tag: /usr/lib/x86_64-linux-gnu/libjbig.so
test/long_tag: /usr/lib/x86_64-linux-gnu/liblzma.so
test/long_tag: test/CMakeFiles/long_tag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable long_tag"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/long_tag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/long_tag.dir/build: test/long_tag

.PHONY : test/CMakeFiles/long_tag.dir/build

test/CMakeFiles/long_tag.dir/clean:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test && $(CMAKE_COMMAND) -P CMakeFiles/long_tag.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/long_tag.dir/clean

test/CMakeFiles/long_tag.dir/depend:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/test/CMakeFiles/long_tag.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/long_tag.dir/depend

