#include "B0.h"
#include "cmMath/matrix4.h"
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

using namespace std;
//using namespace vectors;


/*********************************************************************************/
//transform


//constructors
Transform::Transform(const char* name, vec3 inPos, vec3 inRot, vec3 inSca):
position(inPos),rotation(inRot),scale(inSca){
	NAME=(char*)calloc(strlen(name)+1,sizeof(char));
	memcpy(NAME,name,strlen(name));
	calculateMatrix();
}


//destructor
Transform::~Transform(){
	free(NAME);
	free(OVM);
}


//loaders
void Transform::setPosition(vec3 inPos){
	position=inPos;
	calculateMatrix();
}

void Transform::move(vec3 movement){
	position+=movement;
	calculateMatrix();
}


void Transform::setRotation(vec3 inRot){
	rotation=inRot;
	calculateMatrix();
}

void Transform::rotate(vec3 inRot){//if rotation problems occur look here
	rotation+=inRot;

	int result=(int)(rotation.x/PI2);
	rotation.x-=(result*PI2);
	
	result=(int)(rotation.y/PI2);
	rotation.y-=(result*PI2);

	result=(int)(rotation.z/PI2);
	rotation.z-=(result*PI2);
	
	calculateMatrix();
}

void Transform::setScale(vec3 inSca){
	scale=inSca;
}

void Transform::setTransform(vec3 inPos, vec3 inRot, vec3 inSca){
	position=inPos;
	rotation=inRot;
	scale=inSca;
	calculateMatrix();
}


//calculators
void Transform::calculateMatrix(){
	//setting up matrices to multiply
	float tmpC=cos(rotation.x),tmpS=sin(rotation.x);//temporary cos and sin
	float rotXM4[16]={
		1,   0,    0,0,
		0,tmpC, tmpS,0,
		0,-tmpS,tmpC,0,
		0,   0,    0,1
	};
	tmpC=cos(rotation.y);tmpS=sin(rotation.y);
	float rotYM4[16]={
		tmpC,0,-tmpS,0,
		0,   1,    0,0,
		tmpS,0, tmpC,0,
		0,   0,    0,1
	};
	tmpC=cos(rotation.z);tmpS=sin(rotation.z);
	float rotZM4[16]={
		tmpC, tmpS,0,0,
		-tmpS,tmpC,0,0,
		0,       0,1,0,
		0,       0,0,1
	};
	float transM4[16]={
		1,0,0,position.x,
		0,1,0,position.y,
		0,0,1,position.z,
		0,0,0,1
	};
	//pre-final multiplication
	float* temp1=m4_multiply(rotYM4,rotXM4);
	float* temp2=m4_multiply(rotZM4,temp1);
	//final multiplication
	free(OVM);
	OVM=m4_multiply(transM4,temp2);
	//cleanup
	free(temp1);
	free(temp2);
}


/*********************************************************************************/
//Texture


//constructors
Texture::Texture(){
	glGenTextures(1,&ID);
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	unbind();
	loadDefault();
}

Texture::Texture(const char* filename){
	glGenTextures(1,&ID);
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	unbind();
	load(filename,false);
}


//destructors
Texture::~Texture(){
	glDeleteTextures(1,&ID);
}


//loaders
int Texture::load(const char* filename,bool mipmap){
	data=stbi_load(filename,&iWidth,&iHeight,&iChannel,0);

	if(iChannel<3)
		return -1;

	bind();

	if(iChannel==3)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,iWidth,iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
	if(iChannel==4)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,iWidth,iHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,data);

	if(mipmap)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	else
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if(mipmap)
		glGenerateMipmap(GL_TEXTURE_2D);

	unbind();
	stbi_image_free(data);
	return 0;
}

int Texture::loadDefault(){
	bind();
	data=(uint8_t*)malloc(32);
	data[0]=255;data[1]=255;data[2]=255;data[3]=255;
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	unbind();
	free(data);
	return 0;
}


//extractors
int Texture::width(){
	return iWidth;
}

int Texture::height(){
	return iHeight;
}

int Texture::spectrum(){
	return iChannel;
}


//utility
int Texture::bind(){
	glBindTexture(GL_TEXTURE_2D,ID);
	return 0;
}

int Texture::unbind(){
	glBindTexture(GL_TEXTURE_2D,0);
	return 0;
}


/*********************************************************************************/
//vertexData


//constructors
VertexData::VertexData(){}

VertexData::VertexData(int inVCount, vertex* iVertices){
	loadAll(inVCount,iVertices);
}


//destructors
VertexData::~VertexData(){
	free(vertices);
}


//loaders  functions need checking
int VertexData::setColor(vec4 inCol){
	for(int i=0;i<vCount;i++){
		vertices[i].col=inCol;
	}
	return 0;
}

int VertexData::loadPos(vec3* inPos){
	//copy them to vertices[i].pos
	for(int i=0;i<vCount;i++){
		vertices[i].pos=inPos[i];
	}
	return 0;
}

int VertexData::loadNor(vec3* inNor){
	//copy them to vertices[i].nor
	for(int i=0;i<vCount;i++){
		vertices[i].nor=inNor[i];
	}
	return 0;
}

int VertexData::loadCol(vec4* inCol){
	//copy them to vertices[i].col
	for(int i=0;i<vCount;i++){
		vertices[i].col=inCol[i];
	}
	return 0;
}

int VertexData::loadTex(vec2* inTex){
	//copy them to vertices[i].tex
	for(int i=0;i<vCount;i++){
		vertices[i].tex=inTex[i];
	}
	return 0;
}

int VertexData::loadAll(int inVCount, vertex* iVertices){
	vCount=inVCount;
	vertices=(vertex*)realloc(vertices,sizeof(vertex)*inVCount);
	memcpy(vertices,iVertices,sizeof(vertex)*vCount);
	return 0;
}

	
//extractors
int VertexData::getVCount(){
	return vCount;
}


//utility //WIP
int VertexData::reset(){
	vCount=0;
	free(vertices);
	vertices=nullptr;
	return 0;
}

VertexData* VertexData::getPointer(){
	return this;
}


/*********************************************************************************/
//Light


//constructors
Light::Light(int iType, vec3 iPos, vec4 iCol, const char* name){
	NAME=(char*)calloc(strlen(name)+1,sizeof(char));
	memcpy(NAME,name,strlen(name));
	loadData(iType,iPos,iCol);
}


//destructors
Light::~Light(){
	free(NAME);
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


/*********************************************************************************/
//CubeMap


//constructors
CubeMap::CubeMap(const char* sides[6]){
	//texture generation opengl
	glGenTextures(1,&ID);
	bindCM();
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	unbindCM();
	if(sides!=NULL)
		loadAllSides(sides);
}


//destructor
CubeMap::~CubeMap(){
	glDeleteTextures(1,&ID);
}


//loaders
int CubeMap::loadAllSides(const char* sides[6]){
	bindCM();
	for(int i=0;i<6;i++){
		if(sides[i]!=NULL){
			iData=stbi_load(sides[i],&iWidth,&iHeight,&chan,3);
			if(iData!=NULL){
				glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,GL_RGB,iWidth,iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,iData);
				stbi_image_free(iData);
			}
		}
	}
	unbindCM();
	return 0;
}


//utility
int CubeMap::bindCM(){
	glBindTexture(GL_TEXTURE_CUBE_MAP,ID);
	return 0;
}

int CubeMap::unbindCM(){
	glBindTexture(GL_TEXTURE_CUBE_MAP,0);
	return 0;
}


/*********************************************************************************/