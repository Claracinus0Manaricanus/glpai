#include "Window.hpp"

//constructor
Window::Window(WindowData inputData){
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, inputData.openglVersionMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, inputData.openglVersionMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, inputData.openglProfile);
	
	glfwWindowHint(GLFW_FLOATING, true);
	glfwWindowHint(GLFW_RESIZABLE, false);
	
	ID=glfwCreateWindow(inputData.resolution.x, inputData.resolution.y, inputData.name, NULL, NULL);
}


//destructor
Window::~Window(){
	glfwDestroyWindow(ID);
}


//getters
GLFWwindow* Window::getid(){
	return ID;
}

ivec2 Window::getResolution(){
	ivec2 temp;
	glfwGetFramebufferSize(ID, &temp.x, &temp.y);
	return temp;
}

bool Window::getKey(int key){
	if(glfwGetKey(ID, key) == GLFW_PRESS){
		return true;
	}

	return false;
}

bool Window::getKeyR(int key){
	if(glfwGetKey(ID, key) == GLFW_RELEASE){
		return true;
	}

	return false;
}

int Window::getAxis(int key1, int key2){
	if(glfwGetKey(ID, key1) == GLFW_PRESS){
		return 1;
	}else if(glfwGetKey(ID, key2) == GLFW_PRESS){
		return -1;
	}

	return 0;
}


//setters
int Window::changeAttrib(int attrib, int value){
	glfwSetWindowAttrib(ID, attrib, value);
	return 0;
}//error check needed


//utility
int Window::makeContext(){
	glfwMakeContextCurrent(ID);
	return 0;
}