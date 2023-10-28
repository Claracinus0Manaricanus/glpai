#ifndef B2_H
#define B2_H

#include "B1.h"
#include "R0.h"

class SceneManager{
protected:
	//state identifiers
	bool S_FULLBRIGHT=false;
	//data holders
	int L_objects=0;
	GameObject** objects=NULL;
	int L_lights=0;
	Light** lights=NULL;
	int L_UIElemenets=0;
	UI_Element** UIElements;
	//programs
	program pFB[2];//perspective fullbright //col 0, tex 1
	program pL[2];//perspective light //col 0, tex 1
	program pUI;

public:
	//constructors
	SceneManager();

	//destructor
	~SceneManager();

	//program control
	int setPrograms(program* in_pFB, program* in_pL, program* in_pUI);

	//array control
	int addLight(const char* name);
	int addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName=NULL, bool useMipmap=false);
	int addIUElement(const char* name);

	//element selector
	GameObject* getObject(const char* name);//get GameObject from name
	GameObject* getObject(int index);//get GameObject from index

	//drawing utility
	int draw();//draws scene to screen

	//state controllers
	int setFullbright(bool state);

	//debugging
	GameObject** getObjects();
};

//freetype library

#endif