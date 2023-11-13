#include "vectors.h"

//vector utilities
float Dot(vec3 a, vec3 b){
    float ret=0;
    
    for(int i=0;i<3;i++){
        ret+=a[i]*b[i];
    }

    return ret;
}

vec3 Cross(vec3 a, vec3 b){
    return {0};
}

float Length(vec3 a){
    return sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z));
}

vec3 Normalize(vec3 a){
    float aLength=Length(a);
    vec3 ret=a/aLength;
    return ret;
}


//rotation related
float* lookAt(vec3 start, vec3 end, vec3 up){//needs optimization
    float* rotMat=(float*)malloc(sizeof(float)*16);//rotation matrix

    vec3 Z=Normalize(end-start);
    vec3 X={0};
    vec3 Y=Normalize(Cross(Z,X));

    for(int i=0;i<3;i++){
        rotMat[i*4]=X[i];
        rotMat[i*4+1]=Y[i];
        rotMat[i*4+2]=Z[i];
        rotMat[i*4+3]=0;
    }
    rotMat[12]=0;
    rotMat[13]=0;
    rotMat[14]=0;
    rotMat[15]=1;

    return rotMat;
}