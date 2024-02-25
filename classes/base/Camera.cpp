#include "Camera.hpp"

//cosntructors
Camera::Camera(){}

Camera::Camera(int iFov, int iType){
    fov=iFov;
    type=iType;
}


//setters
void Camera::setFov(int iFov){
    fov=iFov;
}

void Camera::setType(int iType){
    type=iType;
}


//getters
int Camera::getFov(){
    return fov;
}

int Camera::getType(){
    return type;
}


//utility
float* Camera::generateCVM(){
    
    float translate[16]={
        1, 0, 0, Position.x,
        0, 1, 0, Position.y,
        0, 0, 1, Position.z,
        0, 0, 0, 1
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

    float* tmp1M4 = m4_multiply(rotY, translate);
    float* tmp2M4 = m4_multiply(rotX, tmp1M4);
    free(tmp1M4);
    tmp1M4 = m4_multiply(rotZ, tmp2M4);
    free(tmp2M4);

    if(type == 1){//perspective
        float projection[16]{
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
        };

        tmp2M4 = m4_multiply(projection, tmp1M4);
        free(tmp1M4);

        return tmp2M4;
    }

    return tmp1M4;
}