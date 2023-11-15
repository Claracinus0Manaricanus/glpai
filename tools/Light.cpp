#include "Light.h"

//constructors
Light::Light(int iType, vec3 iPos, vec4 iCol, const char* name){
	NAME=(char*)calloc(strlen(name)+1,sizeof(char));
	memcpy(NAME,name,strlen(name));
	loadData(iType,iPos,iCol);
}


//destructors
Light::~Light(){
	free(NAME);
	free(LVM);
}


//utility
int Light::update(){
	data[0]=position.x;
	data[1]=position.y;
	data[2]=position.z;
	data[3]=type;
	data[4]=color.x;
	data[5]=color.y;
	data[6]=color.z;
	data[7]=color.w;
	return 0;
}

int Light::move(vec3 movement){
	position+=movement;
	update();
	return 0;
}


int Light::calculateMatrix(){


	
	return 0;
}


//loaders
int Light::loadData(int iType, vec3 iPos, vec4 iCol){
	position=iPos;
	color=iCol;
	type=iType;
	update();
	return 0;
}

int Light::setColor(vec4 iColor){
	color=iColor;
	update();
	return 0;
}

int Light::setPosition(vec3 iPos){
	position=iPos;
	update();
	return 0;
}


//extractors
float* Light::getData(){
	float* temp=new float[8];
	memcpy(temp,data,sizeof(float)*8);
	return temp;
}