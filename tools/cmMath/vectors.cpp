#include "vectors.h"

//vector utilities
float Length(vec3 a){
    return sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z));
}

vec3 Normalize(vec3 a){
    float aLength=Length(a);
    vec3 ret=a/aLength;
    return ret;
}


//rotation related
float* lookAt(vec3 start, vec3 end, vec3 up){
    float* rotMat=(float*)malloc(sizeof(float)*16);//rotation matrix

    

    return NULL;
}