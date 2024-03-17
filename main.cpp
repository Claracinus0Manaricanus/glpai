#include <cstdio>
#include <math.h>
#include <string>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "classes/system/Window.hpp"
#include "classes/system/U0.hpp"
#include "classes/opengl/CMGL_Renderer.hpp"
#include "classes/opengl/CMGL_Camera.hpp"
#include "classes/opengl/CMGL_CubeMap.hpp"
#include "classes/opengl/CMGL_Framebuffer.hpp"
#include "classes/opengl/CMGL_DirectLight.hpp"
#include "include/Client.hpp"

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
	winData.openglProfile = GLFW_OPENGL_CORE_PROFILE;
	winData.resolution.x = 1280;
	winData.resolution.y = 720;

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


	glfwSwapInterval(0);//synchronizing framerate

	//initalizing mouse
	glfwSetInputMode(mainWin.getid(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	/******************************************************************************************/
	//main loop preparations

	//objects
	int objectsCount = 3;
	CMGL_GameObject* objects = new CMGL_GameObject[objectsCount];

	//data
	//plane
	ObjectData OBJData;
	OBJData.trData = {{0,0,0}, {-PI/2.0f,0,0}, {100,100,1}};
	OBJData.mData = importOBJ("objects/plane.obj");
	objects[0].loadData(OBJData);
	free(OBJData.mData.vertices);

	//tree
	OBJData.trData = {{-10,0,10}, {0,0,0}, {1,1,1}};
	OBJData.mData = importOBJ("objects/environment/Treemsi.obj");
	Image treeImg({"images/environment/treemsi.png",3,1});
	OBJData.texData = {0, treeImg.width(), treeImg.height(), GL_TEXTURE_2D, GL_RGB, GL_UNSIGNED_BYTE, GL_REPEAT, GL_LINEAR, treeImg.getDataP()};
	objects[1].loadData(OBJData);
	
	OBJData.trData = {{10,0,10}, {0,0,0}, {1,1,1}};
	objects[2].loadData(OBJData);
	free(OBJData.mData.vertices);


	//dhader programs
	CMGL_Program sprg("shaders/perspective(L)/directional/vert.sha", "shaders/perspective(L)/directional/frag.sha");
	sprg.setInt("T0", 0);//also calls sprg.use()
	sprg.setInt("shadowMap", 1);

	CMGL_Program skyBoxPrg("shaders/perspective(FB)/skybox/vert.sha","shaders/perspective(FB)/skybox/frag.sha");
	skyBoxPrg.setInt("tex0", 0);

	CMGL_Program UI_Out("shaders/orthographic/postProcess/vert.sha","shaders/orthographic/postProcess/frag.sha");
	UI_Out.setInt("tex0", 0);

	CMGL_Program shadowMapPRG("shaders/perspective(L)/ShadMapD/vert.sha","shaders/perspective(L)/ShadMapD/frag.sha");

	CMGL_Renderer mainRenderer;

	//render plane
	ObjectData renderPlaneOBJ;
	renderPlaneOBJ.mData = importOBJ("objects/plane.obj");
	CMGL_GameObject renderPlane(renderPlaneOBJ);
	free(renderPlaneOBJ.mData.vertices);

	//cubeMap
	CubeMapData cbDat;
	cbDat.sides[0]="images/skybox/starryCSky/px.png";
	cbDat.sides[1]="images/skybox/starryCSky/nx.png";
	cbDat.sides[2]="images/skybox/starryCSky/py.png";
	cbDat.sides[3]="images/skybox/starryCSky/ny.png";
	cbDat.sides[4]="images/skybox/starryCSky/pz.png";
	cbDat.sides[5]="images/skybox/starryCSky/nz.png";

	CMGL_CubeMap cubeMap(cbDat);
	cubeMap.bind();
	
	ObjectData cubeData;
	cubeData.trData = {{0,0,0},{0,0,0},{1,1,1}};

	cubeData.mData=importOBJ("objects/cube.obj");
	CMGL_GameObject cubeMapsCube(cubeData);
	free(cubeData.mData.vertices);

	//lights
	DirectLightData lightData;
	lightData.color = {1,1,1,0.5f};
	//lightData.direction = {0.5f,1,0.2f};
	lightData.direction = {0.5f,1,1};
	CMGL_DirectLight denLight0(lightData);

	lightData.color = {1,1,1,0.5f};
	lightData.direction = {-0.5f,1,1};
	CMGL_DirectLight denLight1(lightData);


	//framebuffer
	uint32_t FBWidth = winData.resolution.x;
	uint32_t FBHeight = winData.resolution.y;
	CMGL_Texture depthBuffer({0, FBWidth, FBHeight, GL_TEXTURE_2D, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, GL_CLAMP_TO_BORDER, GL_LINEAR, NULL});
	CMGL_Texture colorBuffer({0, FBWidth, FBHeight, GL_TEXTURE_2D, GL_RGBA, GL_UNSIGNED_BYTE, GL_CLAMP_TO_BORDER, GL_LINEAR, NULL});

	CMGL_Framebuffer renderFB({GL_FRAMEBUFFER});
	renderFB.setColorAttachment(colorBuffer.getid());
	renderFB.setDepthAttachment(depthBuffer.getid());

	//light depth framebuffer
	CMGL_Texture lightDepthBuffer({1, 2048, 2048, GL_TEXTURE_2D, GL_DEPTH_COMPONENT, GL_FLOAT, GL_CLAMP_TO_BORDER, GL_LINEAR, NULL});
	float tempDepthColor[4]={1,1,1,1};
	lightDepthBuffer.bind();
	glTexParameterfv(GL_TEXTURE_2D,  GL_TEXTURE_BORDER_COLOR, tempDepthColor);
	lightDepthBuffer.unbind();
	CMGL_Framebuffer lightFB({GL_FRAMEBUFFER});
	lightFB.setDepthAttachment(lightDepthBuffer.getid());


	/********************************************/
	renderPlane.loadTexture(colorBuffer);

	/*while loop variables*/
	bool cursor=false,escAllow=true;
	int frame=0;//frame counter (resets per second)
	float totalTime=0,deltaTime=0,printCheck=0;//time related
	double cursorX=0,cursorY=0;//cursor input
	CMGL_Camera mainCam(120, 1);
	mainCam.setAspectRatio((float)FBWidth/FBHeight);
	mainCam.setPosition({0,1,0});
	float camSpeed = 5.0f;
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
		glViewport(0, 0, FBWidth, FBHeight);


		//getting framerate
		frame++;
		if(printCheck>=1){
			printf("FPS: %d\n", frame);
			frame=0;
			printCheck=0;

			sendClearTo(connectTo("127.0.0.1", 8080));
			sendCoordinateTo(connectTo("127.0.0.1", 8080), mainCam.getPosition().x, mainCam.getPosition().z, 255, 255, 0);
			sendDrawTo(connectTo("127.0.0.1", 8080));
			
			printf("camx: %f  camy: %f  camz: %f\n",mainCam.getPosition().x, mainCam.getPosition().y, mainCam.getPosition().z);
		}

		//light pass
		glViewport(0, 0, 2048, 2048);
		lightFB.bind();
		glClear(GL_DEPTH_BUFFER_BIT);
		denLight0.bindAsCam();
		mainRenderer.renderGameObjectsA(objects, objectsCount, shadowMapPRG);

		//render pass
		glViewport(0, 0, FBWidth, FBHeight);
		renderFB.bind();
		lightDepthBuffer.bind();

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		mainCam.bind();
		denLight0.bind();
		glFrontFace(GL_CW);
		mainRenderer.renderGameObjectsA(objects, objectsCount, sprg);

		//light pass
		glViewport(0, 0, 2048, 2048);
		lightFB.bind();
		glClear(GL_DEPTH_BUFFER_BIT);
		denLight1.bindAsCam();
		mainRenderer.renderGameObjectsA(objects, objectsCount, shadowMapPRG);

		//render pass
		glViewport(0, 0, FBWidth, FBHeight);
		renderFB.bind();
		lightDepthBuffer.bind();

		mainCam.bind();
		denLight1.bind();
		glFrontFace(GL_CW);
		glBlendFunc(GL_ONE,GL_ONE);
		mainRenderer.renderGameObjectsA(objects, objectsCount, sprg);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);


		//skybox /*****************************/
		glFrontFace(GL_CCW);
		mainRenderer.renderGenericArray(&cubeMapsCube, cubeMapsCube.getVCount(), skyBoxPrg);

		renderFB.unbind();

		
		//clearing screen and rendering
		glViewport(0, 0, winData.resolution.x, winData.resolution.y);

		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glFrontFace(GL_CW);
		renderPlane.loadTexture(colorBuffer, false);
		mainRenderer.renderGenericArray(&renderPlane, renderPlane.getVCount(), UI_Out);


		//input from keyboard (camera movement)
		mainCam.moveForward(mainWin.getAxis(GLFW_KEY_W, GLFW_KEY_S)*deltaTime*camSpeed);
		mainCam.moveRight(mainWin.getAxis(GLFW_KEY_D, GLFW_KEY_A)*deltaTime*camSpeed);
		mainCam.moveUp(mainWin.getAxis(GLFW_KEY_E, GLFW_KEY_Q)*deltaTime*camSpeed);

		//shader switching
		if(mainWin.getKey(GLFW_KEY_F)){
			sprg.load("shaders/perspective(L)/point/vert.sha", "shaders/perspective(L)/point/frag.sha");
			sprg.setInt("T0", 0);
			printf("loading perspective(L)/point\n");
		}else if(mainWin.getKey(GLFW_KEY_G)){
			sprg.load("shaders/imgV/vert.sha", "shaders/imgV/frag.sha");
			sprg.setInt("T0", 0);
			printf("loading imgV\n");
		}else if(mainWin.getKey(GLFW_KEY_H)){
			sprg.load("shaders/perspective(L)/directional/vert.sha", "shaders/perspective(L)/directional/frag.sha");
			sprg.setInt("T0", 0);
			printf("loading perspective(L)/directional\n");
		}
		

		//toggle cursor
		if(mainWin.getKey(GLFW_KEY_ESCAPE)&&escAllow){
			//cursor variables
			cursor=!cursor;
			if(debug){
				logInfo("KEY_ESCAPE detected changing cursor mode\n");
			}
			escAllow=false;
		}else if(mainWin.getKeyR(GLFW_KEY_ESCAPE)){
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
	sendStopTo(connectTo("127.0.0.1", 8080));

	if(debug)printf("\n");
	if(debug)logInfo("Terminating\n");
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

/* 2024-03-01 02:01:00
==51309== 
==51309== HEAP SUMMARY:
==51309==     in use at exit: 140,945 bytes in 999 blocks
==51309==   total heap usage: 86,842 allocs, 85,843 frees, 1,065,886,714 bytes allocated
==51309== 
==51309== LEAK SUMMARY:
==51309==    definitely lost: 43,072 bytes in 28 blocks
==51309==    indirectly lost: 9,924 bytes in 59 blocks
==51309==      possibly lost: 0 bytes in 0 blocks
==51309==    still reachable: 87,949 bytes in 912 blocks
==51309==         suppressed: 0 bytes in 0 blocks
==51309== Rerun with --leak-check=full to see details of leaked memory
==51309== 
==51309== Use --track-origins=yes to see where uninitialised values come from
==51309== For lists of detected and suppressed errors, rerun with: -s
==51309== ERROR SUMMARY: 8 errors from 8 contexts (suppressed: 0 from 0)
*/

/* 2024-03-06 23:58:50
==117194== 
==117194== HEAP SUMMARY:
==117194==     in use at exit: 105,397 bytes in 1,002 blocks
==117194==   total heap usage: 130,012 allocs, 129,010 frees, 1,110,211,998 bytes allocated
==117194== 
==117194== LEAK SUMMARY:
==117194==    definitely lost: 7,356 bytes in 30 blocks
==117194==    indirectly lost: 10,068 bytes in 60 blocks
==117194==      possibly lost: 0 bytes in 0 blocks
==117194==    still reachable: 87,973 bytes in 912 blocks
==117194==         suppressed: 0 bytes in 0 blocks
==117194== Rerun with --leak-check=full to see details of leaked memory
==117194== 
==117194== Use --track-origins=yes to see where uninitialised values come from
==117194== For lists of detected and suppressed errors, rerun with: -s
==117194== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
*/

/* 2024-03-06 00:03:55
==118902== 
==118902== HEAP SUMMARY:
==118902==     in use at exit: 105,397 bytes in 1,002 blocks
==118902==   total heap usage: 133,633 allocs, 132,631 frees, 1,132,940,211 bytes allocated
==118902== 
==118902== LEAK SUMMARY:
==118902==    definitely lost: 7,588 bytes in 31 blocks
==118902==    indirectly lost: 9,836 bytes in 59 blocks
==118902==      possibly lost: 0 bytes in 0 blocks
==118902==    still reachable: 87,973 bytes in 912 blocks
==118902==         suppressed: 0 bytes in 0 blocks
==118902== Rerun with --leak-check=full to see details of leaked memory
==118902== 
==118902== Use --track-origins=yes to see where uninitialised values come from
==118902== For lists of detected and suppressed errors, rerun with: -s
==118902== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)
*/
