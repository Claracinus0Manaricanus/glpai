#ifndef CMGL_CUBEMAP
#define CMGL_CUBEMAP

#include "../system/T0.hpp"
#include "../system/Image.hpp"

#include <GL/glew.h>

class CMGL_CubeMap{
protected:
    uint32_t cubeMap;

protected:
    void initTexture();

public:
    //constructors
    CMGL_CubeMap();
    CMGL_CubeMap(CubeMapData inData);

    //destructors
    ~CMGL_CubeMap();

    //setters
    int loadAll(CubeMapData inData);
    int setPositiveX(char* fileName);
    int setNegativeX(char* fileName);
    int setPositiveY(char* fileName);
    int setNegativeY(char* fileName);
    int setPositiveZ(char* fileName);
    int setNegativeZ(char* fileName);

    //getters

    //utility
    void bind();
    void unbind();
    //int reset();
};

#endif