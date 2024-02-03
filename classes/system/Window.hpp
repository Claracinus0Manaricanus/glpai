#ifndef CMGLFW_WINDOW
#define CMGLFW_WINDOW

#include <GLFW/glfw3.h>
#include "T0.hpp"

class Window{
private:
	GLFWwindow* ID;

public:
	//constructor
	Window(WindowData inputData);

	//getters
	GLFWwindow* getid();
	ivec2 getResolution();

	//setters
	int changeAttrib(int attrib, int value);
	//int setResolution(int x, int y);//not implemented do not use

	//utility
	int makeContext();
};

#endif