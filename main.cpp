#include <cstdio>
#include <math.h>
#include <string>
#include <fstream>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tools/T0.h"
#include "tools/SceneManager.h"
#include "tools/Window.h"
#include "tools/Camera.h"
#include "tools/U0.h"

#include <time.h>

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


	//opengl specifications
	setOpenglVersion(4,5,GLFW_OPENGL_CORE_PROFILE);//major, minor, profile
	setWindowVars(true,true);//floating, resizable
	if(debug)logInfo("Using opengl \033[0;35m4.5\033[0;36m core\n");
	//todo: Check version compatability


	/******************************************************************************************/
	//window creation


	/*window vars*/
	ivec2 resolution={800,600};
	/*window vars*/

	//creating window
	window w0(resolution,"pai");
	if(!w0.getid()){
		logError("Window creation failed! Error code:");
		printf("&d\n",stderr);
		glfwTerminate();
		return -1;
	}if(debug)logInfo("window created\n");


	/******************************************************************************************/
	//opengl context


	glfwMakeContextCurrent(w0.getid());//check
	if(debug)logInfo("opengl context set\n");
	if(GLEW_OK!=glewInit()){
		logError("glew failed to initialize!\n");
		glfwTerminate();
		return -1;
	}if(debug)logInfo("glew initialized\n");


	//Setting up opengl
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glViewport(0,0,resolution.x,resolution.y);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	//glEnable(GL_COLOR_LOGIC_OP);

	glFrontFace(GL_CW);//clockwise winding
	glDepthFunc(GL_LEQUAL);//depth test pass condition (LEQUAL=less or equal)
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//blend coefficients
	glBlendEquationSeparate(GL_FUNC_ADD,GL_MAX);

	
	/******************************************************************************************/
	//glfw settings


	glfwSwapInterval(0);//synchronizing framerate

	//initalizing mouse
	glfwSetInputMode(w0.getid(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

	/******************************************************************************************/
	//shaders
	//this part has been carried to SceneManager
	
	/******************************************************************************************/
	//sceneManager setup and objects
	SceneManager mainManager;

	//constructing data structure for ground
	objectData tmpData;
	MeshData tmpMesh;//for cleanup since calculateNormals() doesnt

	tmpData.trData={{0,0,0},{0,0,0},{0.1f,0.03f,0.1f}};//position, rotation, scale

	tmpMesh = importHeightMap("BadAppleFrames/001.png", 1.0f);
	tmpData.mData = tmpMesh;
	tmpData.mData = calculateNormals(&tmpData.mData);
		
	free(tmpMesh.vertices);
	tmpMesh.vertices = NULL;
	free(tmpMesh.faces);
	tmpMesh.faces = NULL;

	tmpData.texData.imageFile=NULL;
	tmpData.texData.useMipmap=false;

	GameObject* terrainOBJ = mainManager.addObject("terrain",&tmpData);


	//ui elements
	/*TextureData tmpTexData;
	tmpTexData.imageFile="images/utility/paused.png";
	tmpTexData.useMipmap=false;
	UI_Element* pauseMenu=mainManager.addUI_Element("pauseScreen",{0,0},{1,1},&tmpTexData);
	pauseMenu->setActive(false);*/

	//skyboxes
	const char* sides[6]={
		"images/skybox/starryCSky/px.png",//X+
		"images/skybox/starryCSky/nx.png",//X-
		"images/skybox/starryCSky/py.png",//Y+
		"images/skybox/starryCSky/ny.png",//Y-
		"images/skybox/starryCSky/pz.png",//Z+
		"images/skybox/starryCSky/nz.png" //Z-
	};
	mainManager.addSkyBox("stars",sides);
	mainManager.setSkyBox("stars");
	

	/******************************************************************************************/
	//lights


	//mainManager.addLight("mainL",0,{0,20,0},{1,1,1,50});
	vec3 lData[1]={0,1,0};
	mainManager.addLight("direct",1,{1,1,1,1},lData);


	/******************************************************************************************/
	//main loop preparations
	

	/*while loop variables*/
	bool cursor=false,escAllow=true;
	int frame=0, BAFrameCount = 1, BAInit = 0;//frame counter (resets per second)
	string BAFrameName = "";
	bool BAPaused = true;
	float totalTime=0,deltaTime=0,printCheck=0,BACheck=0;//time related
	double cursorX=0,cursorY=0;//cursor input
	Camera cam0(60);//main camera
	
	/*while loop variables*/
	cam0.move({20,25,-1});


	/******************************************************************************************/
	//main loop

	glfwSetTime(0);
	while(!glfwWindowShouldClose(w0.getid())){
		//getting time between frames and increasing total time
		deltaTime=glfwGetTime();
		glfwSetTime(0);
		totalTime+=deltaTime;
		printCheck+=deltaTime;
		BACheck+=deltaTime;


		//updating resolution
		resolution=w0.getResolution();
		glViewport(0,0,resolution.x,resolution.y);
		cam0.setAspectRatio((float)resolution.x/resolution.y);


		//getting framerate
		frame++;
		if(printCheck>=1){
			//cursor position set
			printf("\nFPS=\033[0;35m%i\033[0;36m\n"
			"totalTime:\033[0;35m%f\033[0;36m\n"
			"deltaTime:\033[0;35m%f\033[0;36m\n"
			"camPos= x:\033[0;35m%f\033[0;36m y:\033[0;35m%f\033[0;36m z:\033[0;35m%f\033[0;36m\n"
			"camRot= x:\033[0;35m%f\033[0;36m y:\033[0;35m%f\033[0;36m z:\033[0;35m%f\033[0;36m\n"
			,frame,totalTime,deltaTime,cam0.position.x,cam0.position.y,cam0.position.z,
			cam0.rotation.x,cam0.rotation.y,cam0.rotation.z);
			frame=0;
			printCheck=0;
		}
		//change debugging system to optional
		
		//update BadAppleFrame 24fps
		if(BACheck >= 1.0f/20.0f && !BAPaused){
			if(BAInit == 0){
				system("screen -dmS exec ffplay -nodisp BadApple.mp4");
				totalTime = 0;
				glfwSetTime(0);
			}

			//free memory
			free(tmpMesh.vertices);
			tmpMesh.vertices = NULL;
			free(tmpMesh.faces);
			tmpMesh.faces = NULL;
			free(tmpData.mData.vertices);
			tmpData.mData.vertices = NULL;

			//setting frameCount
			BAFrameCount = totalTime * 24.0f;
			if(BAFrameCount > 5260)BAFrameCount=5259;

			//importing
			BAFrameName.clear();
			BAFrameName += "BadAppleFrames/";
			if(BAFrameCount < 10)BAFrameName += "00";
			else if(BAFrameCount < 100)BAFrameName += "0";
			BAFrameName += to_string(BAFrameCount);
			BAFrameName += ".png";
			
			tmpMesh = importHeightMap(BAFrameName.c_str(), 1.0f, 2);
			tmpData.mData = tmpMesh;
			tmpData.mData = calculateNormals(&tmpData.mData);

			terrainOBJ->setMesh(&tmpData.mData);

			printf(
			"BAFrameCount = %d\n"
			"BAFrameName = %s\n"
			,BAFrameCount,BAFrameName.c_str());

			BACheck = 0;
			BAInit = 1;
		}else if(BAPaused){
			BACheck = 0;
		}

		if(glfwGetKey(w0.getid(),GLFW_KEY_SPACE)==GLFW_PRESS){
			BAPaused = true;
		}else if(glfwGetKey(w0.getid(),GLFW_KEY_X)==GLFW_PRESS){
			BAPaused = false;
		}

		//clearing screen
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


		//toggle cursor
		if(glfwGetKey(w0.getid(),GLFW_KEY_ESCAPE)==GLFW_PRESS&&escAllow){
			//cursor variables
			cursor=!cursor;
			if(debug){
				logInfo("KEY_ESCAPE detected changing cursor mode\n");
			}
			escAllow=false;
		}else if(glfwGetKey(w0.getid(),GLFW_KEY_ESCAPE)==GLFW_RELEASE){
			//for snappier feel
			escAllow=true;
		}


		//cursor capture
		if(!cursor){
			//hide cursor
			glfwSetInputMode(w0.getid(),GLFW_CURSOR,GLFW_CURSOR_DISABLED);
			if(!escAllow)
				glfwSetCursorPos(w0.getid(),0,0);	

			//mouse input for roty (cursor position of the current frame)
			glfwGetCursorPos(w0.getid(),&cursorX,&cursorY);

			//update rot
			cam0.rotate({(float)cursorY*deltaTime,(float)cursorX*deltaTime,0});

			//movement variable updates (add the trig functions)
			cam0.moveForward(CgetAxis(w0.getid(),GLFW_KEY_W,GLFW_KEY_S)*deltaTime*2);
			cam0.moveRight(CgetAxis(w0.getid(),GLFW_KEY_D,GLFW_KEY_A)*deltaTime*2);
			cam0.moveUp(CgetAxis(w0.getid(),GLFW_KEY_E,GLFW_KEY_Q)*deltaTime*2);

			//reset cursor position
			glfwSetCursorPos(w0.getid(),0,0);
		}else{
			//make cursor visible
			glfwSetInputMode(w0.getid(),GLFW_CURSOR,GLFW_CURSOR_NORMAL);
		}
		

		//drawing to back buffer
		//mainManager.setFullbright(1);
		mainManager.draw(&cam0, resolution);


		//polling events and displaying back buffer
		glfwPollEvents();
		glfwSwapBuffers(w0.getid());
	}


	/******************************************************************************************/
	//termination


	if(debug)printf("\n");
	if(debug)logInfo("Terminating\n");
	glfwDestroyWindow(w0.getid());
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