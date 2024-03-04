#include "Light.hpp"

//constructors
Light::Light(){
    updateData();
}

Light::Light(LightData lDat):
Transform(lDat.trData){
    type = lDat.type;
    color = lDat.color;
    updateData();
}


//destructors
Light::~Light(){
    free(data);
}


//setters
void Light::setType(int iType){
    type=iType;
}


//getters
int Light::getType(){
    return type;
}


//utility
float* Light::getData(){
    return data;
}


void Light::updateData(){
    if(data == NULL) data = (float*)malloc(sizeof(float)*8);

    data[0] = Transform::Position.x;
    data[1] = Transform::Position.y;
    data[2] = Transform::Position.z;
    data[3] = 0;
    data[4] = color.x;
    data[5] = color.y;
    data[6] = color.z;
    data[7] = color.w;
}


//Transform overrides
void Light::updateTransform(){
    updateData();
}