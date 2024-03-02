#ifndef CM_LIGHT
#define CM_LIGHT

#include "Transform.hpp"

#include <cstdlib>
#include <cstring>

class Light : public Transform{
protected:
    int type=0;
    vec4 color={0,0,0,0};
    float* data=NULL;

public:
    //constructors
    Light();
    Light(LightData lDat);

    //destructors
    ~Light();

    //setters
    void setType(int iType);

    //getters
    int getType();

    //utility
    float* getData();
    void updateData();

    //Transform overrides
    void updateTransform() override;
};

#endif