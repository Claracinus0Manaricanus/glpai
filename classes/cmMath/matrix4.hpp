#ifndef M4_H
#define M4_H

#include "../system/T0.hpp"
#include "vectors.hpp"
#include <cstdlib>

void m4_multiply(float* m1, float* m2);
float* m4_multiplyNew(float* m1, float* m2);
void m4_transpose(float* m1);
float* m4_lookAt(vec3 source, vec3 destination, vec3 up);//up must ve normalized

#endif