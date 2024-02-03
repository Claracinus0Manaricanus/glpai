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


//getters
GLFWwindow* Window::getid(){
	return ID;
}

ivec2 Window::getResolution(){
	ivec2 temp;
	glfwGetFramebufferSize(ID, &temp.x, &temp.y);
	return temp;
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