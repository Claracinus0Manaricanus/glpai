#include "B2.h"


/*********************************************************************************/
//SceneManager


//constructors
SceneManager::SceneManager(){
	objects=(GameObject**)malloc(sizeof(GameObject*));
}


//destructors
SceneManager::~SceneManager(){
	free(objects);
	free(lights);
}


//program control
int SceneManager::setPrograms(program* in_pFB, program* in_pL, program* in_pUI){
	pFB[0]=in_pFB[0];
	pFB[1]=in_pFB[1];
	pL[0]=in_pL[0];
	pL[1]=in_pL[1];
	pUI=(*in_pUI);
	return 0;
}


//array control
int SceneManager::addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName, bool useMipmap){
	L_objects++;
	objects=(GameObject**)realloc(objects,sizeof(GameObject*)*L_objects);
	objects[L_objects-1]=new GameObject(inPos,inRot,inSca,inVCount,iVertices,name);
	if(imageFileName!=NULL){
		objects[L_objects-1]->loadTexture(imageFileName,useMipmap);
		objects[L_objects-1]->useColor(false);
	}
	return (L_objects-1);
}


//element selector
GameObject* SceneManager::getObject(const char* name){
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


//drawing utility
int SceneManager::draw(){
	for(int i=0;i<L_objects;i++){
		if(S_FULLBRIGHT){
			if(objects[i]->usingTexture())
				pFB[1].use();
			else
				pFB[0].use();
		}else{
			if(objects[i]->usingTexture())
				pL[1].use();
			else
				pL[0].use();
		}

		objects[i]->bind();
		glDrawArrays(GL_TRIANGLES,0,objects[i]->getVCount());
		objects[i]->unbind();
	}
	return 0;
}


//state controllers
int SceneManager::setFullbright(bool state){
	S_FULLBRIGHT=state;
	return 0;
}


//debugging
GameObject** SceneManager::getObjects(){
	return objects;
}


/*********************************************************************************/