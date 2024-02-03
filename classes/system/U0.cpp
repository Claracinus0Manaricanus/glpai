#include "U0.hpp"

//input utility
int CgetAxis(GLFWwindow* win, int key1, int key2){//custom get axis first key is positive second is negative
	if(glfwGetKey(win,key1)==GLFW_PRESS)
		return 1;
	else if(glfwGetKey(win,key2)==GLFW_PRESS)
		return -1;
	return 0;
}


//debug features
void logInfo(const char* message){
	printf("\033[0;32mINFO:\033[0;36m%s",message);
}

void logDebug(const char* message){
	printf("\033[0;33mDEBUG:\033[0;36m%s",message);
}

void logError(const char* message){
	printf("\033[0;31mERROR:\033[0;36m%s",message);
}

void logGreen(const char* message){
	printf("\033[0;32m%s",message);
}


//number utility
int cm_rand(int seed){//not tested
	return (seed*seed<<23*seed*seed);
}


//file import
Vertex* importOBJ(std::string filename, int& size){//size = element number of array
	int vPosInd=0,vNorInd=0,vTexInd=0,vArrInd=0,tmpPos=0;
	//finding out array lengths
	std::string line,tmp;
	std::ifstream file(filename);
	while(getline(file,line)){
		if(line.length()>2){
			switch(line[0]+line[1]){
				case 'v'+' ':
					vPosInd++;
				break;
				case 'v'+'n':
					vNorInd++;
				break;
				case 'v'+'t':
					vTexInd++;
				break;
				case 'f'+' ':
					for(int i=0;i<line.length();i++){
						if(line[i]==' ')tmpPos++;
					}
					vArrInd+=(3*tmpPos-6);
					tmpPos=0;
				break;
			}
		}
	}file.close();

	size=vArrInd*3;//Vertex array length

	//creating arrays
	vec3* vPos=new vec3[vPosInd*3];vPosInd=0;//positions
	vec3* vNor=new vec3[vNorInd*3];vNorInd=0;//normals
	vec2* vTex=new vec2[vTexInd*2];vTexInd=0;//texture coordinates
	Vertex* vArr=new Vertex[vArrInd*3];vArrInd=0;//vertices
	int index[9]={0};
	
	//getting array data from file
	std::ifstream fileT(filename);
	while(getline(fileT,line)){
		if(line.length()>2){
			switch(line[0]+line[1]){
				//positions
				case 'v'+' ':
					for(int i=2;i<line.length();i++){
						if(i==(line.length()-1))tmp+=line[i];
						if(line[i]!=' '&&i!=(line.length()-1)){
							tmp+=line[i];
						}else{
							switch(tmpPos){
								case 0:
									vPos[vPosInd].x=strtof(tmp.c_str(),nullptr);
									tmpPos++;
								break;
								case 1:
									vPos[vPosInd].y=strtof(tmp.c_str(),nullptr);
									tmpPos++;
								break;
								case 2:
									vPos[vPosInd].z=strtof(tmp.c_str(),nullptr);
									tmpPos=0;
								break;
							}
							tmp.clear();
						}
					}
					vPosInd++;
				break;
				//normals
				case 'v'+'n':
					for(int i=3;i<line.length();i++){
						if(i==(line.length()-1))tmp+=line[i];
						if(line[i]!=' '&&i!=(line.length()-1)){
							tmp+=line[i];
						}else{
							switch(tmpPos){
								case 0:
									vNor[vNorInd].x=strtof(tmp.c_str(),nullptr);
									tmpPos++;
								break;
								case 1:
									vNor[vNorInd].y=strtof(tmp.c_str(),nullptr);
									tmpPos++;
								break;
								case 2:
									vNor[vNorInd].z=strtof(tmp.c_str(),nullptr);
									tmpPos=0;
								break;
							}
							tmp.clear();
						}
					}
					vNorInd++;
				break;
				//texture coordinates
				case 'v'+'t':
					for(int i=3;i<line.length();i++){
						if(i==(line.length()-1))tmp+=line[i];
						if(line[i]!=' '&&i!=(line.length()-1)){
							tmp+=line[i];
						}else{
							switch(tmpPos){
								case 0:
									vTex[vTexInd].x=strtof(tmp.c_str(),nullptr);
									tmpPos++;
								break;
								case 1:
									vTex[vTexInd].y=strtof(tmp.c_str(),nullptr);
									tmpPos=0;
								break;
							}
							tmp.clear();
						}
					}
					vTexInd++;
				break;
				//faces
				case 'f'+' ':
					tmpPos=0;
					for(int i=2;i<line.length();i++){
						if(i==(line.length()-1))tmp+=line[i];
						if(line[i]!='/'&&line[i]!=' '&&i!=(line.length()-1)){
							tmp+=line[i];
						}else{
							switch(tmpPos%3){
							case 0://position
								if(tmp==""){
									index[tmpPos]=0;
									tmpPos++;
									break;
								}
								index[tmpPos]=stoi(tmp);
								tmpPos++;
						 	break;

							case 1://tex
								if(tmp==""){
									index[tmpPos]=0;
									tmpPos++;
									break;
								}
								index[tmpPos]=stoi(tmp);
								tmpPos++;
						 	break;

							case 2://normal
								if(tmp==""){
									index[tmpPos]=0;
									tmpPos++;
									break;
								}
								index[tmpPos]=stoi(tmp);
								tmpPos++;
						 	break;
							}
							tmp.clear();
						}
						//loading to vArr
						if(tmpPos==9||i==(line.length()-1)){//no index check is made
							for(int k=0;k<9;k++){
								vArr[vArrInd].pos=vPos[index[k]-1];k++;
								vArr[vArrInd].tex=vTex[index[k]-1];k++;
								vArr[vArrInd].nor=vNor[index[k]-1];
								vArrInd++;
							}
							tmpPos=6;
							index[3]=index[6];
							index[4]=index[7];
							index[5]=index[8];
						}
					}
				break;
			}
		}
	}
	fileT.close();

	//returning Vertex*
	return vArr;
}
//importOBJ needs checks at loading to vArr part


MeshData importHeightMap(const char* filename, float division_constant, int terrainResolution, int* WIDTH, int* LENGTH){
	int width = 0, length = 0, channels = 0;

	//reading file
	ImageData tmpImgData;
	tmpImgData.imageFile=(char*)malloc(strlen(filename));
	memcpy(tmpImgData.imageFile, filename, strlen(filename));
	tmpImgData.desiredChannels=1;
	tmpImgData.flipImage=1;
	
	Image dataImage(tmpImgData);
	uint8_t* data = dataImage.getDataP();
	free(tmpImgData.imageFile);

	width/=terrainResolution;
	length/=terrainResolution;

	MeshData m_data;

	if(data == NULL)
		return m_data;

	//creating mesh
	m_data.vCount = width*length;
	m_data.vertices = (Vertex*)calloc(m_data.vCount, sizeof(Vertex));
	m_data.fCount = (width-1)*(length-1)*6;
	m_data.faces = (uint32_t*)calloc(m_data.fCount, sizeof(int));

	//Vertex data
	for(int k = 0; k < length; k++){//X
		for(int i = 0; i < width; i++){//Y
			//positions
			m_data.vertices[k*width+i].pos.x = i * terrainResolution / division_constant;
			m_data.vertices[k*width+i].pos.y = (float)data[(k*width*terrainResolution+i)*terrainResolution]*0.2f;
			m_data.vertices[k*width+i].pos.z = k * terrainResolution / division_constant;

			m_data.vertices[k*width+i].col={1,1,1,1};

			//UV coordinates
			m_data.vertices[k*width+i].tex.x = (float)i / width;
			m_data.vertices[k*width+i].tex.y = 1.0f - (float)k / length;
		}
	}

	//index buffer data (faces)
	for(int k = 0; k < (length - 1); k++){
		for(int i = 0; i < (width - 1); i++){
			m_data.faces[(k*(width-1)+i)*6] = (k*width+i);
			m_data.faces[(k*(width-1)+i)*6+1] = ((k+1)*width+i);
			m_data.faces[(k*(width-1)+i)*6+2] = ((k+1)*width+i+1);
			m_data.faces[(k*(width-1)+i)*6+3] = ((k+1)*width+i+1);
			m_data.faces[(k*(width-1)+i)*6+4] = (k*width+i+1);
			m_data.faces[(k*(width-1)+i)*6+5] = (k*width+i);
		}
	}

	//pass length and width
	if(WIDTH != NULL) (*WIDTH) = width;
	if(LENGTH != NULL) (*LENGTH) = length;

	//free memory
	return m_data;
}


//calculation
MeshData calculateNormals(MeshData* buffer){
	//allocations
	Vertex* vBuff=(Vertex*)calloc(buffer->fCount, sizeof(Vertex));
	
	//temporary variables
	vec3 V1 = {0}, V2 = {0}, Nor = {0};

	//calculations
	for(int i = 0; i < buffer->fCount; i+=3){
		//creates vectors from first Vertex of a face to third and second vertices
		V1 = buffer->vertices[buffer->faces[i+2]].pos - buffer->vertices[buffer->faces[i]].pos;
		V2 = buffer->vertices[buffer->faces[i+1]].pos - buffer->vertices[buffer->faces[i]].pos;

		Nor = Normalize(Cross(V2, V1));

		//trasnferring to vBuff Vertex array with new normals
		memcpy(&vBuff[i], &buffer->vertices[buffer->faces[i]], sizeof(Vertex));
		vBuff[i].nor = Nor;
		memcpy(&vBuff[i+1], &buffer->vertices[buffer->faces[i+1]], sizeof(Vertex));
		vBuff[i+1].nor = Nor;
		memcpy(&vBuff[i+2], &buffer->vertices[buffer->faces[i+2]], sizeof(Vertex));
		vBuff[i+2].nor = Nor;

	}

	//constructing return data
	MeshData toRet;
	toRet.vCount = buffer->fCount;
	toRet.vertices = vBuff;
	toRet.fCount = 0;
	free(toRet.faces);
	toRet.faces = NULL;

	return toRet;
}