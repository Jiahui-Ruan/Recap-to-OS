# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Ryan_Garfield/Documents/OS/PThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PThread.dir/flags.make

CMakeFiles/PThread.dir/main.c.o: CMakeFiles/PThread.dir/flags.make
CMakeFiles/PThread.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PThread.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PThread.dir/main.c.o   -c /Users/Ryan_Garfield/Documents/OS/PThread/main.c

CMakeFiles/PThread.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PThread.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Ryan_Garfield/Documents/OS/PThread/main.c > CMakeFiles/PThread.dir/main.c.i

CMakeFiles/PThread.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PThread.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Ryan_Garfield/Documents/OS/PThread/main.c -o CMakeFiles/PThread.dir/main.c.s

CMakeFiles/PThread.dir/main.c.o.requires:

.PHONY : CMakeFiles/PThread.dir/main.c.o.requires

CMakeFiles/PThread.dir/main.c.o.provides: CMakeFiles/PThread.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/PThread.dir/build.make CMakeFiles/PThread.dir/main.c.o.provides.build
.PHONY : CMakeFiles/PThread.dir/main.c.o.provides

CMakeFiles/PThread.dir/main.c.o.provides.build: CMakeFiles/PThread.dir/main.c.o


# Object files for target PThread
PThread_OBJECTS = \
"CMakeFiles/PThread.dir/main.c.o"

# External object files for target PThread
PThread_EXTERNAL_OBJECTS =

PThread: CMakeFiles/PThread.dir/main.c.o
PThread: CMakeFiles/PThread.dir/build.make
PThread: CMakeFiles/PThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PThread.dir/build: PThread

.PHONY : CMakeFiles/PThread.dir/build

CMakeFiles/PThread.dir/requires: CMakeFiles/PThread.dir/main.c.o.requires

.PHONY : CMakeFiles/PThread.dir/requires

CMakeFiles/PThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PThread.dir/clean

CMakeFiles/PThread.dir/depend:
	cd /Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Ryan_Garfield/Documents/OS/PThread /Users/Ryan_Garfield/Documents/OS/PThread /Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug /Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug /Users/Ryan_Garfield/Documents/OS/PThread/cmake-build-debug/CMakeFiles/PThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PThread.dir/depend

