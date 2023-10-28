#include "B0.h"
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

using namespace std;
//using namespace vectors;


/*********************************************************************************/
//transform


//constructors
transform::transform(){
	position={0,0,0};
	rotation={0,0,0};
	scale={1,1,1};
}

transform::transform(vec3 inPosition, vec3 inRotation, vec3 inScale):
position(inPosition),rotation(inRotation),scale(inScale){}


//loaders
void transform::setPosition(vec3 inPos){
	position=inPos;
}

void transform::move(vec3 movement){
	position=position+movement;
}


void transform::setRotation(vec3 inRot){
	rotation=inRot;
}

void transform::rotate(vec3 inRotation){//if rotation problems occur look here
	rotation=rotation+inRotation;

	int result=(int)(rotation.x/PI2);
	rotation.x-=(result*PI2);
	
	result=(int)(rotation.y/PI2);
	rotation.y-=(result*PI2);

	result=(int)(rotation.z/PI2);
	rotation.z-=(result*PI2);
}

void transform::setScale(vec3 inSca){
	scale=inSca;
}

void transform::setTransform(vec3 inPos, vec3 inRot, vec3 inSca){
	position=inPos;
	rotation=inRot;
	scale=inSca;
}


/*********************************************************************************/
//texture


//constructors
texture::texture(){
	data=nullptr;
	glGenTextures(1,&id);
}

texture::texture(std::string filename){
	data=stbi_load(filename.c_str(),&iWidth,&iHeight,&iChannel,0);
	glGenTextures(1,&id);
}


//destructors
texture::~texture(){
	stbi_image_free(data);
	glDeleteTextures(1,&id);
}


//loaders
int texture::load(std::string filename,bool mipmap){
	stbi_image_free(data);
	data=stbi_load(filename.c_str(),&iWidth,&iHeight,&iChannel,0);

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
uint8_t* texture::getData(){
	return data;
}

int texture::width(){
	return iWidth;
}

int texture::height(){
	return iHeight;
}

int texture::spectrum(){
	return iChannel;
}


int texture::unload(){
	stbi_image_free(data);
	data=nullptr;
	return 0;
}


//checkers
bool texture::loaded(){
	return data!=nullptr;
}


//utility
int texture::bind(){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,id);
	return 0;
}

int texture::unbind(){
	glBindTexture(GL_TEXTURE_2D,0);
	return 0;
}


/*********************************************************************************/
//vertexData


//constructors
vertexData::vertexData():vCount(0),vertices(nullptr){}

vertexData::vertexData(int inVCount):vCount(inVCount){
	vertices=new vertex[vCount]{0};
}

vertexData::vertexData(int inVCount, vertex* iVertices):vCount(inVCount){
	vertices=new vertex[vCount]{0};
	memcpy(vertices,iVertices,sizeof(vertex)*vCount);
}


//destructors
vertexData::~vertexData(){
	delete[] vertices;
}


//loaders
int vertexData::setVertexCount(int inVCount){
	vCount=inVCount;
	delete[] vertices;
	vertices=nullptr;
	return 0;
}

int vertexData::setColor(vec4 inCol){
	for(int i=0;i<vCount;i++){
		vertices[i].col=inCol;
	}
	return 0;
}

int vertexData::loadPos(vec3* inPos){
	//copy them to vertices[i].pos
	for(int i=0;i<vCount;i++){
		vertices[i].pos.x=inPos[i].x;
		vertices[i].pos.y=inPos[i].y;
		vertices[i].pos.z=inPos[i].z;
	}
	return 0;
}

int vertexData::loadNor(vec3* inNor){
	//copy them to vertices[i].nor
	for(int i=0;i<vCount;i++){
		vertices[i].nor.x=inNor[i].x;
		vertices[i].nor.y=inNor[i].y;
		vertices[i].nor.z=inNor[i].z;
	}
	return 0;
}

int vertexData::loadCol(vec4* inCol){
	//copy them to vertices[i].col
	for(int i=0;i<vCount;i++){
		vertices[i].col.x=inCol[i].x;
		vertices[i].col.y=inCol[i].y;
		vertices[i].col.z=inCol[i].z;
		vertices[i].col.w=inCol[i].w;
	}
	return 0;
}

int vertexData::loadTex(vec2* inTex){
	//copy them to vertices[i].tex
	for(int i=0;i<vCount;i++){
		vertices[i].tex.x=inTex[i].x;
		vertices[i].tex.y=inTex[i].y;
	}
	return 0;
}

int vertexData::loadAll(int inVCount, vertex* iVertices){
	vCount=inVCount;
	delete[] vertices;
	vertices=new vertex[vCount]{0};
	memcpy(vertices,iVertices,sizeof(vertex)*vCount);
	return 0;
}

	
//extractors
int vertexData::getVCount(){
	return vCount;
}


//utility //WIP
int vertexData::reset(){
	vCount=0;
	delete[] vertices;
	vertices=nullptr;
	return 0;
}

vertexData* vertexData::getPointer(){
	return this;
}


/*********************************************************************************/
//light


//constructors
light::light(const char* name):
color({1,1,1,1}){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
}
light::light(vec3 iPos, vec4 iCol, const char* name):
transform(iPos,{0,0,0}),color(iCol){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
}


//utility
int light::update(){
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

int light::move(vec3 movement){
	position=position+movement;
	update();
	return 0;
}


//loaders
int light::loadData(vec3 iPos, vec4 iCol){
	position=iPos;
	color=iCol;
	update();
	return 0;
}

int light::Color(vec4 iColor){
	color=iColor;
	update();
	return 0;
}

int light::Position(vec3 iPos){
	position=iPos;
	update();
	return 0;
}


//extractors
float* light::getData(){
	float* temp=new float[8];
	memcpy(temp,data,sizeof(float)*8);
	return temp;
}


/*********************************************************************************/