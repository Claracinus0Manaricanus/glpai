#include "../T0.h"
#include <math.h>

//vector utilities
float Dot(vec3 a, vec3 b);
vec3 Cross(vec3 a, vec3 b);
float Length(vec3 a);
vec3 Normalize(vec3 a);

//rotation related
float* lookAt(vec3 start, vec3 end, vec3 up={0,1,0});