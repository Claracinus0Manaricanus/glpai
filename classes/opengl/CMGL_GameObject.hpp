#ifndef CMGL_GAMEOBJECT
#define CMGL_GAMEOBJECT

#include "../base/Mesh.hpp"
#include "../base/Transform.hpp"
#include "CMGL_Texture.hpp"
#include "CMGL_Base.hpp"

#include "../cmMath/matrix4.hpp"

#include <cmath>
#include <GL/glew.h>//needs change, used for opengl functions

//note: binds ssb to binding 4

class CMGL_GameObject : public Mesh, public Transform, public CMGL_Texture, public CMGL_Base{
protected:
    uint32_t VAO,VBO,EAB,SSB;//vertex array object, vertex buffer object, element array buffer, shader storage buffer

protected:
    int initBuffers();
    int update();
    void updateSSB();

public:
    //constructors
    CMGL_GameObject();
    CMGL_GameObject(ObjectData inData);

    //destructors
    ~CMGL_GameObject();

    //setters
    void loadData(ObjectData inData);
    void loadMesh(MeshData inputMesh);
    void loadTransform(TransformData inputTransform);
    int loadTexture(TextureData inputData);
    int loadTexture(CMGL_Texture& inputTex, bool clean = true);

    //binder
    void bind();
    void bindWT();//without texture
    void unbind();

    //Transform overrides
    void updateTransform() override;
};

#endif