#ifndef LIGHT
#define LIGHT

#include <cstdlib>
#include <cstring>
#include "T0.h"

class Light{
protected:
	char* NAME=NULL;
	vec3 position;
	vec4 color;//w used as strength
	float data[8];
	int type=0;//usage for now 0=point 1=directional
	float* LVM=NULL;//light view matrix

public:
	//constructors
	Light(int iType=0, vec3 iPos={0}, vec4 iCol={1}, const char* name="default\0");

	//destructors
	~Light();

	//utility
	int update();
	int move(vec3 movement);
	int calculateMatrix();

	//loaders
	int loadData(int iType, vec3 iPos, vec4 iCol);
	int setColor(vec4 iCol);
	int setPosition(vec3 iPos);

	//extractors
	float* getData();

	//friend classes
	friend class SceneManager;
};
//future idea use position.w as identity
//as an example point light can be 0 and directional can be 1
//and use the class as light not specifically just one type

#endif