#ifndef CMGL_CAMERA
#define CMGL_CAMERA

#include "../base/Camera.hpp"
#include "CMGL_Base.hpp"
#include <GL/glew.h>

//note: binds ssb to binding 5

class CMGL_Camera : public CMGL_Base, public Camera{
protected:
    uint32_t SSB;

protected:
    void initBuffers();

public:
    //constructors
    CMGL_Camera();
    CMGL_Camera(int iFov, int iType);

    //destructors
    ~CMGL_Camera();

    //utility
    void bind();

    //Transform overrides
    void updateTransform() override;
};

#endif