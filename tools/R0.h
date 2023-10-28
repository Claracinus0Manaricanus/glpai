#ifndef R0_H
#define R0_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdint>
#include "T0.h"


class shader{
public:
	uint32_t id=0;

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
	uint32_t id=0;
	bool loaded;

public:
	//constructor
	program();
	program(shader* vertex, shader* fragment);

	//loaders
	int load(shader* vertex, shader* fragment);

	//extractors
	uint32_t getid();

	//destructor
	~program();

	//binder
	int use();
};//if id=0 then error


class window{
private:
	GLFWwindow *id;

public:
	//constructor
	window(vec2int resolution,std::string);

	//extractor
	GLFWwindow* getid();

	//utility
	int changeAttrib(int attrib, int value);
	int setResolution(int x, int y);//not implemented do not use
	vec2int getResolution();
};


#endif