cmake_minimum_required(VERSION 3.25.0)
project("glpai")

add_executable(

"pai" "main.cpp"

#actors folder
#"classes/actors/Camera.cpp" "classes/actors/CubeMap.cpp" 
#"classes/actors/GameObject.cpp" "classes/actors/Light.cpp"
#"classes/actors/SceneManager.cpp" "classes/actors/SkyBox.cpp"
#"classes/actors/Transform.cpp" "classes/actors/UI_Element.cpp"
#"classes/actors/Mesh.cpp"

#base folder
"classes/base/Mesh.cpp" "classes/base/Transform.cpp"
"classes/base/Camera.cpp" "classes/base/Light.cpp"

#opengl folder
"classes/opengl/CMGL_GameObject.cpp" "classes/opengl/CMGL_Texture.cpp"
"classes/opengl/CMGL_Renderer.cpp" "classes/opengl/CMGL_Camera.cpp"
"classes/opengl/CMGL_CubeMap.cpp" "classes/opengl/CMGL_Framebuffer.cpp"
"classes/opengl/CMGL_DirectLight.cpp" "classes/opengl/CMGL_Scene.cpp"

#graphics folder
"classes/graphics/CMGL_Shader.cpp" "classes/graphics/CMGL_Program.cpp"

#system folder
"classes/system/Window.cpp" "classes/system/U0.cpp"
"classes/system/Image.cpp"

#cmMath folder
"classes/cmMath/matrix4.cpp" "classes/cmMath/vectors.cpp"

#dataDisplay
"include/implementations/Client.cpp"
)

target_link_libraries(pai PUBLIC GL GLEW glfw)