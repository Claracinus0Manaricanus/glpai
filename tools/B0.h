#ifndef B0_H
#define B0_H

#include "T0.h"
#include <string>
#include <cstdint>
#include <GL/glew.h>


class Transform{//add scale
protected:
	char* NAME;

public:
	vec3 position;
	vec3 rotation;
	vec3 scale;

public:
	//constructor
	Transform(const char* name="default");
	Transform(vec3 inPosition, vec3 inRotation, vec3 inScale={1,1,1}, const char* name="default");

	//destructor
	~Transform();

	//loaders
	void setPosition(vec3 inPos);
	void setRotation(vec3 inRot);
	void setScale(vec3 inSca);
	void setTransform(vec3 inPos, vec3 inRot, vec3 inSca);
	
	//transformations
	void move(vec3 movement);
	void rotate(vec3 inRotation);
};


class Texture{
protected:
	uint32_t id;
	uint8_t* data;
	int iHeight,iWidth,iChannel;

public:
	//constructors
	Texture();
	Texture(const char* filename);

	//destructors
	~Texture();

	//loaders
	int load(const char* filename, bool mipmap);
	int unload();

	//extractors
	uint8_t* getData();
	int width();
	int height();
	int spectrum();

	//checkers
	bool loaded();

	//utility
	int bind();
	int unbind();
};


class VertexData{
protected:
	int vCount;//total vertices
	vertex* vertices;

public:
	//constructrors
	VertexData();
	VertexData(int inVCount);
	VertexData(int inVCount, vertex* iVertices);

	//destructor
	~VertexData();

	//loaders
	int setVertexCount(int inVCount);
	int setColor(vec4 inCol);
	int loadPos(vec3* inPos);
	int loadNor(vec3* inNor);
	int loadCol(vec4* inCol);
	int loadTex(vec2* inTex);
	int loadAll(int inVCount, vertex* iVertices);

	//extractors
	int getVCount();

	//utility
	int reset();
	virtual VertexData* getPointer();
};//unsafe


class Light : public Transform{
protected:
	char* NAME;
	vec3 position;
	vec4 color;//w used as strength
	float data[8];
	int type=1;

public:
	//constructors
	Light(const char* name="default\0");
	Light(vec3 iPos, vec4 iCol, const char* name="default\0");

	//utility
	int update();
	int move(vec3 movement);

	//loaders
	int loadData(vec3 iPos, vec4 iCol);
	int Color(vec4 iCol);
	int Position(vec3 iPos);

	//extractors
	float* getData();
};
//future idea use position.w as identity
//as an example point light can be 0 and directional can be 1
//and use the class as light not specifically just one type

#endif

