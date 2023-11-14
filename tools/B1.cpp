#include "B1.h"
#include <math.h>
#include <GL/glew.h>
#include "cmMath/matrix4.h"
#include "cmMath/vectors.h"


/*********************************************************************************/
//Camera


//constructors
Camera::Camera(float Ifov, float inAspectRatio):
fov(Ifov*PI/180.0f),aspectRatio(inAspectRatio){}


//control
void Camera::moveForward(float forward){
	move({sin(rotation.y)*forward,0,cos(rotation.y)*forward});
}

void Camera::moveRight(float right){
	move({sin(rotation.y+(PI/2))*right,0,cos(rotation.y+(PI/2))*right});
}

void Camera::moveUp(float up){
	move({0,up,0});
}

void Camera::setAspectRatio(float inAspectRatio){
	aspectRatio=inAspectRatio;
}


//overrides
void Camera::calculateRotation(){
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
		tmpC,-tmpS,0,0,
		tmpS, tmpC,0,0,
		0,       0,1,0,
		0,       0,0,1
	};

	float* temp1=m4_multiply(rotXM4,rotYM4);
	free(rotM4);
	rotM4=m4_multiply(rotZM4,temp1);
	//cleanup
	free(temp1);
}

void Camera::calculateMatrix(){
	//setting up matrices to multiply
	if(LookingAt==NULL){
		calculateRotation();
	}else{
		lookAt(*LookingAt);
	}
	float transM4[16]={
		1,0,0,-position.x,
		0,1,0,-position.y,
		0,0,1,-position.z,
		0,0,0, 1
	};
	float proj[16]={
		1.0f/tan(fov),            0,  0,  0,
		0,(1.0f*aspectRatio)/tan(fov),  0,  0,
		0,                        0,  1, -0.01f,
		0,                        0,  1,  0
	};
	//multiplications
	float* temp1=m4_multiply(rotM4,transM4);
	free(OVM);
	OVM=m4_multiply(proj,temp1);
	free(temp1);
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


/*********************************************************************************/
//UI_Element


//constructor
UI_Element::UI_Element(vec2 iPos, vec2 iScale, const char* name):
pos(iPos),scale(iScale){
	//initialization
	NAME=(char*)malloc(strlen(name));
	memcpy(NAME,name,strlen(name));
	glGenVertexArrays(1,&vArr);
	glGenBuffers(1,&posBuff);
	glGenBuffers(1,&texBuff);
	//tex coordinates (static)
	glBindVertexArray(vArr);
	glBindBuffer(GL_ARRAY_BUFFER,texBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*12,vTex,GL_STATIC_DRAW);
	glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(3);
	//vertex positions
	updateArrays();
}


//destructor
UI_Element::~UI_Element(){
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
	return mainTex.loadDefault();
}

int UI_Element::setActive(bool state){
	Active=state;
	return 0;
}


//extractors
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
	vPos=new float[12]{
		pos.x+scale.x,pos.y+scale.y,
		pos.x+scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y-scale.y,
		pos.x-scale.x,pos.y+scale.y,
		pos.x+scale.x,pos.y+scale.y
	};
	updateBuffers();
	delete[] vPos;
	return 0;
}

int UI_Element::updateBuffers(){
	glBindVertexArray(vArr);
	glBindBuffer(GL_ARRAY_BUFFER,posBuff);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*12,vPos,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(void*)0);
	glEnableVertexAttribArray(0);
	return 0;
}


/*********************************************************************************/
//SkyBox


//initializers
void SkyBox::initData(){
	float posses[108]={
		//Z+
		-1,-1, 1,-1, 1, 1, 1,-1, 1,//1 face
		 1,-1, 1,-1, 1, 1, 1, 1, 1,
		//Z-
		 1,-1,-1, 1, 1,-1,-1,-1,-1,
		-1,-1,-1, 1, 1,-1,-1, 1,-1,
		//Y+
		-1,	1, 1,-1, 1,-1, 1, 1,-1,
		 1, 1,-1, 1, 1, 1,-1, 1, 1,
		//Y-
		-1,-1,-1,-1,-1, 1, 1,-1,-1,
		 1,-1,-1,-1,-1, 1, 1,-1, 1,
		//X+
		 1,-1, 1, 1, 1, 1, 1,-1,-1,
		 1,-1,-1, 1, 1, 1, 1, 1,-1,
		//X-
		-1,-1,-1,-1, 1,-1,-1,-1, 1,
		-1,-1, 1,-1, 1,-1,-1, 1, 1
	};

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*108,posses,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*3,(void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}


//constructors
SkyBox::SkyBox(const char* name){
	NAME=(char*)calloc(strlen(name)+1,sizeof(char));
	memcpy(NAME,name,strlen(name));
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	initData();
}

SkyBox::SkyBox(const char* sides[6], const char* name):
CubeMap(sides){
	NAME=(char*)calloc(strlen(name)+1,sizeof(char));
	memcpy(NAME,name,strlen(name));
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1,&VBO);
	initData();
}


//destructors
SkyBox::~SkyBox(){
	glDeleteBuffers(1,&VBO);
	glDeleteVertexArrays(1,&VAO);
	free(NAME);
}


//uility
int SkyBox::bind(){
	glBindVertexArray(VAO);
	bindCM();
	return 0;
}

int SkyBox::unbind(){
	glBindVertexArray(0);
	unbindCM();
	return 0;
}


/*********************************************************************************/