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
    direction = data.direction;

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

    float scaleMat[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,50
    };

    free(LVM);
    LVM = m4_lookAt({0,0,0}, -direction, up);
    m4_multiply(LVM, scaleMat);

    
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(float)*16, LVM);
    glBufferSubData(GL_SHADER_STORAGE_BUFFER, sizeof(float)*16, sizeof(float)*8, data);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}