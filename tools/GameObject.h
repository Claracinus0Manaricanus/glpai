#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <GL/glew.h>
#include "Transform.h"
#include "VertexData.h"
#include "Texture.h"
#include "T0.h"

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

#endif