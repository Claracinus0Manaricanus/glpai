#ifndef CMGL_GAMEOBJECT
#define CMGL_GAMEOBJECT

#include "../base/Mesh.hpp"
#include "../base/Transform.hpp"
#include "CMGL_Texture.hpp"

#include <GL/glew.h>//needs change, used for opengl functions

class CMGL_GameObject : public Mesh, public Transform, public CMGL_Texture{
protected:
    uint32_t VAO,VBO,EAB;//vertex array object, vertex buffer object, element array buffer

protected:
    int initBuffers();
    int update();

public:
    //constructors
    CMGL_GameObject();
    CMGL_GameObject(MeshData inputMesh, TransformData inputTransform);

    //destructors
    ~CMGL_GameObject();

    //setters
    void loadData(MeshData inputMesh, TransformData inputTransform);
    void loadData(MeshData inputMesh);
    int loadTexture(TextureData inputData);

    //getters
    

    //binder
    void bind();
};

#endif