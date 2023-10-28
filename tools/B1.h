#ifndef B1_H
#define B1_H

#include "B0.h"
#include <cstdint>
#include <string>
#include <cstring>


class Camera : public Transform{
protected:
	float fov;//field of view (60=default) //add changeFov

public:
	Camera(float Ifov=60);
	
	void moveForward(float forward);
	void moveRight(float right);
	void moveUp(float up);
};


class GameObject : public Transform, public VertexData{
protected:
	char* NAME;
	uint32_t vArr;//vertexArray
	uint32_t posBuff,norBuff,colBuff,texBuff;//buffers
	Texture mainTex;
	//state bools
	bool bTex=false;//bool color and bool texture

protected:
	//initializers
	void initBuffers();
	void initName(const char* name);

public:
	//constructors
	GameObject(const char* name="default\0");
	GameObject(vec3 inPosition, vec3 inRotation, const char* name="default\0");
	GameObject(int inVCount, vertex* iVertices, const char* name="default\0");
	GameObject(vec3 inPosition, vec3 inRotation, int inVCount, vertex* iVertices, const char* name="default\0");
	GameObject(vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* name="default\0");

	//destructors
	~GameObject();

	//loaders
	int setColor(vec4 inCol);
	int loadData(vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices);
	int loadData(vec3 inPos, vec3 inRot, int inVCount, vertex* iVertices);
	int loadData(int inVCount, vertex* iVertices);
	int loadTexture(const char* filename, bool mipmap=true);
	int unloadTexture();

	//selectors
	int useColor(bool newState=true);

	//state identifiers
	bool usingTexture();

	//utility
	int bind();
	int unbind();
	int update();

	//friend classes
	friend class SceneManager;
};


class UI_Element{
protected:
	bool Active=true;
	char* NAME;
	uint32_t vArr;//opengl vertex array
	uint32_t posBuff,texBuff;//opengl buffers
	float* vPos=NULL;//vertex positions
	float* vTex=new float[12]{1,0,1,1,0,1,0,1,0,0,1,0};//tex coords
	vec2 pos={0,0},scale={1,1};//screen coordinates and scale
	Texture mainTex;//texture to use

public:
	//constructor
	UI_Element(const char* name="default");
	UI_Element(vec2 iPos, vec2 iScale, const char* name="default");

	//destructor
	~UI_Element();

	//loaders
	int changePos(vec2 iPos);
	int changeScale(vec2 iScale);
	int loadTexture(const char* filename, bool mipmap=true);
	int unloadTexture();
	int setActive(bool state);

	//extractors
	int getVCount();
	bool isActive();

	//utility
	int bind();
	int unbind();
	int updateArrays();
	int updateBuffers();
	
	//friend classes
	friend class SceneManager;
};//unsafe
//NEEDS FIX:
//unsafe usage without loaded textures

#endif