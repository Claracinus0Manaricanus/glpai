#ifndef CMGL_TEXTURE
#define CMGL_TEXTURE

#include "../system/Image.hpp"//also include T0.hpp
#include <GL/glew.h>

class CMGL_Texture : public Image{
protected:
    uint32_t ID=0;
    uint32_t Unit=0;

protected:
    //utility
    int init();
    int update();

public:
    //constructors
    CMGL_Texture();
    CMGL_Texture(TextureData inputData);

    //destructors
    ~CMGL_Texture();

    //setters
    int loadData(TextureData inputData);
    void setTextureUnit(uint32_t inUnit);

    //getters
    //some getters implemented at Image
    uint32_t getTextureUnit();

    //utility
    void bind();
    int reset();

};

#endif