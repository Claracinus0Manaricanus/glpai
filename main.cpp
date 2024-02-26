#include <cstdio>
#include <math.h>
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "classes/system/Window.hpp"
#include "classes/system/Image.hpp"
#include "classes/system/U0.hpp"
#include "classes/graphics/CMGL_Program.hpp"
#include "classes/opengl/CMGL_GameObject.hpp"
#include "classes/opengl/CMGL_Renderer.hpp"
#include "classes/opengl/CMGL_Camera.hpp"

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


	//Setting up opengl (should be carried to GL related scene manager)
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
	MeshData impOBJData=importOBJ("objects/torus.obj");

	CMGL_GameObject impOBJ(impOBJData, {{0,0,0},{0,0,0},{1,1,1}});
	impOBJ.loadTexture(texDen);
	
	CMGL_Program sprg("shaders/imgV/vert.sha", "shaders/imgV/frag.sha");
	sprg.setInt("T0", 0);//also calls sprg.use()

	CMGL_Renderer mainRenderer;
	

	/*while loop variables*/
	bool cursor=false,escAllow=true;
	int frame=0;//frame counter (resets per second)
	float totalTime=0,deltaTime=0,printCheck=0;//time related
	double cursorX=0,cursorY=0;//cursor input
	CMGL_Camera mainCam(120, 1);
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

		//clearing screen and rendering
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		mainCam.bind();
		mainRenderer.renderGenericArray(&impOBJ, impOBJ.getVCount(), sprg);

		//input from keyboard (camera movement)
		if(glfwGetKey(mainWin.getid(), GLFW_KEY_W) == GLFW_PRESS){
			mainCam.moveForward(1*deltaTime);
		}else if(glfwGetKey(mainWin.getid(), GLFW_KEY_S) == GLFW_PRESS){
			mainCam.moveForward(-1*deltaTime);
		}
		if(glfwGetKey(mainWin.getid(), GLFW_KEY_D) == GLFW_PRESS){
			mainCam.moveForward(1*deltaTime, 3.14159265f/2.0f);
		}else if(glfwGetKey(mainWin.getid(), GLFW_KEY_A) == GLFW_PRESS){
			mainCam.moveForward(-1*deltaTime, 3.14159265f/2.0f);
		}
		if(glfwGetKey(mainWin.getid(), GLFW_KEY_E) == GLFW_PRESS){
			mainCam.move({0, 1*deltaTime, 0});
		}else if(glfwGetKey(mainWin.getid(), GLFW_KEY_Q) == GLFW_PRESS){
			mainCam.move({0, -1*deltaTime, 0});
		}

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

			//use cursor input for camera rotation
			glfwGetCursorPos(mainWin.getid(), &cursorX, &cursorY);
			mainCam.rotate({(float)cursorY * 0.001f, (float)cursorX * 0.001f, 0});

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

/* 2024-02-26 / 20:33:40
==48968== 
==48968== HEAP SUMMARY:
==48968==     in use at exit: 807,188 bytes in 3,007 blocks
==48968==   total heap usage: 153,869 allocs, 150,862 frees, 22,299,294 bytes allocated
==48968== 
==48968== LEAK SUMMARY:
==48968==    definitely lost: 41,300 bytes in 4 blocks
==48968==    indirectly lost: 0 bytes in 0 blocks
==48968==      possibly lost: 497,664 bytes in 1 blocks
==48968==    still reachable: 268,224 bytes in 3,002 blocks
==48968==         suppressed: 0 bytes in 0 blocks
==48968== Rerun with --leak-check=full to see details of leaked memory
==48968== 
==48968== For lists of detected and suppressed errors, rerun with: -s
==48968== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
*/