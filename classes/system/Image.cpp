#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//constructors
Image::Image(){
	imgData=(uint8_t*)malloc(4);
	imgData[0]=255;
	imgData[1]=255;
	imgData[2]=255;
	imgData[3]=255;
}

Image::Image(ImageData data){
	load(data);
}


//destructors
Image::~Image(){
	stbi_image_free(imgData);
}


//loaders
int Image::load(ImageData data){	
	stbi_image_free(imgData);//to free previous image
	
	stbi_set_flip_vertically_on_load(data.flipImage);
	imgData = stbi_load(data.imageFile,&iWidth,&iHeight,&iChannel,data.desiredChannels);

	if(data.desiredChannels != 0)//if channel preferation specified
		iChannel=data.desiredChannels;

	if(imgData == NULL){
		printf("Failed to load image: %s\n",data.imageFile);
		return -1;
	}

	return 0;
}


//extractors
int Image::width(){
	return iWidth;
}

int Image::height(){
	return iHeight;
}

int Image::spectrum(){
	return iChannel;
}


uint8_t* Image::getDataP(){
	return imgData;
}


//utility
int Image::reset(){
	stbi_image_free(imgData);
	
	imgData=(uint8_t*)malloc(4);
	imgData[0]=255;
	imgData[1]=255;
	imgData[2]=255;
	imgData[3]=255;

	iWidth=1;
	iHeight=1;
	iChannel=4;
	
	return 0;
}