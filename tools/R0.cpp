#include "R0.h"
#include <fstream>
#include <iostream>


/*********************************************************************************/
//shader

//constructor
shader::shader(std::string source, unsigned int type, bool debug){
	//creating shader
	id=glCreateShader(type);

	//getting shader from source file
	std::string line,total;
	std::ifstream sourceIn(source);
	while(getline(sourceIn,line)){
		total+=line+'\n';
	}sourceIn.close();

	const char* src=total.c_str();

	//compiling shader
	glShaderSource(id,1,&src,NULL);
	glCompileShader(id);

	char inf[1024];
	if(debug&&getError(inf)>0){
		std::cout<<std::endl<<inf;
	}
}//needs error checking (fstream)


//destructor
shader::~shader(){
	if(id!=0)
		glDeleteShader(id);
}


//loaders
int shader::load(std::string source, uint32_t type, bool debug){
	//deleting old shader
	if(id!=0)
		glDeleteShader(id);

	//creating new shader
	id=glCreateShader(type);

	//getting shader source file
	std::string line,total;
	std::ifstream sourceIn(source);
	while(getline(sourceIn,line)){
		total+=line+'\n';
	}sourceIn.close();

	const char* src=total.c_str();

	//compiling shader
	glShaderSource(id,1,&src,NULL);
	glCompileShader(id);

	char inf[1024];
	if(debug&&getError(inf)>0){
		std::cout<<std::endl<<inf;
	}
	return 0;
}


//utility
int shader::Delete(){
	glDeleteShader(id);
	id=0;
	return 0;
}//check needed

int shader::getError(char ret[1024]){
	int tempLength;
	glGetShaderInfoLog(id,1024,&tempLength,ret);
	return tempLength;
}//error check needed (glGetShaderInfoLog())

//reusable shader objects?


/*********************************************************************************/
//program


//constructor
program::program(){
	id=glCreateProgram();
	loaded=false;
}

program::program(shader* vertex, shader* fragment){
	id=glCreateProgram();
	glAttachShader(id,vertex->id);
	glAttachShader(id,fragment->id);
	glLinkProgram(id);
	loaded=true;
}


//loaders
int program::load(shader* vertex, shader* fragment){
	if(loaded)
		return -1;
	glAttachShader(id,vertex->id);
	glAttachShader(id,fragment->id);
	glLinkProgram(id);
	loaded=true;
	return 0;
}


//extractors
uint32_t program::getid(){
	return id;
}


//destructor
program::~program(){
	glDeleteProgram(id);
}


//binder
int program::use(){
	glUseProgram(id);
	return 0;
}


/*********************************************************************************/
//window


//constructor
window::window(vec2int resolution,std::string name){
	id=glfwCreateWindow(resolution.x,resolution.y,name.c_str(),NULL,NULL);
}


//extractor
GLFWwindow* window::getid(){
	return id;
}


//utility
int window::changeAttrib(int attrib, int value){
	glfwSetWindowAttrib(id,attrib,value);
	return 0;
}//error check needed

vec2int window::getResolution(){
	vec2int temp;
	glfwGetFramebufferSize(id,&temp.x,&temp.y);
	return temp;
}


/*********************************************************************************/