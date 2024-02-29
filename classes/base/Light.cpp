#include "Light.hpp"

//constructors
Light::Light(){

}

Light::Light(LightData lDat):
Transform(lDat.trData){
    type = lDat.type;
    color = lDat.color;
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
float* Light::generateData(){
    if(data == NULL) data = (float*)malloc(sizeof(float)*8);
    
    data[0] = Transform::Position.x;
    data[1] = Transform::Position.y;
    data[2] = Transform::Position.z;
    data[3] = 0;
    data[4] = color.x;
    data[5] = color.y;
    data[6] = color.z;
    data[7] = color.w;

    return data;
}