#include "CMGL_Shader.h"

//constructor
CMGL_Shader::CMGL_Shader(const char* sourceFile, unsigned int type, bool debug){
	//creating CMGL_Shader
	ID=glCreateShader(type);

	
	//getting CMGL_Shader from source file (WIP error checking)
	int sourceFD=open(sourceFile, O_RDONLY);
	struct stat fileInfo;
	fstat(sourceFD, &fileInfo);

	//creating buffer to hold source data
	char* src=(char*)calloc(fileInfo.st_size + 1, 1);
	read(sourceFD, src, fileInfo.st_size);


	//compiling CMGL_Shader
	glShaderSource(ID,1,&src,NULL);
	glCompileShader(ID);

	//cleaning source file buffer
	free(src);

	char inf[1024];
	if(debug && (getError(inf) > 0)){
		printf("\n%s\n",inf);
	}
}//needs error checking (fstream)


//destructor
CMGL_Shader::~CMGL_Shader(){
	if(ID!=0)
		glDeleteShader(ID);
}


//loaders
int CMGL_Shader::load(const char* sourceFile, uint32_t type, bool debug){
	//deleting old CMGL_Shader
	if(ID!=0)
		glDeleteShader(ID);

	//creating new CMGL_Shader
	ID=glCreateShader(type);

	//getting CMGL_Shader from source file (WIP error checking)
	int sourceFD=open(sourceFile, O_RDONLY);
	struct stat fileInfo;
	fstat(sourceFD, &fileInfo);

	//creating buffer to hold source data
	char* src=(char*)calloc(fileInfo.st_size + 1, 1);
	read(sourceFD, src, fileInfo.st_size);


	//compiling CMGL_Shader
	glShaderSource(ID,1,&src,NULL);
	glCompileShader(ID);

	//cleaning source file buffer
	free(src);

	char inf[1024];
	if(debug&&getError(inf)>0){
		printf("\n%s\n",inf);
	}
	return 0;
}


//utility
int CMGL_Shader::Delete(){
	glDeleteShader(ID);
	ID=0;
	return 0;
}//check needed

int CMGL_Shader::getError(char ret[1024]){
	int tempLength;
	glGetShaderInfoLog(ID,1024,&tempLength,ret);
	return tempLength;
}//error check needed (glGetShaderInfoLog())