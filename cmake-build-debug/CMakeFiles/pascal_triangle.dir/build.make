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
include CMakeFiles/pascal_triangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pascal_triangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pascal_triangle.dir/flags.make

CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o: CMakeFiles/pascal_triangle.dir/flags.make
CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o: ../pascal_triangle.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o -c /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/pascal_triangle.cc

CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/pascal_triangle.cc > CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.i

CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/pascal_triangle.cc -o CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.s

# Object files for target pascal_triangle
pascal_triangle_OBJECTS = \
"CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o"

# External object files for target pascal_triangle
pascal_triangle_EXTERNAL_OBJECTS =

pascal_triangle: CMakeFiles/pascal_triangle.dir/pascal_triangle.cc.o
pascal_triangle: CMakeFiles/pascal_triangle.dir/build.make
pascal_triangle: CMakeFiles/pascal_triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pascal_triangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pascal_triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pascal_triangle.dir/build: pascal_triangle

.PHONY : CMakeFiles/pascal_triangle.dir/build

CMakeFiles/pascal_triangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pascal_triangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pascal_triangle.dir/clean

CMakeFiles/pascal_triangle.dir/depend:
	cd /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles/pascal_triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pascal_triangle.dir/depend

