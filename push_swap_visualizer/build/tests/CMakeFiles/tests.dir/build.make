# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abdoo/push_swap/push_swap_visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abdoo/push_swap/push_swap_visualizer/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/tests.dir/flags.make

tests/CMakeFiles/tests.dir/test_queues.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/test_queues.cpp.o: /home/abdoo/push_swap/push_swap_visualizer/tests/test_queues.cpp
tests/CMakeFiles/tests.dir/test_queues.cpp.o: tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdoo/push_swap/push_swap_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/tests.dir/test_queues.cpp.o"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/tests.dir/test_queues.cpp.o -MF CMakeFiles/tests.dir/test_queues.cpp.o.d -o CMakeFiles/tests.dir/test_queues.cpp.o -c /home/abdoo/push_swap/push_swap_visualizer/tests/test_queues.cpp

tests/CMakeFiles/tests.dir/test_queues.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/test_queues.cpp.i"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdoo/push_swap/push_swap_visualizer/tests/test_queues.cpp > CMakeFiles/tests.dir/test_queues.cpp.i

tests/CMakeFiles/tests.dir/test_queues.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test_queues.cpp.s"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdoo/push_swap/push_swap_visualizer/tests/test_queues.cpp -o CMakeFiles/tests.dir/test_queues.cpp.s

tests/CMakeFiles/tests.dir/test_pushswap.cpp.o: tests/CMakeFiles/tests.dir/flags.make
tests/CMakeFiles/tests.dir/test_pushswap.cpp.o: /home/abdoo/push_swap/push_swap_visualizer/tests/test_pushswap.cpp
tests/CMakeFiles/tests.dir/test_pushswap.cpp.o: tests/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/abdoo/push_swap/push_swap_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/tests.dir/test_pushswap.cpp.o"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/tests.dir/test_pushswap.cpp.o -MF CMakeFiles/tests.dir/test_pushswap.cpp.o.d -o CMakeFiles/tests.dir/test_pushswap.cpp.o -c /home/abdoo/push_swap/push_swap_visualizer/tests/test_pushswap.cpp

tests/CMakeFiles/tests.dir/test_pushswap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/test_pushswap.cpp.i"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abdoo/push_swap/push_swap_visualizer/tests/test_pushswap.cpp > CMakeFiles/tests.dir/test_pushswap.cpp.i

tests/CMakeFiles/tests.dir/test_pushswap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test_pushswap.cpp.s"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abdoo/push_swap/push_swap_visualizer/tests/test_pushswap.cpp -o CMakeFiles/tests.dir/test_pushswap.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test_queues.cpp.o" \
"CMakeFiles/tests.dir/test_pushswap.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

bin/tests: tests/CMakeFiles/tests.dir/test_queues.cpp.o
bin/tests: tests/CMakeFiles/tests.dir/test_pushswap.cpp.o
bin/tests: tests/CMakeFiles/tests.dir/build.make
bin/tests: src/libVisualizerLib.a
bin/tests: _deps/imgui-sfml-build/libImGui-SFML.so
bin/tests: _deps/sfml-build/lib/libsfml-graphics.so.2.5.1
bin/tests: _deps/sfml-build/lib/libsfml-window.so.2.5.1
bin/tests: _deps/sfml-build/lib/libsfml-system.so.2.5.1
bin/tests: /usr/lib/x86_64-linux-gnu/libGL.so
bin/tests: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/tests: tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/abdoo/push_swap/push_swap_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/tests"
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/tests.dir/build: bin/tests
.PHONY : tests/CMakeFiles/tests.dir/build

tests/CMakeFiles/tests.dir/clean:
	cd /home/abdoo/push_swap/push_swap_visualizer/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/tests.dir/clean

tests/CMakeFiles/tests.dir/depend:
	cd /home/abdoo/push_swap/push_swap_visualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abdoo/push_swap/push_swap_visualizer /home/abdoo/push_swap/push_swap_visualizer/tests /home/abdoo/push_swap/push_swap_visualizer/build /home/abdoo/push_swap/push_swap_visualizer/build/tests /home/abdoo/push_swap/push_swap_visualizer/build/tests/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/tests.dir/depend

