#include "VertexData.h"

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