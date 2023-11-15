#include "GameObject.h"

//initializers
void GameObject::initBuffers(){
	glGenVertexArrays(1,&vArr);
	glBindVertexArray(vArr);
	glGenBuffers(1,&posBuff);
	glGenBuffers(1,&norBuff);
	glGenBuffers(1,&colBuff);
	glGenBuffers(1,&texBuff);
}


//constructors
GameObject::GameObject(const char* name):
Transform(name){
	initBuffers();
}

GameObject::GameObject(vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* name):
Transform(name,inPos,inRot,inSca),VertexData(inVCount,iVertices){
	initBuffers();
	update();
}


//destructors
GameObject::~GameObject(){
	glDeleteBuffers(1,&posBuff);
	glDeleteBuffers(1,&norBuff);
	glDeleteBuffers(1,&colBuff);
	glDeleteBuffers(1,&texBuff);
	glDeleteVertexArrays(1,&vArr);
}


//loaders
int GameObject::setColor(vec4 inCol){//needed for update()
	VertexData::setColor(inCol);
	update();
	return 0;
}

int GameObject::loadData(vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices){
	setTransform(inPos,inRot,inSca);
	loadAll(inVCount,iVertices);
	update();
	return 0;
}

int GameObject::loadData(vec3 inPos, vec3 inRot, int inVCount, vertex* iVertices){
	setTransform(inPos,inRot,scale);
	loadAll(inVCount,iVertices);
	update();
	return 0;
}

int GameObject::loadData(int inVCount, vertex* iVertices){
	loadAll(inVCount,iVertices);
	update();
	return 0;
}

int GameObject::loadTexture(const char* filename, bool mipmap){
	mainTex.load(filename,mipmap);
	bTex=true;
	return 0;
}

int GameObject::unloadTexture(){
	mainTex.loadDefault();
	bTex=false;
	return 0;
}


//selectors
int GameObject::useColor(bool newState){
	bTex=!newState;
	return 0;
}


//state identifiers
bool GameObject::usingTexture(){
	return bTex;
}


//utility
int GameObject::bind(){
	glBindVertexArray(vArr);
	mainTex.bind();
	return 0;
}

int GameObject::unbind(){
	glBindVertexArray(0);
	mainTex.unbind();
	return 0;
}

int GameObject::update(){
	//vertexArray
	glBindVertexArray(vArr);


	//position
	//to store modified data
	float* tmpData=(float*)malloc(sizeof(float)*3*vCount);
	for(int i=0;i<vCount;i++){
		//scale
		tmpData[i*3]=vertices[i].pos.x*scale.x;//x
		tmpData[i*3+1]=vertices[i].pos.y*scale.y;//y
		tmpData[i*3+2]=vertices[i].pos.z*scale.z;//z
	}


	//load modified data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,posBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*3,tmpData,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
	glEnableVertexAttribArray(0);


	//normal
	//to store modified data
	tmpData=(float*)realloc(tmpData,sizeof(float)*3*vCount);
	//update according to Transform data
	for(int i=0;i<vCount;i++){
		//scaling
		tmpData[i*3]=vertices[i].nor.x*scale.y*scale.z;//x
		tmpData[i*3+1]=vertices[i].nor.y*scale.x*scale.z;//y
		tmpData[i*3+2]=vertices[i].nor.z*scale.x*scale.y;//z
	}

	//load modded data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,norBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*3,tmpData,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
	glEnableVertexAttribArray(1);


	//color
	tmpData=(float*)realloc(tmpData,sizeof(float)*4*vCount);
	for(int i=0;i<vCount;i++){
		tmpData[i*4]=vertices[i].col.x;//x
		tmpData[i*4+1]=vertices[i].col.y;//y
		tmpData[i*4+2]=vertices[i].col.z;//z
		tmpData[i*4+3]=vertices[i].col.w;//w
	}
	//data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,colBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*4,tmpData,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,sizeof(float)*4,(void*)0);
	glEnableVertexAttribArray(2);


	//textureCoordinates
	tmpData=(float*)realloc(tmpData,sizeof(float)*2*vCount);
	for(int i=0;i<vCount;i++){
		tmpData[i*2]=vertices[i].tex.x;//x
		tmpData[i*2+1]=vertices[i].tex.y;//y
	}
	//data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,texBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*2,tmpData,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(3);
	
	//cleanup
	free(tmpData);
	unbind();
	return 0;
}