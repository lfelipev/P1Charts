# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felipe/P1Charts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felipe/P1Charts/build

# Include any dependencies generated for this target.
include drawing/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include drawing/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include drawing/CMakeFiles/test.dir/flags.make

drawing/CMakeFiles/test.dir/drawing.c.o: drawing/CMakeFiles/test.dir/flags.make
drawing/CMakeFiles/test.dir/drawing.c.o: ../drawing/drawing.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/felipe/P1Charts/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object drawing/CMakeFiles/test.dir/drawing.c.o"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/drawing.c.o   -c /home/felipe/P1Charts/drawing/drawing.c

drawing/CMakeFiles/test.dir/drawing.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/drawing.c.i"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/felipe/P1Charts/drawing/drawing.c > CMakeFiles/test.dir/drawing.c.i

drawing/CMakeFiles/test.dir/drawing.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/drawing.c.s"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/felipe/P1Charts/drawing/drawing.c -o CMakeFiles/test.dir/drawing.c.s

drawing/CMakeFiles/test.dir/drawing.c.o.requires:
.PHONY : drawing/CMakeFiles/test.dir/drawing.c.o.requires

drawing/CMakeFiles/test.dir/drawing.c.o.provides: drawing/CMakeFiles/test.dir/drawing.c.o.requires
	$(MAKE) -f drawing/CMakeFiles/test.dir/build.make drawing/CMakeFiles/test.dir/drawing.c.o.provides.build
.PHONY : drawing/CMakeFiles/test.dir/drawing.c.o.provides

drawing/CMakeFiles/test.dir/drawing.c.o.provides.build: drawing/CMakeFiles/test.dir/drawing.c.o

drawing/CMakeFiles/test.dir/drawingTest.c.o: drawing/CMakeFiles/test.dir/flags.make
drawing/CMakeFiles/test.dir/drawingTest.c.o: ../drawing/drawingTest.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/felipe/P1Charts/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object drawing/CMakeFiles/test.dir/drawingTest.c.o"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/test.dir/drawingTest.c.o   -c /home/felipe/P1Charts/drawing/drawingTest.c

drawing/CMakeFiles/test.dir/drawingTest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/drawingTest.c.i"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/felipe/P1Charts/drawing/drawingTest.c > CMakeFiles/test.dir/drawingTest.c.i

drawing/CMakeFiles/test.dir/drawingTest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/drawingTest.c.s"
	cd /home/felipe/P1Charts/build/drawing && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/felipe/P1Charts/drawing/drawingTest.c -o CMakeFiles/test.dir/drawingTest.c.s

drawing/CMakeFiles/test.dir/drawingTest.c.o.requires:
.PHONY : drawing/CMakeFiles/test.dir/drawingTest.c.o.requires

drawing/CMakeFiles/test.dir/drawingTest.c.o.provides: drawing/CMakeFiles/test.dir/drawingTest.c.o.requires
	$(MAKE) -f drawing/CMakeFiles/test.dir/build.make drawing/CMakeFiles/test.dir/drawingTest.c.o.provides.build
.PHONY : drawing/CMakeFiles/test.dir/drawingTest.c.o.provides

drawing/CMakeFiles/test.dir/drawingTest.c.o.provides.build: drawing/CMakeFiles/test.dir/drawingTest.c.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/drawing.c.o" \
"CMakeFiles/test.dir/drawingTest.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

drawing/test: drawing/CMakeFiles/test.dir/drawing.c.o
drawing/test: drawing/CMakeFiles/test.dir/drawingTest.c.o
drawing/test: drawing/CMakeFiles/test.dir/build.make
drawing/test: drawing/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable test"
	cd /home/felipe/P1Charts/build/drawing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
drawing/CMakeFiles/test.dir/build: drawing/test
.PHONY : drawing/CMakeFiles/test.dir/build

drawing/CMakeFiles/test.dir/requires: drawing/CMakeFiles/test.dir/drawing.c.o.requires
drawing/CMakeFiles/test.dir/requires: drawing/CMakeFiles/test.dir/drawingTest.c.o.requires
.PHONY : drawing/CMakeFiles/test.dir/requires

drawing/CMakeFiles/test.dir/clean:
	cd /home/felipe/P1Charts/build/drawing && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : drawing/CMakeFiles/test.dir/clean

drawing/CMakeFiles/test.dir/depend:
	cd /home/felipe/P1Charts/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felipe/P1Charts /home/felipe/P1Charts/drawing /home/felipe/P1Charts/build /home/felipe/P1Charts/build/drawing /home/felipe/P1Charts/build/drawing/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : drawing/CMakeFiles/test.dir/depend

