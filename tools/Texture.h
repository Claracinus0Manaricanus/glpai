#ifndef TEXTURE
#define TEXTURE

#include <GL/glew.h>
#include <cstdlib>
#include "T0.h"

class Texture{
protected:
	uint32_t ID;
	uint8_t* data=NULL;
	int iHeight,iWidth,iChannel;

public:
	//constructors
	Texture();
	Texture(const char* filename);

	//destructors
	~Texture();

	//loaders
	int load(const char* filename, bool mipmap);
	int loadDefault();

	//extractors
	int width();
	int height();
	int spectrum();

	//utility
	int bind();
	int unbind();
};

#endif