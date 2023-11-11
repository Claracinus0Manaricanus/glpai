#ifndef B1_H
#define B1_H

#include "B0.h"
#include "T0.h"
#include <cstdint>
#include <string>
#include <cstring>


class Camera : public Transform{
protected:
	float fov;//field of view (60=default) //add changeFov
	float aspectRatio;

public:
//constructors
	Camera(float Ifov=60, float inAspectRatio=1);

//control
	void moveForward(float forward);
	void moveRight(float right);
	void moveUp(float up);
	void setAspectRatio(float inAspectRatio);
	void calculateMatrix();
};


class GameObject : public Transform, public VertexData{
protected:
	uint32_t vArr;//vertexArray
	uint32_t posBuff,norBuff,colBuff,texBuff;//buffers
	Texture mainTex;
	//state bools
	bool bTex=false;//bool color and bool texture

protected:
	//initializers
	void initBuffers();

public:
	//constructors
	GameObject(const char* name="default\0");
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


class UI_Element{//has 6 vertices
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
	UI_Element(vec2 iPos={0,0}, vec2 iScale={1,1}, const char* name="default");

	//destructor
	~UI_Element();

	//loaders
	int changePos(vec2 iPos);
	int changeScale(vec2 iScale);
	int loadTexture(const char* filename, bool mipmap=true);
	int unloadTexture();
	int setActive(bool state);

	//extractors
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


class SkyBox : public CubeMap{
protected:
	char* NAME=NULL;
	//opengl
	uint32_t VAO;//vertex array
	uint32_t VBO;//indexes 0:position 1:texture coordinates
	
private:
	//initializers
	void initData();

public:
	//constructors
	SkyBox(const char* name="default");
	SkyBox(const char* sides[6], const char* name="default");

	//destructors
	~SkyBox();

	//uility
	int bind();
	int unbind();

	//friend classes
	friend class SceneManager;
};


#endif