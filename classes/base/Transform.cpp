#include "Transform.hpp"

//constructors
Transform::Transform(){}

Transform::Transform(TransformData inputTransform){
    Position=inputTransform.position;
    Rotation=inputTransform.rotation;
    Scale=inputTransform.scale;
}


//destructors
Transform::~Transform(){}


//setters
void Transform::loadData(TransformData inputTransform){
    Position=inputTransform.position;
    Rotation=inputTransform.rotation;
    Scale=inputTransform.scale;
    updateTransform();
}

void Transform::setPosition(vec3 newPosition){
    Position=newPosition;
    updateTransform();
}

void Transform::setRotation(vec3 newRotation){
    Rotation=newRotation;
    updateTransform();
}

void Transform::setScale(vec3 newScale){
    Scale=newScale;
    updateTransform();
}

void Transform::move(vec3 movement){
    Position+=movement;
    updateTransform();
}

void Transform::rotate(vec3 rot){
    Rotation+=rot;
    updateTransform();
}

void Transform::scale(vec3 scaleToAdd){
    Scale+=scaleToAdd;
    updateTransform();
}


//getters
TransformData Transform::getTransformData(){
    return {Position, Rotation, Scale};
}

vec3 Transform::getPosition(){
    return Position;
}

vec3 Transform::getRotation(){
    return Rotation;
}
vec3 Transform::getScale(){
    return Scale;
}


//utility
void Transform::generateVectors(){
    float cosine = cos(Rotation.x);
    float sine = sin(Rotation.x);
    float rotX[16] = {
        1,0,0,0,
        0,cosine,sine,0,
        0,-sine,cosine,0,
        0,0,0,1
    };

    cosine = cos(Rotation.y);
    sine = sin(Rotation.y);
    float rotY[16] = {
        cosine,0,-sine,0,
        0,1,0,0,
        sine,0,cosine,0,
        0,0,0,1
    };

    cosine = cos(Rotation.z);
    sine = sin(Rotation.z);
    float rotZ[16] = {
        cosine,sine,0,0,
        -sine,cosine,0,0,
        0,0,1,0,
        0,0,0,1
    };

    m4_multiply(rotY, rotX);
    m4_multiply(rotZ, rotY);

    forwardVector = {rotZ[2], rotZ[6], rotZ[10]};
    rightVector = {rotZ[0], rotZ[4], rotZ[8]};
    upVector = {rotZ[1], rotZ[5], rotZ[9]};
}

void Transform::lookAt(vec3 destination, vec3 up){
    float* lookMat = m4_lookAt(Position, destination, up);

    forwardVector = {lookMat[2], lookMat[6], lookMat[10]};
    rightVector = {lookMat[0], lookMat[4], lookMat[8]};
    upVector = {lookMat[1], lookMat[5], lookMat[9]};

    free(lookMat);
}

void Transform::moveForward(float step){
    Position = Position + (forwardVector * step);
    updateTransform();
}

void Transform::moveRight(float step){
    Position = Position + (rightVector * step);
    updateTransform();
}

void Transform::moveUp(float step){
    Position = Position + (upVector * step);
    updateTransform();
}



//updaters (generally for overrides)
void Transform::updateTransform(){}