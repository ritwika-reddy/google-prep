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
include CMakeFiles/defective_jugs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/defective_jugs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/defective_jugs.dir/flags.make

CMakeFiles/defective_jugs.dir/defective_jugs.cc.o: CMakeFiles/defective_jugs.dir/flags.make
CMakeFiles/defective_jugs.dir/defective_jugs.cc.o: ../defective_jugs.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/defective_jugs.dir/defective_jugs.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/defective_jugs.dir/defective_jugs.cc.o -c /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/defective_jugs.cc

CMakeFiles/defective_jugs.dir/defective_jugs.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/defective_jugs.dir/defective_jugs.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/defective_jugs.cc > CMakeFiles/defective_jugs.dir/defective_jugs.cc.i

CMakeFiles/defective_jugs.dir/defective_jugs.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/defective_jugs.dir/defective_jugs.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/defective_jugs.cc -o CMakeFiles/defective_jugs.dir/defective_jugs.cc.s

# Object files for target defective_jugs
defective_jugs_OBJECTS = \
"CMakeFiles/defective_jugs.dir/defective_jugs.cc.o"

# External object files for target defective_jugs
defective_jugs_EXTERNAL_OBJECTS =

defective_jugs: CMakeFiles/defective_jugs.dir/defective_jugs.cc.o
defective_jugs: CMakeFiles/defective_jugs.dir/build.make
defective_jugs: CMakeFiles/defective_jugs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable defective_jugs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/defective_jugs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/defective_jugs.dir/build: defective_jugs

.PHONY : CMakeFiles/defective_jugs.dir/build

CMakeFiles/defective_jugs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/defective_jugs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/defective_jugs.dir/clean

CMakeFiles/defective_jugs.dir/depend:
	cd /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug /home/ritwika/Documents/third-sem/google-prep/EPIJudge/epi_judge_cpp/cmake-build-debug/CMakeFiles/defective_jugs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/defective_jugs.dir/depend
