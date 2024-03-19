#include "matrix4.hpp"

void m4_multiply(float* m1, float* m2){//m1 * m2
    float temp[4] = {0};
    
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            temp[k]=(m1[i*4]*m2[k])+(m1[i*4+1]*m2[k+4])+(m1[i*4+2]*m2[k+8])+(m1[i*4+3]*m2[k+12]);
        }

        m1[i*4] = temp[0];
        m1[i*4+1] = temp[1];
        m1[i*4+2] = temp[2];
        m1[i*4+3] = temp[3];
    }
}


float* m4_multiplyNew(float* m1, float* m2){//m1 * m2
    float* temp=(float*)calloc(16, sizeof(float));
    
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            temp[i*4+k]=(m1[i*4]*m2[k])+(m1[i*4+1]*m2[k+4])+(m1[i*4+2]*m2[k+8])+(m1[i*4+3]*m2[k+12]);
        }
    }
    
    return temp;
}


void m4_transpose(float* m1){
    float temp = 0;

    for(int i = 1; i < 4; i++){
        temp = m1[i];
        m1[i] = m1[i*4];
        m1[i*4] = temp;
    }

    for(int i = 1; i < 3; i++){
        temp = m1[i+5];
        m1[i+5] = m1[i*4+5];
        m1[i*4+5] = temp;
    }

    temp = m1[11];
    m1[11] = m1[14];
    m1[14] = temp;
}


float* m4_lookAt(vec3 source, vec3 destination, vec3 up){
    float* retMat = (float*)calloc(16, sizeof(float));

    vec3 forward = Normalize(destination - source);
    vec3 right = Normalize(Cross(up, forward));
    up = Normalize(Cross(forward, right));

    for(int i = 0; i < 3; i++){
        retMat[i*4] = right[i];
        retMat[i*4+1] = up[i];
        retMat[i*4+2] = forward[i];
    }
    retMat[15] = 1;

    return retMat;
}


void m4_copy(float* m1, float* m2){
    for(int i = 0; i < 16; i++){
        m1[i] = m2[i];
    }
}