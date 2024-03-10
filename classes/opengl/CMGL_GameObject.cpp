#include "CMGL_GameObject.hpp"

//utility
int CMGL_GameObject::initBuffers(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EAB);
    glGenBuffers(1, &SSB);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*19, NULL, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

    return 0;
}

int CMGL_GameObject::update(){
    glBindVertexArray(VAO);
    
    /****Array Buffer****/
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*Mesh::vCount, Mesh::vertices, GL_DYNAMIC_DRAW);

    //position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    //normals
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    //color
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    //texture coordinates
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(10*sizeof(float)));
    glEnableVertexAttribArray(3);

    /****Element Array Buffer****/
    if(Mesh::fCount != 0){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EAB);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*Mesh::fCount*3, Mesh::faces, GL_DYNAMIC_DRAW);
    }

    return 0;
}

void CMGL_GameObject::updateSSB(){
    /****Shader Storage Buffer****/
    float* OVM = generateOVM();
    m4_transpose(OVM);
    
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(float)*16, OVM);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, sizeof(float)*3, &Scale);

    free(OVM);
}


//constructors
CMGL_GameObject::CMGL_GameObject(){
    initBuffers();
    updateSSB();
}

CMGL_GameObject::CMGL_GameObject(MeshData inputMesh, TransformData inputTransform):
Transform(inputTransform), Mesh(inputMesh){
    initBuffers();
    update();
    updateSSB();
}


//destructors
CMGL_GameObject::~CMGL_GameObject(){
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EAB);
    glDeleteBuffers(1, &SSB);
    glDeleteVertexArrays(1, &VAO);
}


//setters
void CMGL_GameObject::loadData(MeshData inputMesh, TransformData inputTransform){
    Transform::loadData(inputTransform);
    Mesh::loadData(inputMesh);
    update();
}

void CMGL_GameObject::loadMesh(MeshData inputMesh){
    Mesh::loadData(inputMesh);
    update();
}

void CMGL_GameObject::loadTransform(TransformData inputTransform){
    Transform::loadData(inputTransform);
    update();
}

int CMGL_GameObject::loadTexture(TextureData inputData){
    return CMGL_Texture::loadData(inputData);
}

int CMGL_GameObject::loadTexture(CMGL_Texture& inputTex){
    return CMGL_Texture::loadData(inputTex);
}

void CMGL_GameObject::enableLookAt(vec3 lookVec){
    isLookingAt = true;
    lookVector = lookVec;
    updateTransform();
}

void CMGL_GameObject::disableLookAt(){
    isLookingAt = false;
    updateTransform();
}



//getters
bool CMGL_GameObject::getLookingAt(){
    return isLookingAt;
}


//Matrices
float* CMGL_GameObject::generateOVM(){

    float translate[16]={
        1,0,0,Position.x,
        0,1,0,Position.y,
        0,0,1,Position.z,
        0,0,0,1
    };
    
    if(isLookingAt){
        Transform::lookAt(lookVector, {0,1,0});
    }else{
        generateVectors();
    }

    float rotMat[16]={
        rightVector.x, upVector.x, forwardVector.x, 0,
        rightVector.y, upVector.y, forwardVector.y, 0,
        rightVector.z, upVector.z, forwardVector.z, 0,
        0, 0, 0, 1,
    };

    float * ret = m4_multiplyNew(translate, rotMat);

    return ret;
}


//binder
void CMGL_GameObject::bind(){
    glBindVertexArray(VAO);
    CMGL_Texture::bind();
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 4, SSB, 0, sizeof(float)*19);
}

void CMGL_GameObject::bindWT(){
    glBindVertexArray(VAO);
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 4, SSB, 0, sizeof(float)*19);
}


//Trasnform overrides
void CMGL_GameObject::updateTransform(){
    updateSSB();
}