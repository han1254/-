# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/han1254/Downloads/clion-2020.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/han1254/Downloads/clion-2020.2.5/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/han1254/Documents/PGEE/clion_datastructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mGraphMain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mGraphMain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mGraphMain.dir/flags.make

CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o: CMakeFiles/mGraphMain.dir/flags.make
CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o: ../_6_graph/_1_adjacency_matrix/MGraphMain.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o   -c /home/han1254/Documents/PGEE/clion_datastructure/_6_graph/_1_adjacency_matrix/MGraphMain.c

CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/han1254/Documents/PGEE/clion_datastructure/_6_graph/_1_adjacency_matrix/MGraphMain.c > CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.i

CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/han1254/Documents/PGEE/clion_datastructure/_6_graph/_1_adjacency_matrix/MGraphMain.c -o CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.s

# Object files for target mGraphMain
mGraphMain_OBJECTS = \
"CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o"

# External object files for target mGraphMain
mGraphMain_EXTERNAL_OBJECTS =

mGraphMain: CMakeFiles/mGraphMain.dir/_6_graph/_1_adjacency_matrix/MGraphMain.c.o
mGraphMain: CMakeFiles/mGraphMain.dir/build.make
mGraphMain: CMakeFiles/mGraphMain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mGraphMain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mGraphMain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mGraphMain.dir/build: mGraphMain

.PHONY : CMakeFiles/mGraphMain.dir/build

CMakeFiles/mGraphMain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mGraphMain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mGraphMain.dir/clean

CMakeFiles/mGraphMain.dir/depend:
	cd /home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/han1254/Documents/PGEE/clion_datastructure /home/han1254/Documents/PGEE/clion_datastructure /home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug /home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug /home/han1254/Documents/PGEE/clion_datastructure/cmake-build-debug/CMakeFiles/mGraphMain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mGraphMain.dir/depend

