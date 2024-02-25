#include "matrix4.hpp"
#include <stdlib.h>

float* m4_multiply(float* m1, float* m2){//m1 * m2
    float* temp=(float*)calloc(16, sizeof(float));
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            temp[i*4+k]=(m1[i*4]*m2[k])+(m1[i*4+1]*m2[k+4])+(m1[i*4+2]*m2[k+8])+(m1[i*4+3]*m2[k+12]);
        }
    }
    return temp;
}