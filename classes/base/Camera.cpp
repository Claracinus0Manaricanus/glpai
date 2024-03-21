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

void Camera::updateOVM(){
    for(int  i = 0; i < 3; i++){
        OVM[i] = rightVector[i];
        OVM[i+4] = upVector[i];
        OVM[i+8] = forwardVector[i];
        OVM[(i*4)+3] = 0;
        OVM[i+12] = 0;
    }
    OVM[15] = 1;

    float transMat[16] = {
        1, 0, 0, -Transform::Position.x,
        0, 1, 0, -Transform::Position.y,
        0, 0, 1, -Transform::Position.z,
        0, 0, 0,  1
    };
    
    m4_multiply(OVM, transMat);

    if(type == 1){//perspective
        float projection[16] = {
            1/tan((3.14159265f/180.0f)*fov/2.0f),0,0,0,
            0,aspectRatio/tan((3.14159265f/180.0f)*fov/2.0f),0,0,
            0,0,1,-0.01f,
            0,0,1,0
        };
        m4_multiply(projection, OVM);
        m4_copy(OVM, projection);
    }else{
        float projection[16] = {
            1,0,0,0,
            0,aspectRatio,0,0,
            0,0,1,0,
            0,0,0,fov
        };
        m4_multiply(projection, OVM);
        m4_copy(OVM, projection);
    }
    

    m4_transpose(OVM);
}