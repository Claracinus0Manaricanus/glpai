#include "CMGL_DirectLight.hpp"

//constructors
CMGL_DirectLight::CMGL_DirectLight(){
    Light::type = 2;
    
    Light::data = (float*)calloc(8, sizeof(float));
    Light::dataLength = 2;
    
    Light::setColor({1,1,1,1});
    direction = {0,1,0};

    glGenBuffers(1, &SSB);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*24, NULL, GL_DYNAMIC_DRAW);

    updateLight();
}

CMGL_DirectLight::CMGL_DirectLight(DirectLightData data){
    Light::type = 2;
    
    Light::data = (float*)calloc(8, sizeof(float));
    Light::dataLength = 2;
    
    Light::setColor(data.color);
    setDirection(data.direction);

    glGenBuffers(1, &SSB);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);
    glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*24, NULL, GL_DYNAMIC_DRAW);

    updateLight();
}


//destructors
CMGL_DirectLight::~CMGL_DirectLight(){
    glDeleteBuffers(1, &SSB);
    free(LVM);
}


//setters
void CMGL_DirectLight::setDirection(vec3 inDir){
    direction = inDir;

    updateLight();
}

void CMGL_DirectLight::setShadowPrecision(float inP){
    shadowPrecision = inP;
}


//getters
vec3 CMGL_DirectLight::getDirection(){
    return direction;
}


//utility
void CMGL_DirectLight::bind(){
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 6, SSB, 0, sizeof(float)*24);
}

void CMGL_DirectLight::bindAsCam(){
    glBindBufferRange(GL_SHADER_STORAGE_BUFFER, 5, SSB, 0, sizeof(float)*24);
}

void CMGL_DirectLight::calculateDepthBuffer(CMGL_GameObject* objects, int objectsCount, CMGL_Framebuffer& depthBuffer, CMGL_Program& depthProgram){
    depthBuffer.bind();
    glClear(GL_DEPTH_BUFFER_BIT);

    bindAsCam();
    
    CMGL_Renderer::renderGameObjects(objects, objectsCount, depthProgram);

    depthBuffer.unbind();
}


//overrides
void CMGL_DirectLight::updateLight(){
    Light::data[0] = direction.x;
    Light::data[1] = direction.y;
    Light::data[2] = direction.z;
    Light::data[3] = 0;

    Light::data[4] = color.x;
    Light::data[5] = color.y;
    Light::data[6] = color.z;
    Light::data[7] = color.w;

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSB);

    vec3 up = {0,1,0};
    if(direction.x == 0 && direction.z == 0){
        up.x = 1;
        up.y = 0;
    }

    float transMat[16] = {
        1,0,0,-Transform::Position.x,
        0,1,0,-Transform::Position.y,
        0,0,1,-Transform::Position.z,
        0,0,0,1
    };

    float scaleMat[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,shadowPrecision
    };

    free(LVM);
    LVM = m4_lookAt({0,0,0}, -direction, up);
    m4_transpose(LVM);
    m4_multiply(scaleMat, transMat);
    m4_multiply(LVM, scaleMat);

    m4_transpose(LVM);
    
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(float)*16, LVM);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, sizeof(float)*8, data);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void CMGL_DirectLight::updateTransform(){
    updateLight();
}