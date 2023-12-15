#ifndef GAMEOBJECT
#define GAMEOBJECT

#include <GL/glew.h>
#include "Transform.h"
#include "Mesh.h"
#include "Texture.h"
#include "T0.h"

class GameObject : public Transform, public Mesh{
protected:
	uint32_t VAO;//vertexArray
	uint32_t VBO;//buffers
	Texture mainTex;

protected:
	//initializers
	void initBuffers();

public:
	//constructors
	GameObject(const char* name="default\0");

	//destructors
	~GameObject();

	//loaders
	int setColor(vec4 inCol);
	int loadTexture(const char* filename, bool mipmap=true);
	int unloadTexture();

	//utility
	int bind();
	int unbind();
	int update();

	//friend classes
	friend class SceneManager;
};

#endif