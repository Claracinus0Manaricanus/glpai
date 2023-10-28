#include "B0.h"
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

using namespace std;
//using namespace vectors;


/*********************************************************************************/
//transform


//constructors
Transform::Transform(const char* name){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
	position={0,0,0};
	rotation={0,0,0};
	scale={1,1,1};
}

Transform::Transform(vec3 inPosition, vec3 inRotation, vec3 inScale, const char* name):
position(inPosition),rotation(inRotation),scale(inScale){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
}


//destructor
Transform::~Transform(){
	free(NAME);
}


//loaders
void Transform::setPosition(vec3 inPos){
	position=inPos;
}

void Transform::move(vec3 movement){
	position=position+movement;
}


void Transform::setRotation(vec3 inRot){
	rotation=inRot;
}

void Transform::rotate(vec3 inRotation){//if rotation problems occur look here
	rotation=rotation+inRotation;

	int result=(int)(rotation.x/PI2);
	rotation.x-=(result*PI2);
	
	result=(int)(rotation.y/PI2);
	rotation.y-=(result*PI2);

	result=(int)(rotation.z/PI2);
	rotation.z-=(result*PI2);
}

void Transform::setScale(vec3 inSca){
	scale=inSca;
}

void Transform::setTransform(vec3 inPos, vec3 inRot, vec3 inSca){
	position=inPos;
	rotation=inRot;
	scale=inSca;
}


/*********************************************************************************/
//Texture


//constructors
Texture::Texture(){
	data=nullptr;
	glGenTextures(1,&id);
}

Texture::Texture(const char* filename){
	data=stbi_load(filename,&iWidth,&iHeight,&iChannel,0);
	glGenTextures(1,&id);
}


//destructors
Texture::~Texture(){
	stbi_image_free(data);
	glDeleteTextures(1,&id);
}


//loaders
int Texture::load(const char* filename,bool mipmap){
	stbi_image_free(data);
	data=stbi_load(filename,&iWidth,&iHeight,&iChannel,0);

	if(iChannel<3)
		return -1;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,id);

	if(iChannel==3)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,iWidth,iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
	if(iChannel==4)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,iWidth,iHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,data);

	if(mipmap)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	else
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if(mipmap)
		glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D,0);

	return 0;
}


//extractors
uint8_t* Texture::getData(){
	return data;
}

int Texture::width(){
	return iWidth;
}

int Texture::height(){
	return iHeight;
}

int Texture::spectrum(){
	return iChannel;
}


int Texture::unload(){
	stbi_image_free(data);
	data=nullptr;
	return 0;
}


//checkers
bool Texture::loaded(){
	return data!=nullptr;
}


//utility
int Texture::bind(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,id);
	return 0;
}

int Texture::unbind(){
	glBindTexture(GL_TEXTURE_2D,0);
	return 0;
}


/*********************************************************************************/
//vertexData


//constructors
VertexData::VertexData():vCount(0),vertices(nullptr){}

VertexData::VertexData(int inVCount, vertex* iVertices):vCount(inVCount){
	vertices=new vertex[vCount]{0};
	memcpy(vertices,iVertices,sizeof(vertex)*vCount);
}


//destructors
VertexData::~VertexData(){
	delete[] vertices;
}


//loaders
int VertexData::setVertexCount(int inVCount){
	vCount=inVCount;
	delete[] vertices;
	vertices=nullptr;
	return 0;
}

int VertexData::setColor(vec4 inCol){
	for(int i=0;i<vCount;i++){
		vertices[i].col=inCol;
	}
	return 0;
}

int VertexData::loadPos(vec3* inPos){
	//copy them to vertices[i].pos
	for(int i=0;i<vCount;i++){
		vertices[i].pos.x=inPos[i].x;
		vertices[i].pos.y=inPos[i].y;
		vertices[i].pos.z=inPos[i].z;
	}
	return 0;
}

int VertexData::loadNor(vec3* inNor){
	//copy them to vertices[i].nor
	for(int i=0;i<vCount;i++){
		vertices[i].nor.x=inNor[i].x;
		vertices[i].nor.y=inNor[i].y;
		vertices[i].nor.z=inNor[i].z;
	}
	return 0;
}

int VertexData::loadCol(vec4* inCol){
	//copy them to vertices[i].col
	for(int i=0;i<vCount;i++){
		vertices[i].col.x=inCol[i].x;
		vertices[i].col.y=inCol[i].y;
		vertices[i].col.z=inCol[i].z;
		vertices[i].col.w=inCol[i].w;
	}
	return 0;
}

int VertexData::loadTex(vec2* inTex){
	//copy them to vertices[i].tex
	for(int i=0;i<vCount;i++){
		vertices[i].tex.x=inTex[i].x;
		vertices[i].tex.y=inTex[i].y;
	}
	return 0;
}

int VertexData::loadAll(int inVCount, vertex* iVertices){
	vCount=inVCount;
	delete[] vertices;
	vertices=new vertex[vCount]{0};
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
	delete[] vertices;
	vertices=nullptr;
	return 0;
}

VertexData* VertexData::getPointer(){
	return this;
}


/*********************************************************************************/
//Light


//constructors
Light::Light(const char* name):
color({1,1,1,1}){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
}
Light::Light(vec3 iPos, vec4 iCol, const char* name):
Transform(iPos,{0,0,0}),color(iCol){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
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
	position=position+movement;
	update();
	return 0;
}


//loaders
int Light::loadData(vec3 iPos, vec4 iCol){
	position=iPos;
	color=iCol;
	update();
	return 0;
}

int Light::Color(vec4 iColor){
	color=iColor;
	update();
	return 0;
}

int Light::Position(vec3 iPos){
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