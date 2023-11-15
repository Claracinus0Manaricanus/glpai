#include "Window.h"

//constructor
window::window(ivec2 resolution, const char* name){
	ID=glfwCreateWindow(resolution.x,resolution.y,name,NULL,NULL);
}


//extractor
GLFWwindow* window::getid(){
	return ID;
}


//utility
int window::changeAttrib(int attrib, int value){
	glfwSetWindowAttrib(ID,attrib,value);
	return 0;
}//error check needed

ivec2 window::getResolution(){
	ivec2 temp;
	glfwGetFramebufferSize(ID,&temp.x,&temp.y);
	return temp;
}