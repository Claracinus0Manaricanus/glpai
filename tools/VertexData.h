#ifndef VERTEXDATA
#define VERTEXDATA

#include <cstring>
#include <cstdlib>
#include "T0.h"

class VertexData{
protected:
	int vCount=0;//total vertices
	vertex* vertices=nullptr;

public:
	//constructrors
	VertexData();
	VertexData(int inVCount, vertex* iVertices);

	//destructor
	~VertexData();

	//loaders
	int setColor(vec4 inCol);
	int loadPos(vec3* inPos);
	int loadNor(vec3* inNor);
	int loadCol(vec4* inCol);
	int loadTex(vec2* inTex);
	int loadAll(int inVCount, vertex* iVertices);

	//extractors
	int getVCount();

	//utility
	int reset();
	virtual VertexData* getPointer();
};//unsafe

#endif