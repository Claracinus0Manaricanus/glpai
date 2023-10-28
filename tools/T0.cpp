#include "T0.h"

float vectors::dot(vec3 a, vec3 b){
	return ((a.x*b.x)+(a.y*b.y)+(a.z*b.z));
}

float vectors::dot(vec2 a, vec2 b){
	return ((a.x*b.x)+(a.y*b.y));
}

vec3 vectors::normalize(vec3 a){
	vec3 temp=a*a;
	float length=sqrt(temp.x+temp.y+temp.z);
	temp={a.x/length,a.y/length,a.z/length};
	return temp;
}

vec2 vectors::normalize(vec2 a){
	vec2 temp=a*a;
	float length=sqrt(temp.x+temp.y);
	temp={a.x/length,a.y/length};
	return temp;
}