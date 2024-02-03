#ifndef TRANFORM_HPP
#define TRANFORM_HPP

#include "../system/T0.hpp"

class Transform{
protected:
    vec3 Position={0,0,0};
    vec3 Rotation={0,0,0};
    vec3 Scale={1,1,1};

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

};

#endif