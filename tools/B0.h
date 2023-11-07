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
	uint32_t ID;
	uint8_t* data=NULL;
	int iHeight,iWidth,iChannel;

public:
	//constructors
	Texture();
	Texture(const char* filename);

	//destructors
	~Texture();

	//loaders
	int load(const char* filename, bool mipmap);
	int loadDefault();

	//extractors
	int width();
	int height();
	int spectrum();

	//utility
	int bind();
	int unbind();
};


class VertexData{
protected:
	int vCount=0;//total vertices
	vertex* vertices=nullptr;

public:
	//constructrors
	VertexData();
	VertexData(int inVCount, vertex* iVertices);

	//destructor
	~VertexData();

	//loaders
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


class Light{
protected:
	char* NAME=NULL;
	vec3 position;
	vec4 color;//w used as strength
	float data[8];
	int type=0;
	//usage for now 0=point 1=directional

public:
	//constructors
	Light(int iType=0, vec3 iPos={0}, vec4 iCol={1}, const char* name="default\0");

	//destructors
	~Light();

	//utility
	int update();
	int move(vec3 movement);

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


class CubeMap{
protected:
	uint32_t ID;
	int chan;

	//cubemap side textures data holders
	int iWidth,iHeight;//general purpose temporary
	uint8_t* iData=NULL;//general purpose temporary

public:
	//constructor
	CubeMap(const char* sides[6]=NULL);

	//destructor
	~CubeMap();
	
	//loaders
	int loadAllSides(const char* sides[6]);//starts from X+

	//utility
	int bindCM();//binding ID as GL_TEXTURE_CUBE_MAP
	int unbindCM();//binding 0 as GL_TEXTURE_CUBE_MAP

};


#endif

