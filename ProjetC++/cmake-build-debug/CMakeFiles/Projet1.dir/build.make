# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/quentingyselinck/CLionProjects/ProjetC++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Projet1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Projet1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Projet1.dir/flags.make

CMakeFiles/Projet1.dir/Test1.cpp.o: CMakeFiles/Projet1.dir/flags.make
CMakeFiles/Projet1.dir/Test1.cpp.o: ../Test1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Projet1.dir/Test1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Projet1.dir/Test1.cpp.o -c /Users/quentingyselinck/CLionProjects/ProjetC++/Test1.cpp

CMakeFiles/Projet1.dir/Test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Projet1.dir/Test1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/quentingyselinck/CLionProjects/ProjetC++/Test1.cpp > CMakeFiles/Projet1.dir/Test1.cpp.i

CMakeFiles/Projet1.dir/Test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Projet1.dir/Test1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/quentingyselinck/CLionProjects/ProjetC++/Test1.cpp -o CMakeFiles/Projet1.dir/Test1.cpp.s

# Object files for target Projet1
Projet1_OBJECTS = \
"CMakeFiles/Projet1.dir/Test1.cpp.o"

# External object files for target Projet1
Projet1_EXTERNAL_OBJECTS =

Projet1: CMakeFiles/Projet1.dir/Test1.cpp.o
Projet1: CMakeFiles/Projet1.dir/build.make
Projet1: CMakeFiles/Projet1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Projet1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Projet1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Projet1.dir/build: Projet1

.PHONY : CMakeFiles/Projet1.dir/build

CMakeFiles/Projet1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Projet1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Projet1.dir/clean

CMakeFiles/Projet1.dir/depend:
	cd /Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/quentingyselinck/CLionProjects/ProjetC++ /Users/quentingyselinck/CLionProjects/ProjetC++ /Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug /Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug /Users/quentingyselinck/CLionProjects/ProjetC++/cmake-build-debug/CMakeFiles/Projet1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Projet1.dir/depend

