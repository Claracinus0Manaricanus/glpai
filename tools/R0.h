#ifndef R0_H
#define R0_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include "T0.h"


class shader{
public:
	uint32_t ID=0;

public:
	//constructor
	shader(){};
	shader(std::string source, uint32_t type, bool debug=true);

	//destructor
	~shader();

	//loaders
	int load(std::string source, uint32_t type, bool debug=true);

	//utility
	int Delete();
	int getError(char* ret);
};


class program{
protected://make protected
	uint32_t ID=0;
	bool loaded;

public:
	//constructor
	program();
	program(shader* vertex, shader* fragment);
	program(const char* vName, const char* fName);

	//loaders
	int load(shader* vertex, shader* fragment);
	int load(const char* vName, const char* fName);
	
	//uniform utilities
	int setInt(const char* u_name, int data);
	int setVec2i(const char* u_name, ivec2 data);
	int setVec2(const char* u_name, vec2 data);
	int setVec3(const char* u_name, vec3 data);
	int setVec4Array(const char* u_name, int dataLength,const float* data);
	int setMat4(const char* u_name, const float* data);

	//extractors
	uint32_t getid();

	//destructor
	~program();

	//binder
	int use();
};//if ID=0 then error


class window{
private:
	GLFWwindow *ID;

public:
	//constructor
	window(ivec2 resolution,std::string);

	//extractor
	GLFWwindow* getid();

	//utility
	int changeAttrib(int attrib, int value);
	//int setResolution(int x, int y);//not implemented do not use
	ivec2 getResolution();
};


#endif