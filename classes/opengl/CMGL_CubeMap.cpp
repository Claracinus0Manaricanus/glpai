#include "CMGL_CubeMap.hpp"

//private
void CMGL_CubeMap::initTexture(){
    glGenTextures(1, &cubeMap);
}


//constructors
CMGL_CubeMap::CMGL_CubeMap(){
    initTexture();
}

CMGL_CubeMap::CMGL_CubeMap(CubeMapData inData){
    initTexture();
    loadAll(inData);
}


//destuctors
CMGL_CubeMap::~CMGL_CubeMap(){
    glDeleteTextures(1, &cubeMap);
}


//setters
int CMGL_CubeMap::loadAll(CubeMapData inData){
    bind();

    //glTex paramaters
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);

    //readying Image class
    Image tmpImage;
    ImageData tmpIMGData;

    for(int i=0; i < 6; i++){
        //importing image
        tmpIMGData.imageFile = inData.sides[i];
        tmpImage.load(tmpIMGData);

        //loading cubeMap sides
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());
    }

    return 0;
}

int CMGL_CubeMap::setPositiveX(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());
    
    return 0;
}

int CMGL_CubeMap::setNegativeX(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());

    return 0;
}

int CMGL_CubeMap::setPositiveY(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());

    return 0;
}

int CMGL_CubeMap::setNegativeY(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());

    return 0;
}

int CMGL_CubeMap::setPositiveZ(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());

    return 0;
}

int CMGL_CubeMap::setNegativeZ(char* fileName){
    ImageData tmpIMGData;

    tmpIMGData.imageFile = fileName;
    Image tmpImage(tmpIMGData);
    
    //loading cubeMap sides
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB8, tmpImage.width(), tmpImage.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, tmpImage.getDataP());

    return 0;
}


//getters


//utility
void CMGL_CubeMap::bind(){
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeMap);
}

void CMGL_CubeMap::unbind(){
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
