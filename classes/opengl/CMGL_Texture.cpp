#include "CMGL_Texture.hpp"


//utility
int CMGL_Texture::init(){
    glGenTextures(1, &ID);
    bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    return 0;
}

int CMGL_Texture::update(){
    bind();
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, iWidth, iHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);

    //do mipmaps

    return 0;
}


//constructors
CMGL_Texture::CMGL_Texture(){
    init();
    update();
}

CMGL_Texture::CMGL_Texture(TextureData inputData){
    init();
    
    Unit=inputData.unit;
    
    ImageData tmpData={inputData.imageFile, 4};
    Image::load(tmpData);
    update();
}


//destructors
CMGL_Texture::~CMGL_Texture(){
    glDeleteTextures(1, &ID);
}


//setters
int CMGL_Texture::loadData(TextureData inputData){
    ImageData tmpData={inputData.imageFile, 4};
    Image::load(tmpData);
    update();
    return 0;
}

void CMGL_Texture::setTextureUnit(uint32_t inUnit){
    Unit=inUnit;
}


//getters
uint32_t CMGL_Texture::getTextureUnit(){
    return Unit;
}


//utility
void CMGL_Texture::bind(){
    glActiveTexture(GL_TEXTURE0+Unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

int CMGL_Texture::reset(){
    Image::reset();
    update();

    return 0;
}