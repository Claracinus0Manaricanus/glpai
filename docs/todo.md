# docs
- CMGL_Texture
- Mesh
- U0
- T0
- Camera
- CMGL_Camera
- CMGL_CubeMap
- CMGL_Program
- Light
- CMGL_Renderer
- CMGL_GameObject
- Transform
- CMGL_Framebuffer

# when I feel like it
- seperating opengl from glew and glfw to support custom libraries
- adding (optional) "auto" support for glfw and glew
- audio support
- mipmaps for textures
- perspective projection matrix that keeps Z data
- find where the memory leak is
- optimize OVM and CVM calculations

# Just Do It
- Window class getCursorPos
- Window class setCursorPos
- SceneManager
- fix heightmaps

# done (gets cleared once in a while)
- OVM now at Transform
- added m4_copy to copy 4D matrices
- updated CMGL_GameObject to use OVM from transform
- updated camera to use OVM from transform
- added shadow precision float to CMGL_DirectLight