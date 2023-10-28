#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tools/T0.h"
#include "tools/B0.h"
#include "tools/B1.h"
#include "tools/B2.h"
#include "tools/R0.h"
#include "tools/U0.h"

using namespace std;

int main(){
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
	vec2int resolution={800,600};
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
	//glfw settings


	glfwSwapInterval(1);//synchronizing framerate

	//initalizing mouse
	glfwSetInputMode(w0.getid(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

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

	glFrontFace(GL_CW);//clockwise winding
	glDepthFunc(GL_LEQUAL);//depth test pass condition (LEQUAL=less or equal)
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//search

	
	/******************************************************************************************/
	//shaders

	program pFB[2];//perspective fullbright //col 0, tex 1
	program pL[2];//perspective light //col 0, tex 1

	//creating shaders
	
	shader vS("shaders/perspective(FB)/color/vert.sha",GL_VERTEX_SHADER);
	shader fS("shaders/perspective(FB)/color/frag.sha",GL_FRAGMENT_SHADER);
	pFB[0].load(&vS,&fS);
	
	vS.load("shaders/perspective(FB)/texture/vert.sha",GL_VERTEX_SHADER);
	fS.load("shaders/perspective(FB)/texture/frag.sha",GL_FRAGMENT_SHADER);
	pFB[1].load(&vS,&fS);

	vS.load("shaders/orthographic/UItex/vert.sha",GL_VERTEX_SHADER);
	fS.load("shaders/orthographic/UItex/frag.sha",GL_FRAGMENT_SHADER);
	program oUI(&vS, &fS);

	vS.load("shaders/perspective(L)/color/vert.sha",GL_VERTEX_SHADER);
	fS.load("shaders/perspective(L)/color/frag.sha",GL_FRAGMENT_SHADER);
	pL[0].load(&vS, &fS);

	vS.load("shaders/perspective(L)/texture/vert.sha",GL_VERTEX_SHADER);
	fS.load("shaders/perspective(L)/texture/frag.sha",GL_FRAGMENT_SHADER);
	pL[1].load(&vS, &fS);

	if(debug)logInfo("shaders loaded\n");


	//Deleting shaders
	vS.Delete();
	fS.Delete();
	//look for a delete check

	
	/******************************************************************************************/
	//sceneManager setup
	SceneManager mainManager;
	mainManager.setPrograms(pFB,pL,&oUI);

	//vertex datas
	//ground
	vertex verts[6]={
	//	  tex   position    normal  color
		{{0,1},{-1,0,-1},{0,1,0},{1,1,1,1}},
		{{0,0},{-1,0,1} ,{0,1,0},{1,1,1,1}},
		{{1,0},{1,0,1}  ,{0,1,0},{1,1,1,1}},
		{{1,0},{1,0,1}  ,{0,1,0},{1,1,1,1}},
		{{1,1},{1,0,-1} ,{0,1,0},{1,1,1,1}},
		{{0,1},{-1,0,-1},{0,1,0},{1,1,1,1}}
	};
	//giving datas to objects
	//ground
	mainManager.addObject("ground",{0,0,0},{0,0,0},{50,1,50},6,verts,"images/Dark/texture_13.png",false);
	//mComp
	int oL=0;
	vertex* o=importOBJ("objects/mComp.obj",oL);
	mainManager.addObject("mComp",{0,10,0},{0,0,0},{1,1,1},oL,o);


	//for texture use (single texture system)
	glUniform1i(glGetUniformLocation(pFB[0].getid(),"tex0"),0);

	//ui elements
	UI_Element pauseS;
	pauseS.loadTexture("images/utility/paused.png");


	/******************************************************************************************/
	//lights

	int lC=1;
	float lightsData[8]={
		10,5,10,1,
		1,1,1,10
	};


	/******************************************************************************************/
	//main loop preparations
	

	/*while loop variables*/
	bool cursor=false,escAllow=true;
	int frame=0;//frame counter (resets per second)
	float totalTime=0,deltaTime=0,printCheck=0;//time related
	double cursorX=0,cursorY=0;//cursor input
	Camera cam0(60);//main camera
	
	/*while loop variables*/
	cam0.move({1,5,1});


	/******************************************************************************************/
	//main loop


	while(!glfwWindowShouldClose(w0.getid())){
		//getting time between frames and increasing total time
		deltaTime=glfwGetTime();
		glfwSetTime(0);
		totalTime+=deltaTime;
		printCheck+=deltaTime;


		//updating resolution
		resolution=w0.getResolution();
		glViewport(0,0,resolution.x,resolution.y);


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


		//updating uniforms
		for(int i=0;i<2;i++){
			pFB[i].use();
			glUniform2f(glGetUniformLocation(pFB[i].getid(),"rot"),cam0.rotation.x,cam0.rotation.y);
			glUniform3f(glGetUniformLocation(pFB[i].getid(),"mov"),cam0.position.x,cam0.position.y,cam0.position.z);
			glUniform1i(glGetUniformLocation(pFB[i].getid(),"w"),resolution.x);
			glUniform1i(glGetUniformLocation(pFB[i].getid(),"h"),resolution.y);
		}

		for(int i=0;i<2;i++){
			pL[i].use();
			glUniform2f(glGetUniformLocation(pL[i].getid(),"rot"),cam0.rotation.x,cam0.rotation.y);
			glUniform3f(glGetUniformLocation(pL[i].getid(),"mov"),cam0.position.x,cam0.position.y,cam0.position.z);
			glUniform1i(glGetUniformLocation(pL[i].getid(),"w"),resolution.x);
			glUniform1i(glGetUniformLocation(pL[i].getid(),"h"),resolution.y);
			glUniform1i(glGetUniformLocation(pL[i].getid(),"count"),lC);
			glUniform4fv(glGetUniformLocation(pL[i].getid(),"lights"),lC*2,lightsData);
		}


		//drawing to back buffer
			mainManager.draw();//objects

			//pause screen
			if(cursor){
				oUI.use();
				pauseS.bind();
				glDrawArrays(GL_TRIANGLES,0,pauseS.getVCount());
				pauseS.unbind();
			}


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