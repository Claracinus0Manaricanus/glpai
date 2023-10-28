#include "B2.h"


/*********************************************************************************/
//SceneManager


//constructors
SceneManager::SceneManager(){
	lights=(Light**)malloc(sizeof(Light*));
	objects=(GameObject**)malloc(sizeof(GameObject*));
	UIElements=(UI_Element**)malloc(sizeof(UI_Element*));
}


//destructors
SceneManager::~SceneManager(){
	free(objects);
	free(lights);
	free(UIElements);
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
GameObject* SceneManager::addObject(const char* name, vec3 inPos, vec3 inRot, vec3 inSca, int inVCount, vertex* iVertices, const char* imageFileName, bool useMipmap){
	L_objects++;
	objects=(GameObject**)realloc(objects,sizeof(GameObject*)*L_objects);
	objects[L_objects-1]=new GameObject(inPos,inRot,inSca,inVCount,iVertices,name);
	if(imageFileName!=NULL){
		objects[L_objects-1]->loadTexture(imageFileName,useMipmap);
		objects[L_objects-1]->useColor(false);
	}
	return objects[L_objects-1];
}

UI_Element* SceneManager::addUI_Element(const char* name, vec2 iPos, vec2 iScale, const char* filename){
	L_UIElements++;
	UIElements=(UI_Element**)realloc(UIElements,sizeof(UI_Element*)*L_UIElements);
	UIElements[L_UIElements-1]=new UI_Element(iPos,iScale,name);
	if(filename!=NULL)
		UIElements[L_UIElements-1]->loadTexture(filename);
	return UIElements[L_UIElements-1];
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

UI_Element* SceneManager::getUI_Element(const char* name){
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

	pUI.use();
	for(int i=0;i<L_UIElements;i++){
		if(UIElements[i]->isActive()){
			UIElements[i]->bind();
			glDrawArrays(GL_TRIANGLES,0,6);
			UIElements[i]->unbind();
		}
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