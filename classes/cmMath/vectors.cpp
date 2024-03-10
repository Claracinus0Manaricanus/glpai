#include "vectors.hpp"

//vector utilities
float Dot(vec3 a, vec3 b){
    float ret=0;
    
    for(int i=0;i<3;i++){
        ret+=a[i]*b[i];
    }

    return ret;
}

vec3 Cross(vec3 a, vec3 b){
    return {
        (a.y*b.z)-(a.z*b.y),
        (a.z*b.x)-(a.x*b.z),
        (a.x*b.y)-(a.y*b.x)
    };
}

float Length(vec3 a){
    return sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z));
}

float Length(vec2 a){
    return sqrt((a.x*a.x)+(a.y*a.y));
}

vec3 Normalize(vec3 a){
    float aLength=Length(a);
    vec3 ret;
    if(aLength == 0){
        ret = {0,0,0};
    }else{
        ret = a/aLength;
    }
    return ret;
}

vec2 Normalize(vec2 a){
    float aLength=Length(a);
    vec2 ret;
    if(aLength == 0){
        ret = {0,0};
    }else{
        ret = a/aLength;
    }
    return ret;
}