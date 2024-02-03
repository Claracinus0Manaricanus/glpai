#include <cstdio>
#include <math.h>
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "classes/system/Window.hpp"
#include "classes/system/Image.hpp"
#include "classes/system/U0.hpp"
#include "classes/graphics/CMGL_Program.h"
#include "classes/opengl/CMGL_GameObject.hpp"

using namespace std;

const char* LICENSE="GLPAI  Copyright (C) 2023-2024  Sarp Akkaya\n"
"This program comes with ABSOLUTELY NO WARRANTY.\n"
"This is free software, and you are welcome to redistribute it under certain conditions.\n";

int main(int argc, char** argv){
	printf("%s\n",LICENSE);
	printf("\033[0;36mHello, please wait while i start!\n\n");

	//enable debug
	bool debug=true;
	if(debug)logInfo("Debug enabled\n");


	/******************************************************************************************/
	//glfw initialization


	if(!glfwInit()){
		logError("glfw failed to initialize!\n");
		return -1;
	}if(debug)logInfo("GLFW initialized\n");


	/******************************************************************************************/
	//window creation

	WindowData winData;
	winData.openglProfile=GLFW_OPENGL_CORE_PROFILE;

	Window mainWin(winData);
	if(!mainWin.getid()){
		printf("window init failed!\n");
		glfwTerminate();
		return 1;
	}

	mainWin.changeAttrib(GLFW_RESIZABLE, true);


	/*resolution******************************************************************************************/
	//opengl context


	mainWin.makeContext();//check
	if(debug)logInfo("opengl context set\n");
	if(GLEW_OK!=glewInit()){
		logError("glew failed to initialize!\n");
		glfwTerminate();
		return -1;
	}
	if(debug)logInfo("glew initialized\n");


	//Setting up opengl
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glViewport(0, 0, winData.resolution.x, winData.resolution.y);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);

	glFrontFace(GL_CW);//clockwise winding
	glDepthFunc(GL_LEQUAL);//depth test pass condition (LEQUAL=less or equal)
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//blend coefficients
	glBlendEquationSeparate(GL_FUNC_ADD,GL_MAX);

	
	/******************************************************************************************/
	//glfw settings


	glfwSwapInterval(1);//synchronizing framerate

	//initalizing mouse
	glfwSetInputMode(mainWin.getid(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	/******************************************************************************************/
	//main loop preparations

	TextureData texDen;
	texDen.imageFile="BadAppleFrames/245.png";

	Vertex vData[4]={
//		position    normal   color     UV
		{{-1,-1, 0},{0,0,0},{1,1,1,1},{0,1}},
		{{-1, 1, 0},{0,0,0},{1,1,1,1},{0,0}},
		{{ 1, 1, 0},{0,0,0},{1,1,1,1},{1,0}},
		{{ 1,-1, 0},{0,0,0},{1,1,1,1},{1,1}},
	};

	uint32_t faces[6]={
		0,1,2,2,3,0
	};

	CMGL_GameObject denOBJ({4,vData,2,faces}, {{0,0,0},{0,0,0},{1,1,1}});
	denOBJ.loadTexture(texDen);
	
	CMGL_Program sprg("shaders/imgV/vert.sha", "shaders/imgV/frag.sha");
	

	/*while loop variables*/
	bool cursor=false,escAllow=true;
	int frame=0;//frame counter (resets per second)
	float totalTime=0,deltaTime=0,printCheck=0;//time related
	double cursorX=0,cursorY=0;//cursor input
	/*while loop variables*/
	

	/******************************************************************************************/
	//main loop
	glfwSetTime(0);
	while(!glfwWindowShouldClose(mainWin.getid())){
		//getting time between frames and increasing total time
		deltaTime=glfwGetTime();
		glfwSetTime(0);
		totalTime+=deltaTime;
		printCheck+=deltaTime;


		//updating resolution
		winData.resolution=mainWin.getResolution();
		glViewport(0, 0, winData.resolution.x, winData.resolution.y);


		//getting framerate
		frame++;
		if(printCheck>=1){
			printf("FPS: %d\n", frame);
			frame=0;
			printCheck=0;
		}
		//change debugging system to optional

		//clearing screen
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		denOBJ.bind();
		sprg.setInt("T0", 0);//also calls sprg.use()
		glDrawElements(GL_TRIANGLES,denOBJ.getFCount()*3,GL_UNSIGNED_INT,(void*)0);


		//toggle cursor
		if(glfwGetKey(mainWin.getid(),GLFW_KEY_ESCAPE)==GLFW_PRESS&&escAllow){
			//cursor variables
			cursor=!cursor;
			if(debug){
				logInfo("KEY_ESCAPE detected changing cursor mode\n");
			}
			escAllow=false;
		}else if(glfwGetKey(mainWin.getid(),GLFW_KEY_ESCAPE)==GLFW_RELEASE){
			//for snappier feel
			escAllow=true;
		}


		//cursor capture
		if(!cursor){
			//hide cursor
			glfwSetInputMode(mainWin.getid(),GLFW_CURSOR,GLFW_CURSOR_DISABLED);
			if(!escAllow)
				glfwSetCursorPos(mainWin.getid(),0,0);

			//reset cursor position
			glfwSetCursorPos(mainWin.getid(),0,0);
		}else{
			//make cursor visible
			glfwSetInputMode(mainWin.getid(),GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}


		//polling events and displaying back buffer
		glfwPollEvents();
		glfwSwapBuffers(mainWin.getid());
	}


	/******************************************************************************************/
	//termination


	if(debug)printf("\n");
	if(debug)logInfo("Terminating\n");
	glfwDestroyWindow(mainWin.getid());
	glfwTerminate();
	if(debug)printf("\033[0;32mINFO:\033[0;36mProgram ran for \033[0;35m%f\033[0;36m seconds!\n",totalTime);//change this
	printf("\nSee ya later!\n");
	return 0;
}

/*
general debug colors:
- yellow: debug notify
- red: debug error
- green: task done
- cyan: information
- purple: number
*/

/*
2023-06-22 / 00:32
==9191== 				LEAK SUMMARY:
==9191==    definitely lost: 1,080 bytes in 23 blocks
==9191==    indirectly lost: 16,412 bytes in 97 blocks
==9191==      possibly lost: 0 bytes in 0 blocks
==9191==    still reachable: 87,083 bytes in 913 blocks
==9191==         suppressed: 0 bytes in 0 blocks
*/

/*
2023-11-07 / 06:38
==38370== HEAP SUMMARY:
==38370==     in use at exit: 56,306 bytes in 639 blocks
==38370==   total heap usage: 3,275 allocs, 2,636 frees, 228,022 bytes allocated
==38370== 
==38370== LEAK SUMMARY:
==38370==    definitely lost: 0 bytes in 0 blocks
==38370==    indirectly lost: 0 bytes in 0 blocks
==38370==      possibly lost: 0 bytes in 0 blocks
==38370==    still reachable: 56,306 bytes in 639 blocks
==38370==         suppressed: 0 bytes in 0 blocks
==38370== Rerun with --leak-check=full to see details of leaked memory
*/