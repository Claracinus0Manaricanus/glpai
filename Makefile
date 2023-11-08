# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/cm/codes/c++/glpai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cm/codes/c++/glpai

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cm/codes/c++/glpai/CMakeFiles /home/cm/codes/c++/glpai//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/cm/codes/c++/glpai/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named pai

# Build rule for target.
pai: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 pai
.PHONY : pai

# fast build rule for target.
pai/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/build
.PHONY : pai/fast

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/main.cpp.s
.PHONY : main.cpp.s

tools/B0.o: tools/B0.cpp.o
.PHONY : tools/B0.o

# target to build an object file
tools/B0.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B0.cpp.o
.PHONY : tools/B0.cpp.o

tools/B0.i: tools/B0.cpp.i
.PHONY : tools/B0.i

# target to preprocess a source file
tools/B0.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B0.cpp.i
.PHONY : tools/B0.cpp.i

tools/B0.s: tools/B0.cpp.s
.PHONY : tools/B0.s

# target to generate assembly for a file
tools/B0.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B0.cpp.s
.PHONY : tools/B0.cpp.s

tools/B1.o: tools/B1.cpp.o
.PHONY : tools/B1.o

# target to build an object file
tools/B1.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B1.cpp.o
.PHONY : tools/B1.cpp.o

tools/B1.i: tools/B1.cpp.i
.PHONY : tools/B1.i

# target to preprocess a source file
tools/B1.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B1.cpp.i
.PHONY : tools/B1.cpp.i

tools/B1.s: tools/B1.cpp.s
.PHONY : tools/B1.s

# target to generate assembly for a file
tools/B1.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B1.cpp.s
.PHONY : tools/B1.cpp.s

tools/B2.o: tools/B2.cpp.o
.PHONY : tools/B2.o

# target to build an object file
tools/B2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B2.cpp.o
.PHONY : tools/B2.cpp.o

tools/B2.i: tools/B2.cpp.i
.PHONY : tools/B2.i

# target to preprocess a source file
tools/B2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B2.cpp.i
.PHONY : tools/B2.cpp.i

tools/B2.s: tools/B2.cpp.s
.PHONY : tools/B2.s

# target to generate assembly for a file
tools/B2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/B2.cpp.s
.PHONY : tools/B2.cpp.s

tools/R0.o: tools/R0.cpp.o
.PHONY : tools/R0.o

# target to build an object file
tools/R0.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/R0.cpp.o
.PHONY : tools/R0.cpp.o

tools/R0.i: tools/R0.cpp.i
.PHONY : tools/R0.i

# target to preprocess a source file
tools/R0.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/R0.cpp.i
.PHONY : tools/R0.cpp.i

tools/R0.s: tools/R0.cpp.s
.PHONY : tools/R0.s

# target to generate assembly for a file
tools/R0.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/R0.cpp.s
.PHONY : tools/R0.cpp.s

tools/T0.o: tools/T0.cpp.o
.PHONY : tools/T0.o

# target to build an object file
tools/T0.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/T0.cpp.o
.PHONY : tools/T0.cpp.o

tools/T0.i: tools/T0.cpp.i
.PHONY : tools/T0.i

# target to preprocess a source file
tools/T0.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/T0.cpp.i
.PHONY : tools/T0.cpp.i

tools/T0.s: tools/T0.cpp.s
.PHONY : tools/T0.s

# target to generate assembly for a file
tools/T0.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/T0.cpp.s
.PHONY : tools/T0.cpp.s

tools/U0.o: tools/U0.cpp.o
.PHONY : tools/U0.o

# target to build an object file
tools/U0.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/U0.cpp.o
.PHONY : tools/U0.cpp.o

tools/U0.i: tools/U0.cpp.i
.PHONY : tools/U0.i

# target to preprocess a source file
tools/U0.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/U0.cpp.i
.PHONY : tools/U0.cpp.i

tools/U0.s: tools/U0.cpp.s
.PHONY : tools/U0.s

# target to generate assembly for a file
tools/U0.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/U0.cpp.s
.PHONY : tools/U0.cpp.s

tools/cmMath/matrix4.o: tools/cmMath/matrix4.cpp.o
.PHONY : tools/cmMath/matrix4.o

# target to build an object file
tools/cmMath/matrix4.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/cmMath/matrix4.cpp.o
.PHONY : tools/cmMath/matrix4.cpp.o

tools/cmMath/matrix4.i: tools/cmMath/matrix4.cpp.i
.PHONY : tools/cmMath/matrix4.i

# target to preprocess a source file
tools/cmMath/matrix4.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/cmMath/matrix4.cpp.i
.PHONY : tools/cmMath/matrix4.cpp.i

tools/cmMath/matrix4.s: tools/cmMath/matrix4.cpp.s
.PHONY : tools/cmMath/matrix4.s

# target to generate assembly for a file
tools/cmMath/matrix4.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/tools/cmMath/matrix4.cpp.s
.PHONY : tools/cmMath/matrix4.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... pai"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... tools/B0.o"
	@echo "... tools/B0.i"
	@echo "... tools/B0.s"
	@echo "... tools/B1.o"
	@echo "... tools/B1.i"
	@echo "... tools/B1.s"
	@echo "... tools/B2.o"
	@echo "... tools/B2.i"
	@echo "... tools/B2.s"
	@echo "... tools/R0.o"
	@echo "... tools/R0.i"
	@echo "... tools/R0.s"
	@echo "... tools/T0.o"
	@echo "... tools/T0.i"
	@echo "... tools/T0.s"
	@echo "... tools/U0.o"
	@echo "... tools/U0.i"
	@echo "... tools/U0.s"
	@echo "... tools/cmMath/matrix4.o"
	@echo "... tools/cmMath/matrix4.i"
	@echo "... tools/cmMath/matrix4.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

