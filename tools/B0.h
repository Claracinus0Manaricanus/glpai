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


class CubeMap{
protected:
	char* NAME;
	uint32_t ID;

	//cubemap side textures data holders
	uint8_t* data_XP;//X+
	int iWidth_XP,iHeight_XP;
	uint8_t* data_XN;//X-
	int iWidth_XN,iHeight_XN;
	uint8_t* data_YP;//Y+
	int iWidth_YP,iHeight_YP;
	uint8_t* data_YN;//Y-
	int iWidth_YN,iHeight_YN;
	uint8_t* data_ZP;//Z+
	int iWidth_ZP,iHeight_ZP;
	uint8_t* data_ZN;//Z-
	int iWidth_ZN,iHeight_ZN;

public:
	//constructor
	CubeMap(const char* name="default");

	//destructor
	~CubeMap();
	
	//loaders
	int loadSideXP(const char* filename);//X+ side
	int loadSideXN(const char* filename);//X- side
	int loadSideYP(const char* filename);//Y+ side
	int loadSideYN(const char* filename);//Y- side
	int loadSideZP(const char* filename);//Z+ side
	int loadSideZN(const char* filename);//Z- side

	//utility
	int bind();//binding ID as GL_TEXTURE_CUBE_MAP
	int unbind();//binding 0 as GL_TEXTURE_CUBE_MAP

};


class SkyBox : public CubeMap{
protected:
	char* NAME;

public:
	//constructors
	SkyBox(const char* name="default");

	//destructors
	~SkyBox();

	//friend classes
	friend class SceneManager;
};

#endif

