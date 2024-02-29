#include "CMGL_Program.hpp"

//constructor
CMGL_Program::CMGL_Program(){
	ID=glCreateProgram();
	loaded=false;
}

CMGL_Program::CMGL_Program(CMGL_Shader* vertex, CMGL_Shader* fragment){
	ID=glCreateProgram();
	load(vertex,fragment);
}

CMGL_Program::CMGL_Program(const char* vName, const char* fName){
	//create CMGL_Program
	ID=glCreateProgram();
	load(vName,fName);
}


//destructor
CMGL_Program::~CMGL_Program(){
	glDeleteProgram(ID);
}


//loaders
int CMGL_Program::load(CMGL_Shader* vertex, CMGL_Shader* fragment){
	if(loaded){
		glDeleteProgram(ID);
		ID=glCreateProgram();
	}
	glAttachShader(ID,vertex->ID);
	glAttachShader(ID,fragment->ID);
	glLinkProgram(ID);
	loaded=true;
	return 0;
}

int CMGL_Program::load(const char* vName, const char* fName){
	if(loaded){
		glDeleteProgram(ID);
		ID=glCreateProgram();
	}
	//load shaders
	CMGL_Shader vertex(vName,GL_VERTEX_SHADER);
	CMGL_Shader fragment(fName,GL_FRAGMENT_SHADER);
	//attaching
	glAttachShader(ID,vertex.ID);
	glAttachShader(ID,fragment.ID);
	glLinkProgram(ID);
	loaded=true;
	//shader classes do auto cleanup
	return 0;
}


//uniform utilities
int CMGL_Program::setInt(const char* u_name, int data){
	use();//CMGL_Program needs to be in use before uniform stuff
	glUniform1i(glGetUniformLocation(ID,u_name),data);
	return 0;//todo: return if any opengl errors (for all)
}

int CMGL_Program::setVec2i(const char* u_name, ivec2 data){
	use();
	glUniform2i(glGetUniformLocation(ID,u_name),data.x,data.y);
	return 0;
}

int CMGL_Program::setVec2(const char* u_name, vec2 data){
	use();
	glUniform2f(glGetUniformLocation(ID,u_name),data.x,data.y);
	return 0;
}

int CMGL_Program::setVec3(const char* u_name, vec3 data){
	use();
	glUniform3f(glGetUniformLocation(ID,u_name),data.x,data.y,data.z);
	return 0;
}

int CMGL_Program::setVec4Array(const char* u_name, int dataLength, const float* data){
	use();
	glUniform4fv(glGetUniformLocation(ID,u_name),dataLength,data);
	return 0;
}

int CMGL_Program::setMat4(const char* u_name, const float* data){
	use();
	glUniformMatrix4fv(glGetUniformLocation(ID,u_name),1,GL_TRUE,data);
	return 0;
}


//extractors
uint32_t CMGL_Program::getid(){
	return ID;
}


//binder
int CMGL_Program::use(){
	glUseProgram(ID);
	return 0;
}