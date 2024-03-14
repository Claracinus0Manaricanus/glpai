#ifndef CM_LIGHT
#define CM_LIGHT

#include "Transform.hpp"

#include <cstdlib>
#include <cstring>

class Light : public Transform{
protected:
    int type = 0;
    vec4 color={1,1,1,1};
    float* data=NULL;
    int dataLength = 0;//in vec4 so 2 means 8 floats

public:
    //constructors
    Light();

    //destructors
    ~Light();

    //setters
    void setColor(vec4 inColor);

    //getters
    int getType();
    vec4 getColor();
    int getDataLength();

    //utility
    float* getData();

    //overridables
    virtual void updateLight();
};

#endif