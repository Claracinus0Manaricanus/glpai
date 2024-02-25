# Location
classes/opengl/

# Inherits
CMGL_Base, Transform, Mesh, CMGL_Texture

# Purpose
Used with opengl renderers to render meshes. It uses MeshData to create opengl buffers and matrices.

# Protected Data
- uint32_t VAO, VBO, EAB, SSB;

# Protected Functions
- int initBuffers();  
Used in constructors to init buffers.
- int update();  
Used to update opengl buffers after data changes.

# Public Functions
- CMGL_GameObjects();  
No parameter constructor.
-
- CMGL_GameObject(MeshData inputMesh, TransformData inputTransform);  
Constructors with two parameters.
-
- ~CMGL_GameObject();  
Destructor.
-
- void loadData(MeshData inputMesh, TransformData inputTransform);  
Data loader with two parameters. Similar to two parameter constructor.
-
- void loadMeshData(MeshData inputMesh);  
Loades new MeshData.
-
- int loadTexture(TextureData inputData);  
Loades new TextureData.
-
- float* generateOVM();  
Generates object view matrix.
-
- void bind();  
Binds gameObject for use with renderer.

# Friend Classes
- CMGL_Renderer