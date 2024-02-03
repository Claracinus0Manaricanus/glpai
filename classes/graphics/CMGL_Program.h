#ifndef CMGL_PROGRAM
#define CMGL_PROGRAM

#include <GL/glew.h>
#include "CMGL_Shader.h"
#include "../system/T0.hpp"

class CMGL_Program{
protected://make protected
	uint32_t ID=0;
	bool loaded;

public:
	//constructor
	CMGL_Program();
	CMGL_Program(CMGL_Shader* vertex, CMGL_Shader* fragment);
	CMGL_Program(const char* vName, const char* fName);

	//loaders
	int load(CMGL_Shader* vertex, CMGL_Shader* fragment);
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
	~CMGL_Program();

	//binder
	int use();
};//if ID=0 then error

#endif