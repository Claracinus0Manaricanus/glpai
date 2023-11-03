#include "B2.h"


/*********************************************************************************/
//SceneManager


//constructors
SceneManager::SceneManager(){
	objects=(GameObject**)malloc(sizeof(GameObject*));
	lights=(Light**)malloc(sizeof(Light*));
	UIElements=(UI_Element**)malloc(sizeof(UI_Element*));
	skyboxes=(SkyBox**)malloc(sizeof(SkyBox*));
}


//destructors
SceneManager::~SceneManager(){
	free(objects);
	free(lights);
	free(UIElements);
	free(skyboxes);
}


//program control
int SceneManager::setPrograms(program* in_pFB, program* in_pL, program* in_pUI,  program* in_pSky){
	pFB[0]=in_pFB[0];
	pFB[1]=in_pFB[1];
	pL[0]=in_pL[0];
	pL[1]=in_pL[1];
	pUI=(*in_pUI);
	pSky=(*in_pSky);
	return 0;
}


//array control
GameObject* SceneManager::addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName, bool useMipmap){
	//resize array
	L_objects++;
	objects=(GameObject**)realloc(objects,sizeof(GameObject*)*L_objects);
	//element creation
	objects[L_objects-1]=new GameObject(inPos,inRot,inSca,inVCount,iVertices,name);
	if(imageFileName!=NULL){
		objects[L_objects-1]->loadTexture(imageFileName,useMipmap);
		objects[L_objects-1]->useColor(false);
	}
	//return newly created element
	return objects[L_objects-1];
}

Light* SceneManager::addLight(const char* name, int iType, vec3 iPos, vec4 iCol){
	//resize array
	L_lights++;
	//element creation
	lights=(Light**)realloc(lights,sizeof(Light*)*L_objects);
	lights[L_lights-1]=new Light(iType,iPos,iCol,name);
	//return newly created element
	return lights[L_lights-1];
}

UI_Element* SceneManager::addUI_Element(const char* name, vec2 iPos, vec2 iScale, const char* filename){
	//resize array
	L_UIElements++;
	UIElements=(UI_Element**)realloc(UIElements,sizeof(UI_Element*)*L_UIElements);
	//element creation
	UIElements[L_UIElements-1]=new UI_Element(iPos,iScale,name);
	if(filename!=NULL)
		UIElements[L_UIElements-1]->loadTexture(filename);
	//return newly created element
	return UIElements[L_UIElements-1];
}

SkyBox* SceneManager::addSkyBox(const char* name, const char* sides[6]){
	//resize array
	L_skyboxes++;
	skyboxes=(SkyBox**)realloc(skyboxes,sizeof(SkyBox*)*L_skyboxes);
	//element creation
	skyboxes[L_skyboxes-1]=new SkyBox(sides,name);
	//return newly created element
	return skyboxes[L_skyboxes-1];
}


//element selector
GameObject* SceneManager::getObject(const char* name, int* index){
	for(int i=0;i<L_objects;i++){
		if(strcmp(objects[i]->NAME,name)==0)
			return objects[i];
	}
	return NULL;
}

GameObject* SceneManager::getObject(int index){
	if(index<L_objects)
		return objects[index];
	return NULL;
}

Light* getLight(const char* name, int* index){
	for(int i=0;i<L_lights;i++){
		if(strcmp(lights[i],name)==0)
			return lights[i];
	}
	return NULL;
}

Light* getLight(int index){
	if(index<L_lights)
		return lights[index];
	return NULL;
}

UI_Element* SceneManager::getUI_Element(const char* name, int* index){
	for(int i=0;i<L_UIElements;i++){
		if(strcmp(UIElements[i]->NAME,name)==0)
			return UIElements[i];
	}
	return NULL;
}

UI_Element* SceneManager::getUI_Element(int index){
	if(index<L_UIElements)
		return UIElements[index];
	return NULL;
}

SkyBox* SceneManager::getSkyBox(const char* name, int* index){
	for(int i=0;i<L_skyboxes;i++){
		if(strcmp(skyboxes[i]->NAME,name)==0)
			return skyboxes[i];
	}
	return NULL;
}

SkyBox* SceneManager::getSkyBox(int index){
	if(index<L_skyboxes)
		return skyboxes[index];
	return NULL;
}


//drawing utility
int SceneManager::draw(){
	glActiveTexture(GL_TEXTURE0);

	//GameObject
	for(int i=0;i<L_objects;i++){
		if(S_FULLBRIGHT){
			if(objects[i]->usingTexture()){
				pFB[1].use();
				pFB[1].setVec3("objRot",objects[i]->rotation);
				pFB[1].setVec3("objMov",objects[i]->position);
			}
			else{
				pFB[0].use();
				pFB[0].setVec3("objRot",objects[i]->rotation);
				pFB[0].setVec3("objMov",objects[i]->position);
			}
		}else{
			if(objects[i]->usingTexture()){
				pL[1].use();
				pL[1].setVec3("objRot",objects[i]->rotation);
				pL[1].setVec3("objMov",objects[i]->position);
			}
			else{
				pL[0].use();
				pL[0].setVec3("objRot",objects[i]->rotation);
				pL[0].setVec3("objMov",objects[i]->position);
			}
		}

		objects[i]->bind();
		glDrawArrays(GL_TRIANGLES,0,objects[i]->getVCount());
		objects[i]->unbind();
	}

	//UI_Element
	pUI.use();
	for(int i=0;i<L_UIElements;i++){
		if(UIElements[i]->isActive()){
			UIElements[i]->bind();
			glDrawArrays(GL_TRIANGLES,0,6);
			UIElements[i]->unbind();
		}
	}

	//SkyBox
	if(C_SKYBOX>=0&&C_SKYBOX<L_skyboxes){//can optimize
		pSky.use();
		skyboxes[C_SKYBOX]->bind();
		glDrawArrays(GL_TRIANGLES,0,36);
		skyboxes[C_SKYBOX]->unbind();
	}

	return 0;
}


//state controllers
int SceneManager::setFullbright(bool state){
	S_FULLBRIGHT=state;
	return 0;
}
int SceneManager::setSkyBox(int index){
	if(index<L_skyboxes){
		C_SKYBOX=index;
		return index;
	}
	return -1;
}

int SceneManager::setSkyBox(const char* name){
	for(int i=0;i<L_skyboxes;i++){
		if(strcmp(skyboxes[i]->NAME,name)==0){
			C_SKYBOX=i;
			return i;
		}
	}
	return -1;
}


/*********************************************************************************/