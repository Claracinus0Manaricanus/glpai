#ifndef CMGL_SHADER
#define CMGL_SHADER

#include <GL/glew.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

class CMGL_Shader{
public:
	uint32_t ID=0;

public:
	//constructor
	CMGL_Shader(){};
	CMGL_Shader(const char* sourceFile, uint32_t type, bool debug=true);

	//destructor
	~CMGL_Shader();

	//loaders
	int load(const char* sourceFile, uint32_t type, bool debug=true);

	//utility
	int Delete();
	int getError(char* ret);
};

#endif