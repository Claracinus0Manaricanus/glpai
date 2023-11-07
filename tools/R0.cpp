#include "R0.h"
#include <fstream>
#include <iostream>


/*********************************************************************************/
//shader

//constructor
shader::shader(std::string source, unsigned int type, bool debug){
	//creating shader
	ID=glCreateShader(type);

	//getting shader from source file
	std::string line,total;
	std::ifstream sourceIn(source);
	while(getline(sourceIn,line)){
		total+=line+'\n';
	}sourceIn.close();

	const char* src=total.c_str();

	//compiling shader
	glShaderSource(ID,1,&src,NULL);
	glCompileShader(ID);

	char inf[1024];
	if(debug&&getError(inf)>0){
		std::cout<<std::endl<<inf;
	}
}//needs error checking (fstream)


//destructor
shader::~shader(){
	if(ID!=0)
		glDeleteShader(ID);
}


//loaders
int shader::load(std::string source, uint32_t type, bool debug){
	//deleting old shader
	if(ID!=0)
		glDeleteShader(ID);

	//creating new shader
	ID=glCreateShader(type);

	//getting shader source file
	std::string line,total;
	std::ifstream sourceIn(source);
	while(getline(sourceIn,line)){
		total+=line+'\n';
	}sourceIn.close();

	const char* src=total.c_str();

	//compiling shader
	glShaderSource(ID,1,&src,NULL);
	glCompileShader(ID);

	char inf[1024];
	if(debug&&getError(inf)>0){
		std::cout<<std::endl<<inf;
	}
	return 0;
}


//utility
int shader::Delete(){
	glDeleteShader(ID);
	ID=0;
	return 0;
}//check needed

int shader::getError(char ret[1024]){
	int tempLength;
	glGetShaderInfoLog(ID,1024,&tempLength,ret);
	return tempLength;
}//error check needed (glGetShaderInfoLog())

//reusable shader objects?


/*********************************************************************************/
//program


//constructor
program::program(){
	ID=glCreateProgram();
	loaded=false;
}

program::program(shader* vertex, shader* fragment){
	ID=glCreateProgram();
	glAttachShader(ID,vertex->ID);
	glAttachShader(ID,fragment->ID);
	glLinkProgram(ID);
	loaded=true;
}

program::program(const char* vName, const char* fName){
	//create program
	ID=glCreateProgram();
	//load shaders
	shader vertex(vName,GL_VERTEX_SHADER);
	shader fragment(fName,GL_FRAGMENT_SHADER);
	//attaching
	glAttachShader(ID,vertex.ID);
	glAttachShader(ID,fragment.ID);
	glLinkProgram(ID);
	loaded=true;
	//cleaning
	vertex.Delete();
	fragment.Delete();
}


//loaders
int program::load(shader* vertex, shader* fragment){
	if(loaded)
		return -1;
	glAttachShader(ID,vertex->ID);
	glAttachShader(ID,fragment->ID);
	glLinkProgram(ID);
	loaded=true;
	return 0;
}

int program::load(const char* vName, const char* fName){
	if(loaded)
		return -1;
	//load shaders
	shader vertex(vName,GL_VERTEX_SHADER);
	shader fragment(fName,GL_FRAGMENT_SHADER);
	//attaching
	glAttachShader(ID,vertex.ID);
	glAttachShader(ID,fragment.ID);
	glLinkProgram(ID);
	loaded=true;
	//cleaning
	vertex.Delete();
	fragment.Delete();
	return 0;
}


//uniform utilities
int program::setInt(const char* u_name, int data){
	use();//program needs to be in use before uniform stuff
	glUniform1i(glGetUniformLocation(ID,u_name),data);
	return 0;//todo: return if any opengl errors (for all)
}

int program::setVec2i(const char* u_name, vec2int data){
	use();
	glUniform2i(glGetUniformLocation(ID,u_name),data.x,data.y);
	return 0;
}

int program::setVec2(const char* u_name, vec2 data){
	use();
	glUniform2f(glGetUniformLocation(ID,u_name),data.x,data.y);
	return 0;
}

int program::setVec3(const char* u_name, vec3 data){
	use();
	glUniform3f(glGetUniformLocation(ID,u_name),data.x,data.y,data.z);
	return 0;
}

int program::setVec4Array(const char* u_name, int dataLength, const float* data){
	use();
	glUniform4fv(glGetUniformLocation(ID,u_name),dataLength,data);
	return 0;
}



//extractors
uint32_t program::getid(){
	return ID;
}


//destructor
program::~program(){
	glDeleteProgram(ID);
}


//binder
int program::use(){
	glUseProgram(ID);
	return 0;
}


/*********************************************************************************/
//window


//constructor
window::window(vec2int resolution,std::string name){
	ID=glfwCreateWindow(resolution.x,resolution.y,name.c_str(),NULL,NULL);
}


//extractor
GLFWwindow* window::getid(){
	return ID;
}


//utility
int window::changeAttrib(int attrib, int value){
	glfwSetWindowAttrib(ID,attrib,value);
	return 0;
}//error check needed

vec2int window::getResolution(){
	vec2int temp;
	glfwGetFramebufferSize(ID,&temp.x,&temp.y);
	return temp;
}


/*********************************************************************************/