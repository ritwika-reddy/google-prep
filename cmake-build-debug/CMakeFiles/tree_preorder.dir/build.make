# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tree_preorder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree_preorder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree_preorder.dir/flags.make

CMakeFiles/tree_preorder.dir/tree_preorder.cc.o: CMakeFiles/tree_preorder.dir/flags.make
CMakeFiles/tree_preorder.dir/tree_preorder.cc.o: ../tree_preorder.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree_preorder.dir/tree_preorder.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tree_preorder.dir/tree_preorder.cc.o -c /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/tree_preorder.cc

CMakeFiles/tree_preorder.dir/tree_preorder.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree_preorder.dir/tree_preorder.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/tree_preorder.cc > CMakeFiles/tree_preorder.dir/tree_preorder.cc.i

CMakeFiles/tree_preorder.dir/tree_preorder.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree_preorder.dir/tree_preorder.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/tree_preorder.cc -o CMakeFiles/tree_preorder.dir/tree_preorder.cc.s

# Object files for target tree_preorder
tree_preorder_OBJECTS = \
"CMakeFiles/tree_preorder.dir/tree_preorder.cc.o"

# External object files for target tree_preorder
tree_preorder_EXTERNAL_OBJECTS =

tree_preorder: CMakeFiles/tree_preorder.dir/tree_preorder.cc.o
tree_preorder: CMakeFiles/tree_preorder.dir/build.make
tree_preorder: CMakeFiles/tree_preorder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tree_preorder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree_preorder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree_preorder.dir/build: tree_preorder

.PHONY : CMakeFiles/tree_preorder.dir/build

CMakeFiles/tree_preorder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree_preorder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree_preorder.dir/clean

CMakeFiles/tree_preorder.dir/depend:
	cd /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles/tree_preorder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree_preorder.dir/depend

