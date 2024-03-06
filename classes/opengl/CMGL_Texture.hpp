#ifndef CMGL_TEXTURE
#define CMGL_TEXTURE

#include "../system/Image.hpp"//also include T0.hpp
#include <GL/glew.h>

class CMGL_Texture{
protected:
    uint32_t ID = 0;
    uint32_t Unit = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    uint32_t textureType = 0;
    uint32_t textureFormat = 0;

public:
    //constructors
    CMGL_Texture();
    CMGL_Texture(TextureData inputData);

    //destructors
    ~CMGL_Texture();

    //setters
    int loadData(TextureData inputData);
    int loadData(CMGL_Texture& inputTex);
    void setTextureUnit(uint32_t inUnit);

    //getters
    uint32_t getTextureUnit();
    uint32_t getID();
    uint32_t getWidth();
    uint32_t getHeight();
    uint32_t getType();
    uint32_t getFormat();

    //utility
    void bind();
    void unbind();
    void loadDefault();

};

#endif