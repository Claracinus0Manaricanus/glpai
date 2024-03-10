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

void Camera::enableLookAt(vec3 lookVec){
    isLookingAt = true;
    lookVector = lookVec;
}

void Camera::disableLookAt(){
    isLookingAt = false;
}



//getters
int Camera::getFov(){
    return fov;
}

int Camera::getType(){
    return type;
}

bool Camera::getLookingAt(){
    return isLookingAt;
}


//utility
float* Camera::generateCVM(){
    
    float translate[16]={
        1, 0, 0, -Transform::Position.x,
        0, 1, 0, -Transform::Position.y,
        0, 0, 1, -Transform::Position.z,
        0, 0, 0, 1
    };

    if(isLookingAt){
        Transform::lookAt(lookVector, {0,1,0});
    }else{
        generateVectors();
    }

    float rotMat[16] = {//transpose of what would be cause camera
        rightVector.x, rightVector.y, rightVector.z, 0,
        upVector.x, upVector.y, upVector.z, 0,
        forwardVector.x, forwardVector.y, forwardVector.z, 0,
        0, 0, 0, 1
    };

    float* ret = m4_multiplyNew(rotMat, translate);

    if(type == 1){//perspective
        float projection[16]{
            1/tan((3.14159265f/180.0f)*fov/2.0f),0,0,0,
            0,aspectRatio/tan((3.14159265f/180.0f)*fov/2.0f),0,0,
            0,0,1,-0.01f,
            0,0,1,0
        };

        float* temp = ret;
        ret = m4_multiplyNew(projection, ret);
        free(temp);
        return ret;
    }

    return ret;
}

//Transform overrides
void Camera::generateVectors(){
    float cosine = cos(Rotation.x);
    float sine = sin(Rotation.x);
    float rotX[16] = {
        1,0,0,0,
        0,cosine,-sine,0,
        0,sine,cosine,0,
        0,0,0,1
    };

    cosine = cos(Rotation.y);
    sine = sin(Rotation.y);
    float rotY[16] = {
        cosine,0,sine,0,
        0,1,0,0,
        -sine,0,cosine,0,
        0,0,0,1
    };

    cosine = cos(Rotation.z);
    sine = sin(Rotation.z);
    float rotZ[16] = {
        cosine,-sine,0,0,
        sine,cosine,0,0,
        0,0,1,0,
        0,0,0,1
    };

    m4_multiply(rotY, rotX);
    m4_multiply(rotZ, rotY);

    forwardVector = {rotZ[2], rotZ[6], rotZ[10]};
    rightVector = {rotZ[0], rotZ[4], rotZ[8]};
    upVector = {rotZ[1], rotZ[5], rotZ[9]};
}