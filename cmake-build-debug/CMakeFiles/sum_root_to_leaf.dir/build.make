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
include CMakeFiles/sum_root_to_leaf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sum_root_to_leaf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sum_root_to_leaf.dir/flags.make

CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o: CMakeFiles/sum_root_to_leaf.dir/flags.make
CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o: ../sum_root_to_leaf.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o -c /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/sum_root_to_leaf.cc

CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/sum_root_to_leaf.cc > CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.i

CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/sum_root_to_leaf.cc -o CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.s

# Object files for target sum_root_to_leaf
sum_root_to_leaf_OBJECTS = \
"CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o"

# External object files for target sum_root_to_leaf
sum_root_to_leaf_EXTERNAL_OBJECTS =

sum_root_to_leaf: CMakeFiles/sum_root_to_leaf.dir/sum_root_to_leaf.cc.o
sum_root_to_leaf: CMakeFiles/sum_root_to_leaf.dir/build.make
sum_root_to_leaf: CMakeFiles/sum_root_to_leaf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sum_root_to_leaf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sum_root_to_leaf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sum_root_to_leaf.dir/build: sum_root_to_leaf

.PHONY : CMakeFiles/sum_root_to_leaf.dir/build

CMakeFiles/sum_root_to_leaf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sum_root_to_leaf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sum_root_to_leaf.dir/clean

CMakeFiles/sum_root_to_leaf.dir/depend:
	cd /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles/sum_root_to_leaf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sum_root_to_leaf.dir/depend

