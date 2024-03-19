#ifndef TRANFORM_HPP
#define TRANFORM_HPP

#include "../system/T0.hpp"
#include "../cmMath/matrix4.hpp"
#include <cmath>

class Transform{
protected:
    //data vectors
    vec3 Position = {0,0,0};
    vec3 Rotation = {0,0,0};
    vec3 Scale = {1,1,1};
    
    //unit vectors
    vec3 forwardVector = {0,0,1};
    vec3 rightVector = {1,0,0};
    vec3 upVector = {0,1,0};

    //Object View Matrix
    float OVM[16] = {0};

public:
    //constructors
    Transform();
    Transform(TransformData inputTransform);

    //destructors
    ~Transform();

    //setters
    void loadData(TransformData inputTransform);
    void setPosition(vec3 newPosition);
    void setRotation(vec3 newRotation);
    void setScale(vec3 newScale);
    void move(vec3 movement);
    void rotate(vec3 rotation);
    void scale(vec3 scaleToAdd);

    //getters
    TransformData getTransformData();
    vec3 getPosition();
    vec3 getRotation();
    vec3 getScale();

    //utility
    virtual void generateVectors();//sets unit vector according to rotation
    void lookAt(vec3 destination, vec3 up);//sets unit vector according to look destination
    void moveForward(float step);
    void moveRight(float step);
    void moveUp(float step);

    //updaters
    virtual void updateTransform();
    virtual void updateOVM();
};

#endif