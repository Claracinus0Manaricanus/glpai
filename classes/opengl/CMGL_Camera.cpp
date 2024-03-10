#include "CMGL_Camera.hpp"

//initializers
void CMGL_Camera::initBuffers(){
    glGenBuffers(1, &SSB);
}


//constructors
CMGL_Camera::CMGL_Camera(){
    initBuffers();
    updateTransform();
}

CMGL_Camera::CMGL_Camera(int iFov, int iType):
Camera(iFov, iType){
    initBuffers();
    updateTransform();
}


//destructors
CMGL_Camera::~CMGL_Camera(){
    glDeleteBuffers(1, &SSB);
}


//utility
void CMGL_Camera::bind(){
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 5, SSB, 0, sizeof(float)*16);
}


//Transform overrides
void CMGL_Camera::updateTransform(){
    float* CVM = generateCVM();
    m4_transpose(CVM);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, CVM, GL_DYNAMIC_DRAW);

    free(CVM);
}