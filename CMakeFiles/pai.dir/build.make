# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/cm/codes/c++/glpai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cm/codes/c++/glpai

# Include any dependencies generated for this target.
include CMakeFiles/pai.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pai.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pai.dir/flags.make

CMakeFiles/pai.dir/main.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/main.cpp.o: main.cpp
CMakeFiles/pai.dir/main.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pai.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/main.cpp.o -MF CMakeFiles/pai.dir/main.cpp.o.d -o CMakeFiles/pai.dir/main.cpp.o -c /home/cm/codes/c++/glpai/main.cpp

CMakeFiles/pai.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/main.cpp > CMakeFiles/pai.dir/main.cpp.i

CMakeFiles/pai.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/main.cpp -o CMakeFiles/pai.dir/main.cpp.s

CMakeFiles/pai.dir/classes/base/Mesh.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/base/Mesh.cpp.o: classes/base/Mesh.cpp
CMakeFiles/pai.dir/classes/base/Mesh.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pai.dir/classes/base/Mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/base/Mesh.cpp.o -MF CMakeFiles/pai.dir/classes/base/Mesh.cpp.o.d -o CMakeFiles/pai.dir/classes/base/Mesh.cpp.o -c /home/cm/codes/c++/glpai/classes/base/Mesh.cpp

CMakeFiles/pai.dir/classes/base/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/base/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/base/Mesh.cpp > CMakeFiles/pai.dir/classes/base/Mesh.cpp.i

CMakeFiles/pai.dir/classes/base/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/base/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/base/Mesh.cpp -o CMakeFiles/pai.dir/classes/base/Mesh.cpp.s

CMakeFiles/pai.dir/classes/base/Transform.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/base/Transform.cpp.o: classes/base/Transform.cpp
CMakeFiles/pai.dir/classes/base/Transform.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pai.dir/classes/base/Transform.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/base/Transform.cpp.o -MF CMakeFiles/pai.dir/classes/base/Transform.cpp.o.d -o CMakeFiles/pai.dir/classes/base/Transform.cpp.o -c /home/cm/codes/c++/glpai/classes/base/Transform.cpp

CMakeFiles/pai.dir/classes/base/Transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/base/Transform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/base/Transform.cpp > CMakeFiles/pai.dir/classes/base/Transform.cpp.i

CMakeFiles/pai.dir/classes/base/Transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/base/Transform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/base/Transform.cpp -o CMakeFiles/pai.dir/classes/base/Transform.cpp.s

CMakeFiles/pai.dir/classes/base/Camera.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/base/Camera.cpp.o: classes/base/Camera.cpp
CMakeFiles/pai.dir/classes/base/Camera.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pai.dir/classes/base/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/base/Camera.cpp.o -MF CMakeFiles/pai.dir/classes/base/Camera.cpp.o.d -o CMakeFiles/pai.dir/classes/base/Camera.cpp.o -c /home/cm/codes/c++/glpai/classes/base/Camera.cpp

CMakeFiles/pai.dir/classes/base/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/base/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/base/Camera.cpp > CMakeFiles/pai.dir/classes/base/Camera.cpp.i

CMakeFiles/pai.dir/classes/base/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/base/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/base/Camera.cpp -o CMakeFiles/pai.dir/classes/base/Camera.cpp.s

CMakeFiles/pai.dir/classes/base/Light.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/base/Light.cpp.o: classes/base/Light.cpp
CMakeFiles/pai.dir/classes/base/Light.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pai.dir/classes/base/Light.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/base/Light.cpp.o -MF CMakeFiles/pai.dir/classes/base/Light.cpp.o.d -o CMakeFiles/pai.dir/classes/base/Light.cpp.o -c /home/cm/codes/c++/glpai/classes/base/Light.cpp

CMakeFiles/pai.dir/classes/base/Light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/base/Light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/base/Light.cpp > CMakeFiles/pai.dir/classes/base/Light.cpp.i

CMakeFiles/pai.dir/classes/base/Light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/base/Light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/base/Light.cpp -o CMakeFiles/pai.dir/classes/base/Light.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o: classes/opengl/CMGL_GameObject.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_GameObject.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_GameObject.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_GameObject.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o: classes/opengl/CMGL_Texture.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_Texture.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_Texture.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_Texture.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o: classes/opengl/CMGL_Renderer.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_Renderer.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_Renderer.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_Renderer.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o: classes/opengl/CMGL_Camera.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_Camera.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_Camera.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_Camera.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o: classes/opengl/CMGL_CubeMap.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_CubeMap.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_CubeMap.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_CubeMap.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o: classes/opengl/CMGL_Framebuffer.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_Framebuffer.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_Framebuffer.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_Framebuffer.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.s

CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o: classes/opengl/CMGL_DirectLight.cpp
CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o -MF CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o.d -o CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o -c /home/cm/codes/c++/glpai/classes/opengl/CMGL_DirectLight.cpp

CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/opengl/CMGL_DirectLight.cpp > CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.i

CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/opengl/CMGL_DirectLight.cpp -o CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.s

CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o: classes/graphics/CMGL_Shader.cpp
CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o -MF CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o.d -o CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o -c /home/cm/codes/c++/glpai/classes/graphics/CMGL_Shader.cpp

CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/graphics/CMGL_Shader.cpp > CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.i

CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/graphics/CMGL_Shader.cpp -o CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.s

CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o: classes/graphics/CMGL_Program.cpp
CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o -MF CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o.d -o CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o -c /home/cm/codes/c++/glpai/classes/graphics/CMGL_Program.cpp

CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/graphics/CMGL_Program.cpp > CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.i

CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/graphics/CMGL_Program.cpp -o CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.s

CMakeFiles/pai.dir/classes/system/Window.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/system/Window.cpp.o: classes/system/Window.cpp
CMakeFiles/pai.dir/classes/system/Window.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/pai.dir/classes/system/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/system/Window.cpp.o -MF CMakeFiles/pai.dir/classes/system/Window.cpp.o.d -o CMakeFiles/pai.dir/classes/system/Window.cpp.o -c /home/cm/codes/c++/glpai/classes/system/Window.cpp

CMakeFiles/pai.dir/classes/system/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/system/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/system/Window.cpp > CMakeFiles/pai.dir/classes/system/Window.cpp.i

CMakeFiles/pai.dir/classes/system/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/system/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/system/Window.cpp -o CMakeFiles/pai.dir/classes/system/Window.cpp.s

CMakeFiles/pai.dir/classes/system/U0.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/system/U0.cpp.o: classes/system/U0.cpp
CMakeFiles/pai.dir/classes/system/U0.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/pai.dir/classes/system/U0.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/system/U0.cpp.o -MF CMakeFiles/pai.dir/classes/system/U0.cpp.o.d -o CMakeFiles/pai.dir/classes/system/U0.cpp.o -c /home/cm/codes/c++/glpai/classes/system/U0.cpp

CMakeFiles/pai.dir/classes/system/U0.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/system/U0.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/system/U0.cpp > CMakeFiles/pai.dir/classes/system/U0.cpp.i

CMakeFiles/pai.dir/classes/system/U0.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/system/U0.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/system/U0.cpp -o CMakeFiles/pai.dir/classes/system/U0.cpp.s

CMakeFiles/pai.dir/classes/system/Image.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/system/Image.cpp.o: classes/system/Image.cpp
CMakeFiles/pai.dir/classes/system/Image.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/pai.dir/classes/system/Image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/system/Image.cpp.o -MF CMakeFiles/pai.dir/classes/system/Image.cpp.o.d -o CMakeFiles/pai.dir/classes/system/Image.cpp.o -c /home/cm/codes/c++/glpai/classes/system/Image.cpp

CMakeFiles/pai.dir/classes/system/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/system/Image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/system/Image.cpp > CMakeFiles/pai.dir/classes/system/Image.cpp.i

CMakeFiles/pai.dir/classes/system/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/system/Image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/system/Image.cpp -o CMakeFiles/pai.dir/classes/system/Image.cpp.s

CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o: classes/cmMath/matrix4.cpp
CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o -MF CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o.d -o CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o -c /home/cm/codes/c++/glpai/classes/cmMath/matrix4.cpp

CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/cmMath/matrix4.cpp > CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.i

CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/cmMath/matrix4.cpp -o CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.s

CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o: classes/cmMath/vectors.cpp
CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o -MF CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o.d -o CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o -c /home/cm/codes/c++/glpai/classes/cmMath/vectors.cpp

CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/classes/cmMath/vectors.cpp > CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.i

CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/classes/cmMath/vectors.cpp -o CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.s

CMakeFiles/pai.dir/include/implementations/Client.cpp.o: CMakeFiles/pai.dir/flags.make
CMakeFiles/pai.dir/include/implementations/Client.cpp.o: include/implementations/Client.cpp
CMakeFiles/pai.dir/include/implementations/Client.cpp.o: CMakeFiles/pai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/pai.dir/include/implementations/Client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pai.dir/include/implementations/Client.cpp.o -MF CMakeFiles/pai.dir/include/implementations/Client.cpp.o.d -o CMakeFiles/pai.dir/include/implementations/Client.cpp.o -c /home/cm/codes/c++/glpai/include/implementations/Client.cpp

CMakeFiles/pai.dir/include/implementations/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pai.dir/include/implementations/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cm/codes/c++/glpai/include/implementations/Client.cpp > CMakeFiles/pai.dir/include/implementations/Client.cpp.i

CMakeFiles/pai.dir/include/implementations/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pai.dir/include/implementations/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cm/codes/c++/glpai/include/implementations/Client.cpp -o CMakeFiles/pai.dir/include/implementations/Client.cpp.s

# Object files for target pai
pai_OBJECTS = \
"CMakeFiles/pai.dir/main.cpp.o" \
"CMakeFiles/pai.dir/classes/base/Mesh.cpp.o" \
"CMakeFiles/pai.dir/classes/base/Transform.cpp.o" \
"CMakeFiles/pai.dir/classes/base/Camera.cpp.o" \
"CMakeFiles/pai.dir/classes/base/Light.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o" \
"CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o" \
"CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o" \
"CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o" \
"CMakeFiles/pai.dir/classes/system/Window.cpp.o" \
"CMakeFiles/pai.dir/classes/system/U0.cpp.o" \
"CMakeFiles/pai.dir/classes/system/Image.cpp.o" \
"CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o" \
"CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o" \
"CMakeFiles/pai.dir/include/implementations/Client.cpp.o"

# External object files for target pai
pai_EXTERNAL_OBJECTS =

pai: CMakeFiles/pai.dir/main.cpp.o
pai: CMakeFiles/pai.dir/classes/base/Mesh.cpp.o
pai: CMakeFiles/pai.dir/classes/base/Transform.cpp.o
pai: CMakeFiles/pai.dir/classes/base/Camera.cpp.o
pai: CMakeFiles/pai.dir/classes/base/Light.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_GameObject.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_Texture.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_Renderer.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_Camera.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_CubeMap.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_Framebuffer.cpp.o
pai: CMakeFiles/pai.dir/classes/opengl/CMGL_DirectLight.cpp.o
pai: CMakeFiles/pai.dir/classes/graphics/CMGL_Shader.cpp.o
pai: CMakeFiles/pai.dir/classes/graphics/CMGL_Program.cpp.o
pai: CMakeFiles/pai.dir/classes/system/Window.cpp.o
pai: CMakeFiles/pai.dir/classes/system/U0.cpp.o
pai: CMakeFiles/pai.dir/classes/system/Image.cpp.o
pai: CMakeFiles/pai.dir/classes/cmMath/matrix4.cpp.o
pai: CMakeFiles/pai.dir/classes/cmMath/vectors.cpp.o
pai: CMakeFiles/pai.dir/include/implementations/Client.cpp.o
pai: CMakeFiles/pai.dir/build.make
pai: CMakeFiles/pai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/cm/codes/c++/glpai/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable pai"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pai.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pai.dir/build: pai
.PHONY : CMakeFiles/pai.dir/build

CMakeFiles/pai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pai.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pai.dir/clean

CMakeFiles/pai.dir/depend:
	cd /home/cm/codes/c++/glpai && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cm/codes/c++/glpai /home/cm/codes/c++/glpai /home/cm/codes/c++/glpai /home/cm/codes/c++/glpai /home/cm/codes/c++/glpai/CMakeFiles/pai.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pai.dir/depend

