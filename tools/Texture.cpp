#include "Texture.h"
#include "stb_image.h"

//constructors
Texture::Texture(){
	glGenTextures(1,&ID);
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	unbind();
	loadDefault();
}

Texture::Texture(const char* filename){
	glGenTextures(1,&ID);
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	unbind();
	load(filename,false);
}


//destructors
Texture::~Texture(){
	glDeleteTextures(1,&ID);
}


//loaders
int Texture::load(const char* filename,bool mipmap){
	data=stbi_load(filename,&iWidth,&iHeight,&iChannel,0);

	if(iChannel<3)
		return -1;

	bind();

	if(iChannel==3)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,iWidth,iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);
	if(iChannel==4)
		glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,iWidth,iHeight,0,GL_RGBA,GL_UNSIGNED_BYTE,data);

	if(mipmap)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	else
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	if(mipmap)
		glGenerateMipmap(GL_TEXTURE_2D);

	unbind();
	stbi_image_free(data);
	return 0;
}

int Texture::loadDefault(){
	bind();
	data=(uint8_t*)malloc(32);
	data[0]=255;data[1]=255;data[2]=255;data[3]=255;
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,1,1,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	unbind();
	free(data);
	return 0;
}


//extractors
int Texture::width(){
	return iWidth;
}

int Texture::height(){
	return iHeight;
}

int Texture::spectrum(){
	return iChannel;
}


//utility
int Texture::bind(){
	glBindTexture(GL_TEXTURE_2D,ID);
	return 0;
}

int Texture::unbind(){
	glBindTexture(GL_TEXTURE_2D,0);
	return 0;
}