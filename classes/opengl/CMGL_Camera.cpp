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

void CMGL_Camera::unbind(){
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 5, 0, 0, NULL);
}

void CMGL_Camera::render(CMGL_GameObject* objects, int objectsCount, CMGL_Framebuffer& FB, CMGL_Program& program){
    bind();
    CMGL_Renderer::renderGameObjects(objects, objectsCount, FB, program);
}


//Transform overrides
void CMGL_Camera::updateTransform(){
    updateOVM();

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, OVM, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}