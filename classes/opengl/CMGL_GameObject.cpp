#include "CMGL_GameObject.hpp"

//utility
int CMGL_GameObject::initBuffers(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EAB);

    return 0;
}

int CMGL_GameObject::update(){
    glBindVertexArray(VAO);
    
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

    if(Mesh::fCount != 0){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EAB);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*Mesh::fCount*3, Mesh::faces, GL_DYNAMIC_DRAW);
    }

    return 0;
}


//constructors
CMGL_GameObject::CMGL_GameObject(){
    initBuffers();
}

CMGL_GameObject::CMGL_GameObject(MeshData inputMesh, TransformData inputTransform):
Transform(inputTransform), Mesh(inputMesh){
    initBuffers();
    update();
}


//destructors
CMGL_GameObject::~CMGL_GameObject(){
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EAB);
    glDeleteVertexArrays(1, &VAO);
}


//setters
void CMGL_GameObject::loadData(MeshData inputMesh, TransformData inputTransform){
    Transform::loadData(inputTransform);
    Mesh::loadData(inputMesh);
    update();
}

void CMGL_GameObject::loadData(MeshData inputMesh){
    Mesh::loadData(inputMesh);
    update();
}

int CMGL_GameObject::loadTexture(TextureData inputData){
    return CMGL_Texture::loadData(inputData);
}


//getters


//binder
void CMGL_GameObject::bind(){
    glBindVertexArray(VAO);
    CMGL_Texture::bind();
}