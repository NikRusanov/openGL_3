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
CMAKE_COMMAND = /home/nik/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nik/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/opengl/opengl_lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/opengl/opengl_lab3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opengl_lab3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opengl_lab3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_lab3.dir/flags.make

CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o: CMakeFiles/opengl_lab3.dir/flags.make
CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o: ../src/icosahedron.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o -c /tmp/opengl/opengl_lab3/src/icosahedron.cpp

CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/opengl/opengl_lab3/src/icosahedron.cpp > CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.i

CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/opengl/opengl_lab3/src/icosahedron.cpp -o CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.s

CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o: CMakeFiles/opengl_lab3.dir/flags.make
CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o: ../src/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o -c /tmp/opengl/opengl_lab3/src/Utils.cpp

CMakeFiles/opengl_lab3.dir/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_lab3.dir/src/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/opengl/opengl_lab3/src/Utils.cpp > CMakeFiles/opengl_lab3.dir/src/Utils.cpp.i

CMakeFiles/opengl_lab3.dir/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_lab3.dir/src/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/opengl/opengl_lab3/src/Utils.cpp -o CMakeFiles/opengl_lab3.dir/src/Utils.cpp.s

CMakeFiles/opengl_lab3.dir/main.cpp.o: CMakeFiles/opengl_lab3.dir/flags.make
CMakeFiles/opengl_lab3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/opengl_lab3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_lab3.dir/main.cpp.o -c /tmp/opengl/opengl_lab3/main.cpp

CMakeFiles/opengl_lab3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_lab3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/opengl/opengl_lab3/main.cpp > CMakeFiles/opengl_lab3.dir/main.cpp.i

CMakeFiles/opengl_lab3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_lab3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/opengl/opengl_lab3/main.cpp -o CMakeFiles/opengl_lab3.dir/main.cpp.s

CMakeFiles/opengl_lab3.dir/src/main2.cpp.o: CMakeFiles/opengl_lab3.dir/flags.make
CMakeFiles/opengl_lab3.dir/src/main2.cpp.o: ../src/main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/opengl_lab3.dir/src/main2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_lab3.dir/src/main2.cpp.o -c /tmp/opengl/opengl_lab3/src/main2.cpp

CMakeFiles/opengl_lab3.dir/src/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_lab3.dir/src/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/opengl/opengl_lab3/src/main2.cpp > CMakeFiles/opengl_lab3.dir/src/main2.cpp.i

CMakeFiles/opengl_lab3.dir/src/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_lab3.dir/src/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/opengl/opengl_lab3/src/main2.cpp -o CMakeFiles/opengl_lab3.dir/src/main2.cpp.s

# Object files for target opengl_lab3
opengl_lab3_OBJECTS = \
"CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o" \
"CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o" \
"CMakeFiles/opengl_lab3.dir/main.cpp.o" \
"CMakeFiles/opengl_lab3.dir/src/main2.cpp.o"

# External object files for target opengl_lab3
opengl_lab3_EXTERNAL_OBJECTS =

opengl_lab3: CMakeFiles/opengl_lab3.dir/src/icosahedron.cpp.o
opengl_lab3: CMakeFiles/opengl_lab3.dir/src/Utils.cpp.o
opengl_lab3: CMakeFiles/opengl_lab3.dir/main.cpp.o
opengl_lab3: CMakeFiles/opengl_lab3.dir/src/main2.cpp.o
opengl_lab3: CMakeFiles/opengl_lab3.dir/build.make
opengl_lab3: CMakeFiles/opengl_lab3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable opengl_lab3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_lab3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_lab3.dir/build: opengl_lab3

.PHONY : CMakeFiles/opengl_lab3.dir/build

CMakeFiles/opengl_lab3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_lab3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_lab3.dir/clean

CMakeFiles/opengl_lab3.dir/depend:
	cd /tmp/opengl/opengl_lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/opengl/opengl_lab3 /tmp/opengl/opengl_lab3 /tmp/opengl/opengl_lab3/cmake-build-debug /tmp/opengl/opengl_lab3/cmake-build-debug /tmp/opengl/opengl_lab3/cmake-build-debug/CMakeFiles/opengl_lab3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_lab3.dir/depend
