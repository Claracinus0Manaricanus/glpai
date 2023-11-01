#ifndef B2_H
#define B2_H

#include "B1.h"
#include "R0.h"

class SceneManager{
protected:
	//state identifiers
	bool S_FULLBRIGHT=false;
	int C_SKYBOX=-1;//-1 means no skybox otherwise index of skybox to use
	//data holders L_ means array length of
	int L_objects=0;
	GameObject** objects=NULL;
	int L_lights=0;
	Light** lights=NULL;
	int L_UIElements=0;
	UI_Element** UIElements=NULL;
	int L_skyboxes=0;
	SkyBox** skyboxes=NULL;
	//programs
	program pFB[2];//perspective fullbright //col 0, tex 1
	program pL[2];//perspective light //col 0, tex 1
	program pSky;//skybox renderer
	program pUI;//UI_Element renderer

public:
	//constructors
	SceneManager();

	//destructor
	~SceneManager();

	//program control
	int setPrograms(program* in_pFB, program* in_pL, program* in_pUI,  program* in_pSky);

	//array control
	Light* addLight(const char* name);
	GameObject* addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName=NULL, bool useMipmap=false);
	UI_Element* addUI_Element(const char* name, vec2 iPos, vec2 iScale, const char* filename);
	SkyBox* addSkyBox(const char* name, const char* sides[6]);

	//element selector
	GameObject* getObject(const char* name);//get GameObject from name
	GameObject* getObject(int index);//get GameObject from index
	UI_Element* getUI_Element(const char* name);//get UI_Element from name
	UI_Element* getUI_Element(int index);//get UI_Element from index
	SkyBox* getSkyBox(const char* name);//get SkyBox from name
	SkyBox* getSkyBox(int index);//get SkyBox from index

	//drawing utility
	int draw();//draws scene to screen

	//state controllers
	int setFullbright(bool state);
	int setSkyBox(int index);
	int setSkyBox(const char* name);
};

//freetype library

#endif