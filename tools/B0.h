#ifndef B0_H
#define B0_H

#include "T0.h"
#include <string>
#include <cstdint>
#include <GL/glew.h>


class transform{//add scale
public:
	vec3 position;
	vec3 rotation;
	vec3 scale;

public:
	//constructor
	transform();
	transform(vec3 inPosition, vec3 inRotation, vec3 inScale={1,1,1});

	//loaders
	void setPosition(vec3 inPos);
	void setRotation(vec3 inRot);
	void setScale(vec3 inSca);
	void setTransform(vec3 inPos, vec3 inRot, vec3 inSca);
	
	//transformations
	void move(vec3 movement);
	void rotate(vec3 inRotation);
};


class texture{
protected:
	uint32_t id;
	uint8_t* data;
	int iHeight,iWidth,iChannel;

public:
	//constructors
	texture();
	texture(std::string filename);

	//destructors
	~texture();

	//loaders
	int load(std::string filename, bool mipmap);
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


class vertexData{
protected:
	int vCount;//total vertices
	vertex* vertices;

public:
	//constructrors
	vertexData();
	vertexData(int inVCount);
	vertexData(int inVCount, vertex* iVertices);

	//destructor
	~vertexData();

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
	virtual vertexData* getPointer();
};//unsafe


class light : public transform{
protected:
	char* NAME;
	vec3 position;
	vec4 color;//w used as strength
	float data[8];
	int type=1;

public:
	//constructors
	light(const char* name="default\0");
	light(vec3 iPos, vec4 iCol, const char* name="default\0");

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

