#include "GameObject.h"

//initializers
void GameObject::initBuffers(){
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1,&VBO);
}


//constructors
GameObject::GameObject(const char* name):
Transform(name){
	initBuffers();
}


//destructors
GameObject::~GameObject(){
	glDeleteBuffers(1,&VBO);
	glDeleteVertexArrays(1,&VAO);
}


//loaders
int GameObject::loadTexture(const char* filename, bool mipmap){
	mainTex.load(filename,mipmap);
	return 0;
}

int GameObject::unloadTexture(){
	mainTex.loadDefault();
	return 0;
}


//utility
int GameObject::bind(){
	if(updateNormals)update();
	glBindVertexArray(VAO);
	mainTex.bind();
	return 0;
}

int GameObject::unbind(){
	glBindVertexArray(0);
	mainTex.unbind();
	return 0;
}

int GameObject::update(){
	//normals
	for(int i=0;i<vCount;i++){
		vertices[i].nor.x=normals[i].x*scale.z*scale.y/scale.x;//division is for shader because
		vertices[i].nor.y=normals[i].y*scale.x*scale.z/scale.y;//they will get multiplied
		vertices[i].nor.z=normals[i].z*scale.x*scale.y/scale.z;//with the scaling matrix
	}
	updateNormals=false;//from transform class

	//vertex array
	glBindVertexArray(VAO);
	//vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertex)*vCount,vertices,GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*12,(void*)0);//Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*12,(void*)(sizeof(float)*3));//Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2,4,GL_FLOAT,GL_FALSE,sizeof(float)*12,(void*)(sizeof(float)*6));//Colors
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3,2,GL_FLOAT,GL_FALSE,sizeof(float)*12,(void*)(sizeof(float)*10));//UV
	glEnableVertexAttribArray(3);
	
	//cleanup
	unbind();
	return 0;
}