#include "B2.h"


/*********************************************************************************/
//sceneManager


//constructors
sceneManager::sceneManager(){
	objects=(gameObject**)malloc(sizeof(gameObject*));
}


//program control
int sceneManager::setPrograms(program* in_pFB, program* in_pL, program* in_pUI){
	pFB[0]=in_pFB[0];
	pFB[1]=in_pFB[1];
	pL[0]=in_pL[0];
	pL[1]=in_pL[1];
	pUI=(*in_pUI);
	return 0;
}


//array control
int sceneManager::addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName, bool useMipmap){
	L_objects++;
	objects=(gameObject**)realloc(objects,sizeof(gameObject*)*L_objects);
	objects[L_objects-1]=new gameObject(inPos,inRot,inSca,inVCount,iVertices,name);
	if(imageFileName!=NULL){
		objects[L_objects-1]->loadTexture(imageFileName,useMipmap);
		objects[L_objects-1]->useColor(false);
	}
	return 0;
}


//element selector
gameObject* sceneManager::getObject(const char* name){
	for(int i=0;i<L_objects;i++){
		if(strcmp(objects[i]->NAME,name)==0)
			return objects[i];
	}
	return NULL;
}

gameObject* sceneManager::getObject(int index){
	if(index<L_objects)
		return objects[index];
	return NULL;
}


//drawing utility
int sceneManager::draw(){
	for(int i=0;i<L_objects;i++){
		if(objects[i]->usingTexture())
			pL[1].use();
		else
			pL[0].use();

		objects[i]->bind();
		glDrawArrays(GL_TRIANGLES,0,objects[i]->getVCount());
		objects[i]->unbind();
	}
	return 0;
}


//debugging
gameObject** sceneManager::getObjects(){
	return objects;
}


//destructors
sceneManager::~sceneManager(){
	delete[] objects;
	delete[] lights;
}


/*********************************************************************************/