#include "Light.hpp"

//constructors
Light::Light(){}


//destructors
Light::~Light(){
    free(data);
}


//setters
void Light::setColor(vec4 inColor){
    color = inColor;
    updateLight();
}


//getters
int Light::getType(){
    return type;
}

vec4 Light::getColor(){
    return color;
}

int Light::getDataLength(){
    return dataLength;
}


//utility
float* Light::getData(){
    return data;
}


//overridables
void Light::updateLight(){}