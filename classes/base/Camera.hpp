#ifndef CM_CAMERA
#define CM_CAMERA

#include "Transform.hpp"
#include "../cmMath/matrix4.hpp"

class Camera : public Transform{
protected:
    int fov=120;
    int type=0;
    float aspectRatio=0;

public:
    //constructors
    Camera();
    Camera(int iFov, int iType, float inAspectRatio=1);
    
    //setters
    void setFov(int iFov);
    void setType(int iType);
    void setAspectRatio(float inAspectRatio);

    //getters
    int getFov();
    int getType();

    //utility
    float* generateCVM();
    void moveForward(float step, float offset=0);

};

#endif