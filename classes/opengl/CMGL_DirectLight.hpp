#ifndef CMGL_DIRECTLIGHT
#define CMGL_DIRECTLIGHT

#include "../base/Light.hpp"
#include <GL/glew.h>

//note: binds ssb to binding 6

class CMGL_DirectLight : public Light{
private:
    vec3 direction = {0,1,0};//direction from surfaces normal, so light looks at the opposite site of this vector
    uint32_t SSB;
    float* LVM = NULL;
    float shadowPrecision = 50;

public:
    //constructors
    CMGL_DirectLight();
    CMGL_DirectLight(DirectLightData data);

    //destructors
    ~CMGL_DirectLight();

    //setters
    void setDirection(vec3 inDir);
    void setShadowPrecision(float inP);

    //getters
    vec3 getDirection();

    //utility
    void bind();
    void bindAsCam();

    //overrides
    void updateLight() override;
    void updateTransform() override;

};

#endif