#ifndef CM_CAMERA
#define CM_CAMERA

#include "Transform.hpp"
#include "../cmMath/matrix4.hpp"

class Camera : public Transform{
private:
    int fov=120;
    int type=0;

public:
    //constructors
    Camera();
    Camera(int iFov, int iType);
    //setters
    void setFov(int iFov);
    void setType(int iType);

    //getters
    int getFov();
    int getType();

    //utility
    float* generateCVM();

};

#endif