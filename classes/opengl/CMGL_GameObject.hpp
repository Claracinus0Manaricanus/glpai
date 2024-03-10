#ifndef CMGL_GAMEOBJECT
#define CMGL_GAMEOBJECT

#include "../base/Mesh.hpp"
#include "../base/Transform.hpp"
#include "CMGL_Texture.hpp"
#include "CMGL_Base.hpp"

#include "../cmMath/matrix4.hpp"

#include <cmath>
#include <GL/glew.h>//needs change, used for opengl functions

class CMGL_GameObject : public Mesh, public Transform, public CMGL_Texture, public CMGL_Base{
protected:
    uint32_t VAO,VBO,EAB,SSB;//vertex array object, vertex buffer object, element array buffer, shader storage buffer
    bool isLookingAt = false;
    vec3 lookVector = {0,0,0};

protected:
    int initBuffers();
    int update();
    void updateSSB();

public:
    //constructors
    CMGL_GameObject();
    CMGL_GameObject(MeshData inputMesh, TransformData inputTransform);

    //destructors
    ~CMGL_GameObject();

    //setters
    void loadData(MeshData inputMesh, TransformData inputTransform);
    void loadMesh(MeshData inputMesh);
    void loadTransform(TransformData inputTransform);
    int loadTexture(TextureData inputData);
    int loadTexture(CMGL_Texture& inputTex);
    void enableLookAt(vec3 lookVec);
    void disableLookAt();

    //getters
    bool getLookingAt();

    //Matrices
    float* generateOVM();

    //binder
    void bind();
    void bindWT();//without texture

    //Transform overrides
    void updateTransform() override;
};

#endif