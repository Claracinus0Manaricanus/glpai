cmake_minimum_required(VERSION 3.25.0)
project("glpai")

add_executable("pai" "main.cpp"  
"tools/Camera.cpp" "tools/CubeMap.cpp" "tools/GameObject.cpp"
"tools/Light.cpp" "tools/Program.cpp" "tools/SceneManager.cpp"
"tools/Shader.cpp" "tools/SkyBox.cpp" "tools/Texture.cpp"
"tools/Transform.cpp" "tools/UI_Element.cpp" "tools/VertexData.cpp"
"tools/Window.cpp"
"tools/U0.cpp"
"tools/cmMath/matrix4.cpp" "tools/cmMath/vectors.cpp")

target_link_libraries(pai PUBLIC GL GLEW glfw)