#include "Camera.hpp"

//cosntructors
Camera::Camera(){}

Camera::Camera(int iFov, int iType, float inAspectRatio){
    fov=iFov;
    type=iType;
    aspectRatio=inAspectRatio;
}


//setters
void Camera::setFov(int iFov){
    fov=iFov;
}

void Camera::setType(int iType){
    type=iType;
}

void Camera::setAspectRatio(float inAspectRatio){
    aspectRatio=inAspectRatio;
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
        1, 0, 0, -Transform::Position.x,
        0, 1, 0, -Transform::Position.y,
        0, 0, 1, -Transform::Position.z,
        0, 0, 0, 1
    };

    float cosine = cos(Transform::Rotation.x);
    float sine = sin(Transform::Rotation.x);
    float rotX[16] = {
        1, 0, 0, 0,
        0, cosine, sine, 0,
        0, -sine,  cosine, 0,
        0, 0, 0, 1
    };

    cosine = cos(Transform::Rotation.y);
    sine = sin(Transform::Rotation.y);
    float rotY[16] = {
        cosine, 0, -sine, 0,
        0, 1, 0, 0,
        sine, 0,  cosine, 0,
        0, 0, 0, 1
    };

    cosine = cos(Transform::Rotation.z);
    sine = sin(Transform::Rotation.z);
    float rotZ[16] = {
         cosine,  sine, 0, 0,
        -sine,  cosine, 0, 0,
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
            1/tan((3.14159265f/180.0f)*fov/2.0f),0,0,0,
            0,aspectRatio/tan((3.14159265f/180.0f)*fov/2.0f),0,0,
            0,0,1,-0.01f,
            0,0,1,0
        };

        tmp2M4 = m4_multiply(projection, tmp1M4);
        free(tmp1M4);

        return tmp2M4;
    }

    return tmp1M4;
}

void Camera::moveForward(float step, float offset){
    Transform::move({sin(Transform::Rotation.y+offset)*step, 0.0f, cos(Transform::Rotation.y+offset)*step});
}