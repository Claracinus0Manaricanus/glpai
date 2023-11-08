cmake_minimum_required(VERSION 3.25.0)
project("glpai")

add_executable("pai" "main.cpp" "tools/B0.cpp" 
"tools/B1.cpp" "tools/B2.cpp" "tools/R0.cpp" 
"tools/T0.cpp" "tools/U0.cpp" "tools/cmMath/matrix4.cpp")

target_link_libraries(pai PUBLIC GL GLEW glfw)