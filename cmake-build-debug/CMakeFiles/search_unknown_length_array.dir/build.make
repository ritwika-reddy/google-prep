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
include CMakeFiles/search_unknown_length_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/search_unknown_length_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/search_unknown_length_array.dir/flags.make

CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o: CMakeFiles/search_unknown_length_array.dir/flags.make
CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o: ../search_unknown_length_array.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o -c /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/search_unknown_length_array.cc

CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/search_unknown_length_array.cc > CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.i

CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/search_unknown_length_array.cc -o CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.s

# Object files for target search_unknown_length_array
search_unknown_length_array_OBJECTS = \
"CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o"

# External object files for target search_unknown_length_array
search_unknown_length_array_EXTERNAL_OBJECTS =

search_unknown_length_array: CMakeFiles/search_unknown_length_array.dir/search_unknown_length_array.cc.o
search_unknown_length_array: CMakeFiles/search_unknown_length_array.dir/build.make
search_unknown_length_array: CMakeFiles/search_unknown_length_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable search_unknown_length_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/search_unknown_length_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/search_unknown_length_array.dir/build: search_unknown_length_array

.PHONY : CMakeFiles/search_unknown_length_array.dir/build

CMakeFiles/search_unknown_length_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/search_unknown_length_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/search_unknown_length_array.dir/clean

CMakeFiles/search_unknown_length_array.dir/depend:
	cd /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles/search_unknown_length_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/search_unknown_length_array.dir/depend

