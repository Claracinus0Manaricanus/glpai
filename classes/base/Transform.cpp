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
}

void Transform::setPosition(vec3 newPosition){
    Position=newPosition;
}

void Transform::setRotation(vec3 newRotation){
    Rotation=newRotation;
}

void Transform::setScale(vec3 newScale){
    Scale=newScale;
}

void Transform::move(vec3 movement){
    Position+=movement;
}

void Transform::rotate(vec3 rot){
    Rotation+=rot;
}

void Transform::scale(vec3 scaleToAdd){
    Scale+=scaleToAdd;
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