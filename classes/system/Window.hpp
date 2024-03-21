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

	//destructor
	~Window();

	//getters
	GLFWwindow* getid();
	ivec2 getResolution();
	void getCursorPos(double* xPos, double* yPos);
	bool getKey(int key);//GLFW_PRESS
	bool getKeyR(int key);//GLFW_RELEASE
	int getAxis(int key1, int key2);//key1 +, key2 -

	//setters
	int changeAttrib(int attrib, int value);
	void setInputMode(int mode, int value);
	void setCursorPos(double xPos, double yPos);

	//utility
	int makeContext();
};

#endif