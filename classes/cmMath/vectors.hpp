#ifndef VECTORS
#define VECTORS

#include "../system/T0.hpp"
#include <math.h>

//vector utilities
float Dot(vec3 a, vec3 b);
vec3 Cross(vec3 a, vec3 b);//a X b
float Length(vec3 a);
float Length(vec2 a);
vec3 Normalize(vec3 a);
vec2 Normalize(vec2 a);

#endif