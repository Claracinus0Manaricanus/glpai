#ifndef B2_H
#define B2_H

#include "B1.h"
#include "R0.h"

class sceneManager{
protected:
	int L_objects=0;
	gameObject** objects=NULL;
	int L_lights=0;
	light* lights=NULL;
	program pFB[2];//perspective fullbright //col 0, tex 1
	program pL[2];//perspective light //col 0, tex 1
	program pUI;

public:
	//constructors
	sceneManager();

	//program control
	int setPrograms(program* in_pFB, program* in_pL, program* in_pUI);

	//array control
	int addLight(const char* name);
	int addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName=NULL, bool useMipmap=false);

	//element selector
	gameObject* getObject(const char* name);//get gameObject from name
	gameObject* getObject(int index);//get gameObject from index


	//drawing utility
	int draw();//draws scene to screen

	//debugging
	gameObject** getObjects();

	//destructors
	~sceneManager();
};

//freetype library

#endif