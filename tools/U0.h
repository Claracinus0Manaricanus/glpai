#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <string>
#include "T0.h"


//input utility
int CgetAxis(GLFWwindow* win, int key1, int key2);//custom get axis first key is positive second is negative


//debug features
void logInfo(const char* message);
void logDebug(const char* message);
void logError(const char* message);
void logGreen(const char* message);


//number utility
int cm_rand(int seed);//not tested


//glfw and opengl utility
void setOpenglVersion(int major, int minor, int profile);
void setWindowVars(bool floating, bool resizable);


//file inport
vertex* importOBJ(std::string filename, int& size);//size = element number of array
//importOBJ needs checks at loading to vArr part


#endif