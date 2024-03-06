#include "CMGL_Texture.hpp"


//constructors
CMGL_Texture::CMGL_Texture(){
    glGenTextures(1, &ID);
    loadDefault();
}


CMGL_Texture::CMGL_Texture(TextureData inputData){
    glGenTextures(1, &ID);
    loadData(inputData);
}


//destructors
CMGL_Texture::~CMGL_Texture(){
    glDeleteTextures(1, &ID);
}


//setters
int CMGL_Texture::loadData(TextureData inputData){
    Unit = inputData.unit;
    width = inputData.width;
    height = inputData.height;
    textureType = inputData.textureType;
    textureFormat = inputData.textureFormat;
    
    bind();

    glTexParameteri(textureType, GL_TEXTURE_WRAP_S, inputData.textureWrap);
    glTexParameteri(textureType, GL_TEXTURE_WRAP_T, inputData.textureWrap);
    //add mipmaps
    glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, inputData.textureFilter);
    glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, inputData.textureFilter);

    glTexImage2D(textureType, 0, textureFormat, width, height, 0, textureFormat, inputData.textureDataType, inputData.data);

    unbind();
    return 0;
}

int CMGL_Texture::loadData(CMGL_Texture& inputTex){
    if(ID != inputTex.ID){
        glDeleteTextures(1, &ID);
    }else{
        return -1;
    }

    ID = inputTex.ID;
    Unit = inputTex.Unit;
    width = inputTex.width;
    height = inputTex.height;
    textureType = inputTex.textureType;
    textureFormat = inputTex.textureFormat;

    return 0;
}

void CMGL_Texture::setTextureUnit(uint32_t inUnit){
    Unit = inUnit;
}


//getters
uint32_t CMGL_Texture::getTextureUnit(){
    return Unit;
}

uint32_t CMGL_Texture::getID(){
    return ID;
}

uint32_t CMGL_Texture::getWidth(){
    return width;
}

uint32_t CMGL_Texture::getHeight(){
    return height;
}

uint32_t CMGL_Texture::getType(){
    return textureType;
}

uint32_t CMGL_Texture::getFormat(){
    return textureFormat;
}


//utility
void CMGL_Texture::bind(){
    glActiveTexture(GL_TEXTURE0+Unit);
    glBindTexture(textureType, ID);
}

void CMGL_Texture::unbind(){
    glBindTexture(textureType, 0);
}

void CMGL_Texture::loadDefault(){
    Unit = 0;
    width = 1;
    height = 1;
    textureType = GL_TEXTURE_2D;
    textureFormat = GL_RGBA;

    char data[4]={
        (char)255,(char)255,(char)255,(char)255
    };
    
    bind();

    glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //add mipmaps
    glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glTexImage2D(textureType, 0, textureFormat, width, height, 0, textureFormat, GL_UNSIGNED_BYTE, data);

    unbind();
}