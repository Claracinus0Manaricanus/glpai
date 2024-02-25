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
    

    
    return NULL;
}