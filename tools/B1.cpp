#include "B1.h"
#include <math.h>
#include <GL/glew.h>


/*********************************************************************************/
//Camera


Camera::Camera(float Ifov):fov(Ifov){}

void Camera::moveForward(float forward){
	move({sin(rotation.y)*forward,0,cos(rotation.y)*forward});
}

void Camera::moveRight(float right){
	move({sin(rotation.y+(PI/2))*right,0,cos(rotation.y+(PI/2))*right});
}

void Camera::moveUp(float up){
	move({0,up,0});
}


/*********************************************************************************/
//GameObject

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
Transform(inPos,inRot,inSca,name),VertexData(inVCount,iVertices){
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
	mainTex.unload();
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
	return (bTex&&mainTex.loaded());
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
	float* moddedPos=new float[vCount*3]{0};


	//position
	for(int i=0;i<vCount;i++){
		//scale
		moddedPos[i*3]=vertices[i].pos.x*scale.x;//x
		moddedPos[i*3+1]=vertices[i].pos.y*scale.y;//y
		moddedPos[i*3+2]=vertices[i].pos.z*scale.z;//z
	}


	//load modified data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,posBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*3,moddedPos,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
	glEnableVertexAttribArray(0);
	delete[] moddedPos;


	//normal
	//to store modified data
	float* moddedNor=new float[vCount*3]{0};

	//update according to Transform data
	//rotation (sequence: x->y->z)  needs optimization and quaternions
	for(int i=0;i<vCount;i++){
		//scaling
		moddedPos[i*3]=vertices[i].nor.x*scale.y*scale.z;//x
		moddedPos[i*3+1]=vertices[i].nor.y*scale.x*scale.z;//y
		moddedPos[i*3+2]=vertices[i].nor.z*scale.x*scale.y;//z
	}

	//load modded data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,norBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*3,moddedNor,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
	glEnableVertexAttribArray(1);

	delete[] moddedNor;


	//color
	float* vertexCol=new float[vCount*sizeof(float)*4];
	for(int i=0;i<vCount;i++){
		vertexCol[i*4]=vertices[i].col.x;//x
		vertexCol[i*4+1]=vertices[i].col.y;//y
		vertexCol[i*4+2]=vertices[i].col.z;//z
		vertexCol[i*4+3]=vertices[i].col.w;//w
	}
	//data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,colBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*4,vertexCol,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,sizeof(float)*4,(void*)0);
	glEnableVertexAttribArray(2);


	//textureCoordinates
	float* vertexTex=new float[vCount*sizeof(float)*2];
	for(int i=0;i<vCount;i++){
		vertexTex[i*2]=vertices[i].tex.x;//x
		vertexTex[i*2+1]=vertices[i].tex.y;//y
	}
	//data to buffer
	glBindBuffer(GL_ARRAY_BUFFER,texBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vCount*2,vertexTex,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(3);
	
	unbind();
	return 0;
}


/*********************************************************************************/
//UI_Element


//constructor
UI_Element::UI_Element(const char* name){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
	glGenVertexArrays(1,&vArr);
	glGenBuffers(1,&posBuff);
	glGenBuffers(1,&texBuff);
	updateArrays();
}

UI_Element::UI_Element(vec2 iPos, vec2 iScale, const char* name):
pos(iPos),scale(iScale){
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
	glGenVertexArrays(1,&vArr);
	glGenBuffers(1,&posBuff);
	glGenBuffers(1,&texBuff);
	updateArrays();
}


//destructor
UI_Element::~UI_Element(){
	delete[] vPos;
	delete[] vTex;
	free(NAME);
	glDeleteBuffers(1,&posBuff);
	glDeleteBuffers(1,&texBuff);
	glDeleteVertexArrays(1,&vArr);
}


//loaders
int UI_Element::changePos(vec2 iPos){
	pos=iPos;
	updateArrays();
	return 0;
}

int UI_Element::changeScale(vec2 iScale){
	scale=iScale;
	updateArrays();
	return 0;
}

int UI_Element::loadTexture(const char* filename, bool mipmap){
	return mainTex.load(filename,mipmap);
}

int UI_Element::unloadTexture(){
	return mainTex.unload();
}

int UI_Element::setActive(bool state){
	Active=state;
	return 0;
}


//extractors
int UI_Element::getVCount(){
	return 6;
}

bool UI_Element::isActive(){
	return Active;
}


//utility
int UI_Element::bind(){
	glBindVertexArray(vArr);
	mainTex.bind();
	return 0;
}

int UI_Element::unbind(){
	glBindVertexArray(0);
	mainTex.unbind();
	return 0;
}

int UI_Element::updateArrays(){
	delete[] vPos;
	vPos=new float[12]{
		pos.x+scale.x,pos.y+scale.y,
		pos.x+scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y+scale.y,
		pos.x+scale.x,pos.y+scale.y
	};
	updateBuffers();
	return 0;
}

int UI_Element::updateBuffers(){
	glBindVertexArray(vArr);
	glBindBuffer(GL_ARRAY_BUFFER,posBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*12,vPos,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,texBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*12,vTex,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(3);
	return 0;
}


/*********************************************************************************/