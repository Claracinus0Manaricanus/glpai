#ifndef IMAGE
#define IMAGE

#include <cstdlib>
#include "T0.hpp"

class Image{
protected:
	uint8_t* imgData=NULL;
	int iHeight=1,iWidth=1,iChannel=4;

public:
	//constructors
	Image();
	Image(ImageData data);

	//destructors
	~Image();

	//loaders
	int load(ImageData data);

	//extractors
	int width();
	int height();
	int spectrum();
	uint8_t* getDataP();

	//utility
	int reset();
};

#endif