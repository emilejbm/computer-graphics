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
include contrib/dbs/CMakeFiles/tiff-grayscale.dir/depend.make

# Include the progress variables for this target.
include contrib/dbs/CMakeFiles/tiff-grayscale.dir/progress.make

# Include the compile flags for this target's objects.
include contrib/dbs/CMakeFiles/tiff-grayscale.dir/flags.make

contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o: contrib/dbs/CMakeFiles/tiff-grayscale.dir/flags.make
contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o: ../contrib/dbs/tiff-grayscale.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o   -c /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/contrib/dbs/tiff-grayscale.c

contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.i"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/contrib/dbs/tiff-grayscale.c > CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.i

contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.s"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/contrib/dbs/tiff-grayscale.c -o CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.s

# Object files for target tiff-grayscale
tiff__grayscale_OBJECTS = \
"CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o"

# External object files for target tiff-grayscale
tiff__grayscale_EXTERNAL_OBJECTS =

contrib/dbs/tiff-grayscale: contrib/dbs/CMakeFiles/tiff-grayscale.dir/tiff-grayscale.c.o
contrib/dbs/tiff-grayscale: contrib/dbs/CMakeFiles/tiff-grayscale.dir/build.make
contrib/dbs/tiff-grayscale: libtiff/libtiff.so.5.3.0
contrib/dbs/tiff-grayscale: port/libport.a
contrib/dbs/tiff-grayscale: /usr/lib/x86_64-linux-gnu/libm.so
contrib/dbs/tiff-grayscale: /usr/lib/x86_64-linux-gnu/libz.so
contrib/dbs/tiff-grayscale: /usr/lib/x86_64-linux-gnu/libjpeg.so
contrib/dbs/tiff-grayscale: /usr/lib/x86_64-linux-gnu/libjbig.so
contrib/dbs/tiff-grayscale: /usr/lib/x86_64-linux-gnu/liblzma.so
contrib/dbs/tiff-grayscale: contrib/dbs/CMakeFiles/tiff-grayscale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable tiff-grayscale"
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tiff-grayscale.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
contrib/dbs/CMakeFiles/tiff-grayscale.dir/build: contrib/dbs/tiff-grayscale

.PHONY : contrib/dbs/CMakeFiles/tiff-grayscale.dir/build

contrib/dbs/CMakeFiles/tiff-grayscale.dir/clean:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs && $(CMAKE_COMMAND) -P CMakeFiles/tiff-grayscale.dir/cmake_clean.cmake
.PHONY : contrib/dbs/CMakeFiles/tiff-grayscale.dir/clean

contrib/dbs/CMakeFiles/tiff-grayscale.dir/depend:
	cd /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/contrib/dbs /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs /home/emilejbm/Desktop/github/CS334-2022Fall/CS334/hw1_v2/deps/libtiff-master/build/contrib/dbs/CMakeFiles/tiff-grayscale.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : contrib/dbs/CMakeFiles/tiff-grayscale.dir/depend

