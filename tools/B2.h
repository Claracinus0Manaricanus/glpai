#ifndef B2_H
#define B2_H

#include "B1.h"
#include "R0.h"

class SceneManager{
protected:
	//state identifiers and contants
	bool S_FULLBRIGHT=false;
	int C_SKYBOX=-1;//-1 means no skybox otherwise index of skybox to use
	int C_LightTypes=2;
	//data holders L_ means array length of
	int L_objects=0;
	GameObject** objects=NULL;
	int L_lights=0;
	Light** lights=NULL;
	int L_UIElements=0;
	UI_Element** UIElements=NULL;
	int L_skyboxes=0;
	SkyBox** skyboxes=NULL;
	//depth buffers (for lights)
	uint32_t cubeDepthMap;
	//programs
	program pFB[1];//perspective fullbright
	program pL[2];//perspective light //point 0, directional 1
	program pSky;//skybox renderer
	program pUI;//UI_Element renderer
	program shadowMap;//shadowMap calculator (point light)

public:
	//constructors
	SceneManager();

	//destructor
	~SceneManager();

	//program control
	int setPrograms(program* in_pFB, program* in_pL, program* in_pUI,  program* in_pSky);

	//array control
	GameObject* addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName=NULL, bool useMipmap=false);
	Light* addLight(const char* name, int iType, vec3 iPos, vec4 iCol);
	UI_Element* addUI_Element(const char* name, vec2 iPos, vec2 iScale, const char* filename);
	SkyBox* addSkyBox(const char* name, const char* sides[6]);

	//element selector
	GameObject* getObject(const char* name, int* index=NULL);//get GameObject from name
	GameObject* getObject(int index);//get GameObject from index
	Light* getLight(const char* name, int* index=NULL);//get Light from name
	Light* getLight(int index);//get Light from index
	UI_Element* getUI_Element(const char* name, int* index=NULL);//get UI_Element from name
	UI_Element* getUI_Element(int index);//get UI_Element from index
	SkyBox* getSkyBox(const char* name, int* index=NULL);//get SkyBox from name
	SkyBox* getSkyBox(int index);//get SkyBox from index

	//element deletors WIP
	int deleteObject(const char* name);
	int deleteObject(uint32_t index);
	int deleteLight(const char* name);
	int deleteLight(int index);
	int deleteUI_Element(const char* name);
	int deleteUI_Element(int index);
	int deleteSkyBox(const char* name);
	int deleteSkyBox(int index);

	//drawing utility
	int draw(vec3 camPos, vec3 camRot, vec2int resolution);//draws scene to screen

	//state controllers
	int setFullbright(bool state);
	int setSkyBox(int index);
	int setSkyBox(const char* name);
};

//freetype library

#endif