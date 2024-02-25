# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

classes/base/Camera.o: classes/base/Camera.cpp.o
.PHONY : classes/base/Camera.o

# target to build an object file
classes/base/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Camera.cpp.o
.PHONY : classes/base/Camera.cpp.o

classes/base/Camera.i: classes/base/Camera.cpp.i
.PHONY : classes/base/Camera.i

# target to preprocess a source file
classes/base/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Camera.cpp.i
.PHONY : classes/base/Camera.cpp.i

classes/base/Camera.s: classes/base/Camera.cpp.s
.PHONY : classes/base/Camera.s

# target to generate assembly for a file
classes/base/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Camera.cpp.s
.PHONY : classes/base/Camera.cpp.s

classes/base/Mesh.o: classes/base/Mesh.cpp.o
.PHONY : classes/base/Mesh.o

# target to build an object file
classes/base/Mesh.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Mesh.cpp.o
.PHONY : classes/base/Mesh.cpp.o

classes/base/Mesh.i: classes/base/Mesh.cpp.i
.PHONY : classes/base/Mesh.i

# target to preprocess a source file
classes/base/Mesh.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Mesh.cpp.i
.PHONY : classes/base/Mesh.cpp.i

classes/base/Mesh.s: classes/base/Mesh.cpp.s
.PHONY : classes/base/Mesh.s

# target to generate assembly for a file
classes/base/Mesh.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Mesh.cpp.s
.PHONY : classes/base/Mesh.cpp.s

classes/base/Transform.o: classes/base/Transform.cpp.o
.PHONY : classes/base/Transform.o

# target to build an object file
classes/base/Transform.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Transform.cpp.o
.PHONY : classes/base/Transform.cpp.o

classes/base/Transform.i: classes/base/Transform.cpp.i
.PHONY : classes/base/Transform.i

# target to preprocess a source file
classes/base/Transform.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Transform.cpp.i
.PHONY : classes/base/Transform.cpp.i

classes/base/Transform.s: classes/base/Transform.cpp.s
.PHONY : classes/base/Transform.s

# target to generate assembly for a file
classes/base/Transform.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/base/Transform.cpp.s
.PHONY : classes/base/Transform.cpp.s

classes/cmMath/matrix4.o: classes/cmMath/matrix4.cpp.o
.PHONY : classes/cmMath/matrix4.o

# target to build an object file
classes/cmMath/matrix4.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o
.PHONY : classes/cmMath/matrix4.cpp.o

classes/cmMath/matrix4.i: classes/cmMath/matrix4.cpp.i
.PHONY : classes/cmMath/matrix4.i

# target to preprocess a source file
classes/cmMath/matrix4.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.i
.PHONY : classes/cmMath/matrix4.cpp.i

classes/cmMath/matrix4.s: classes/cmMath/matrix4.cpp.s
.PHONY : classes/cmMath/matrix4.s

# target to generate assembly for a file
classes/cmMath/matrix4.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.s
.PHONY : classes/cmMath/matrix4.cpp.s

classes/cmMath/vectors.o: classes/cmMath/vectors.cpp.o
.PHONY : classes/cmMath/vectors.o

# target to build an object file
classes/cmMath/vectors.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o
.PHONY : classes/cmMath/vectors.cpp.o

classes/cmMath/vectors.i: classes/cmMath/vectors.cpp.i
.PHONY : classes/cmMath/vectors.i

# target to preprocess a source file
classes/cmMath/vectors.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.i
.PHONY : classes/cmMath/vectors.cpp.i

classes/cmMath/vectors.s: classes/cmMath/vectors.cpp.s
.PHONY : classes/cmMath/vectors.s

# target to generate assembly for a file
classes/cmMath/vectors.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.s
.PHONY : classes/cmMath/vectors.cpp.s

classes/graphics/CMGL_Program.o: classes/graphics/CMGL_Program.cpp.o
.PHONY : classes/graphics/CMGL_Program.o

# target to build an object file
classes/graphics/CMGL_Program.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o
.PHONY : classes/graphics/CMGL_Program.cpp.o

classes/graphics/CMGL_Program.i: classes/graphics/CMGL_Program.cpp.i
.PHONY : classes/graphics/CMGL_Program.i

# target to preprocess a source file
classes/graphics/CMGL_Program.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.i
.PHONY : classes/graphics/CMGL_Program.cpp.i

classes/graphics/CMGL_Program.s: classes/graphics/CMGL_Program.cpp.s
.PHONY : classes/graphics/CMGL_Program.s

# target to generate assembly for a file
classes/graphics/CMGL_Program.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.s
.PHONY : classes/graphics/CMGL_Program.cpp.s

classes/graphics/CMGL_Shader.o: classes/graphics/CMGL_Shader.cpp.o
.PHONY : classes/graphics/CMGL_Shader.o

# target to build an object file
classes/graphics/CMGL_Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o
.PHONY : classes/graphics/CMGL_Shader.cpp.o

classes/graphics/CMGL_Shader.i: classes/graphics/CMGL_Shader.cpp.i
.PHONY : classes/graphics/CMGL_Shader.i

# target to preprocess a source file
classes/graphics/CMGL_Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.i
.PHONY : classes/graphics/CMGL_Shader.cpp.i

classes/graphics/CMGL_Shader.s: classes/graphics/CMGL_Shader.cpp.s
.PHONY : classes/graphics/CMGL_Shader.s

# target to generate assembly for a file
classes/graphics/CMGL_Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.s
.PHONY : classes/graphics/CMGL_Shader.cpp.s

classes/opengl/CMGL_GameObject.o: classes/opengl/CMGL_GameObject.cpp.o
.PHONY : classes/opengl/CMGL_GameObject.o

# target to build an object file
classes/opengl/CMGL_GameObject.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o
.PHONY : classes/opengl/CMGL_GameObject.cpp.o

classes/opengl/CMGL_GameObject.i: classes/opengl/CMGL_GameObject.cpp.i
.PHONY : classes/opengl/CMGL_GameObject.i

# target to preprocess a source file
classes/opengl/CMGL_GameObject.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.i
.PHONY : classes/opengl/CMGL_GameObject.cpp.i

classes/opengl/CMGL_GameObject.s: classes/opengl/CMGL_GameObject.cpp.s
.PHONY : classes/opengl/CMGL_GameObject.s

# target to generate assembly for a file
classes/opengl/CMGL_GameObject.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.s
.PHONY : classes/opengl/CMGL_GameObject.cpp.s

classes/opengl/CMGL_Renderer.o: classes/opengl/CMGL_Renderer.cpp.o
.PHONY : classes/opengl/CMGL_Renderer.o

# target to build an object file
classes/opengl/CMGL_Renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o
.PHONY : classes/opengl/CMGL_Renderer.cpp.o

classes/opengl/CMGL_Renderer.i: classes/opengl/CMGL_Renderer.cpp.i
.PHONY : classes/opengl/CMGL_Renderer.i

# target to preprocess a source file
classes/opengl/CMGL_Renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.i
.PHONY : classes/opengl/CMGL_Renderer.cpp.i

classes/opengl/CMGL_Renderer.s: classes/opengl/CMGL_Renderer.cpp.s
.PHONY : classes/opengl/CMGL_Renderer.s

# target to generate assembly for a file
classes/opengl/CMGL_Renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.s
.PHONY : classes/opengl/CMGL_Renderer.cpp.s

classes/opengl/CMGL_Texture.o: classes/opengl/CMGL_Texture.cpp.o
.PHONY : classes/opengl/CMGL_Texture.o

# target to build an object file
classes/opengl/CMGL_Texture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o
.PHONY : classes/opengl/CMGL_Texture.cpp.o

classes/opengl/CMGL_Texture.i: classes/opengl/CMGL_Texture.cpp.i
.PHONY : classes/opengl/CMGL_Texture.i

# target to preprocess a source file
classes/opengl/CMGL_Texture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.i
.PHONY : classes/opengl/CMGL_Texture.cpp.i

classes/opengl/CMGL_Texture.s: classes/opengl/CMGL_Texture.cpp.s
.PHONY : classes/opengl/CMGL_Texture.s

# target to generate assembly for a file
classes/opengl/CMGL_Texture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.s
.PHONY : classes/opengl/CMGL_Texture.cpp.s

classes/system/Image.o: classes/system/Image.cpp.o
.PHONY : classes/system/Image.o

# target to build an object file
classes/system/Image.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Image.cpp.o
.PHONY : classes/system/Image.cpp.o

classes/system/Image.i: classes/system/Image.cpp.i
.PHONY : classes/system/Image.i

# target to preprocess a source file
classes/system/Image.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Image.cpp.i
.PHONY : classes/system/Image.cpp.i

classes/system/Image.s: classes/system/Image.cpp.s
.PHONY : classes/system/Image.s

# target to generate assembly for a file
classes/system/Image.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Image.cpp.s
.PHONY : classes/system/Image.cpp.s

classes/system/U0.o: classes/system/U0.cpp.o
.PHONY : classes/system/U0.o

# target to build an object file
classes/system/U0.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/U0.cpp.o
.PHONY : classes/system/U0.cpp.o

classes/system/U0.i: classes/system/U0.cpp.i
.PHONY : classes/system/U0.i

# target to preprocess a source file
classes/system/U0.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/U0.cpp.i
.PHONY : classes/system/U0.cpp.i

classes/system/U0.s: classes/system/U0.cpp.s
.PHONY : classes/system/U0.s

# target to generate assembly for a file
classes/system/U0.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/U0.cpp.s
.PHONY : classes/system/U0.cpp.s

classes/system/Window.o: classes/system/Window.cpp.o
.PHONY : classes/system/Window.o

# target to build an object file
classes/system/Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Window.cpp.o
.PHONY : classes/system/Window.cpp.o

classes/system/Window.i: classes/system/Window.cpp.i
.PHONY : classes/system/Window.i

# target to preprocess a source file
classes/system/Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Window.cpp.i
.PHONY : classes/system/Window.cpp.i

classes/system/Window.s: classes/system/Window.cpp.s
.PHONY : classes/system/Window.s

# target to generate assembly for a file
classes/system/Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pai.dir/build.make CMakeFiles/pai.dir/classes/system/Window.cpp.s
.PHONY : classes/system/Window.cpp.s

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

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... pai"
	@echo "... classes/base/Camera.o"
	@echo "... classes/base/Camera.i"
	@echo "... classes/base/Camera.s"
	@echo "... classes/base/Mesh.o"
	@echo "... classes/base/Mesh.i"
	@echo "... classes/base/Mesh.s"
	@echo "... classes/base/Transform.o"
	@echo "... classes/base/Transform.i"
	@echo "... classes/base/Transform.s"
	@echo "... classes/cmMath/matrix4.o"
	@echo "... classes/cmMath/matrix4.i"
	@echo "... classes/cmMath/matrix4.s"
	@echo "... classes/cmMath/vectors.o"
	@echo "... classes/cmMath/vectors.i"
	@echo "... classes/cmMath/vectors.s"
	@echo "... classes/graphics/CMGL_Program.o"
	@echo "... classes/graphics/CMGL_Program.i"
	@echo "... classes/graphics/CMGL_Program.s"
	@echo "... classes/graphics/CMGL_Shader.o"
	@echo "... classes/graphics/CMGL_Shader.i"
	@echo "... classes/graphics/CMGL_Shader.s"
	@echo "... classes/opengl/CMGL_GameObject.o"
	@echo "... classes/opengl/CMGL_GameObject.i"
	@echo "... classes/opengl/CMGL_GameObject.s"
	@echo "... classes/opengl/CMGL_Renderer.o"
	@echo "... classes/opengl/CMGL_Renderer.i"
	@echo "... classes/opengl/CMGL_Renderer.s"
	@echo "... classes/opengl/CMGL_Texture.o"
	@echo "... classes/opengl/CMGL_Texture.i"
	@echo "... classes/opengl/CMGL_Texture.s"
	@echo "... classes/system/Image.o"
	@echo "... classes/system/Image.i"
	@echo "... classes/system/Image.s"
	@echo "... classes/system/U0.o"
	@echo "... classes/system/U0.i"
	@echo "... classes/system/U0.s"
	@echo "... classes/system/Window.o"
	@echo "... classes/system/Window.i"
	@echo "... classes/system/Window.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

