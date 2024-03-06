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
    float* transposeOfOVM = m4_transpose(OVM);
    
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(float)*16, transposeOfOVM);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, sizeof(float)*3, &Scale);

    free(transposeOfOVM);
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


//Matrices
float* CMGL_GameObject::generateOVM(){

    float translate[16]={
        1,0,0,Position.x,
        0,1,0,Position.y,
        0,0,1,Position.z,
        0,0,0,1
    };
    
    float cosine = cos(Rotation.x);
    float sine = sin(Rotation.x);
    float rotX[16] = {
        1, 0, 0, 0,
        0, cosine, -sine, 0,
        0, sine,  cosine, 0,
        0, 0, 0, 1
    };

    cosine = cos(Rotation.y);
    sine = sin(Rotation.y);
    float rotY[16] = {
         cosine, 0, sine, 0,
         0, 1, 0, 0,
        -sine, 0, cosine, 0,
         0, 0, 0, 1
    };

    cosine = cos(Rotation.z);
    sine = sin(Rotation.z);
    float rotZ[16] = {
        cosine, -sine, 0, 0,
        sine,  cosine, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    float* tmp1M4 = m4_multiply(rotY, rotX);
    float* tmp2M4 = m4_multiply(rotZ, tmp1M4);
    free(tmp1M4);
    tmp1M4 = m4_multiply(translate, tmp2M4);
    free(tmp2M4);

    return tmp1M4;
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