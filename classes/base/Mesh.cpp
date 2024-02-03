#include "Mesh.hpp"

//constructors
Mesh::Mesh(){}

Mesh::Mesh(MeshData inputData){
    if(inputData.vCount != 0){
        vCount=inputData.vCount;
        vertices=(Vertex*)malloc(vCount*sizeof(Vertex));
        memcpy(vertices, inputData.vertices, vCount*sizeof(Vertex));
    }

    if(inputData.fCount != 0){
        fCount=inputData.fCount;
        faces=(uint32_t*)malloc(fCount*sizeof(int)*3);
        memcpy(faces, inputData.faces, fCount*sizeof(int)*3);
    }
}


//destructors
Mesh::~Mesh(){
    free(vertices);
    free(faces);
}


//setters
int Mesh::loadData(MeshData inputData){
    if(inputData.vCount != 0){
        vCount=inputData.vCount;
        free(vertices);
        vertices=(Vertex*)malloc(vCount*sizeof(Vertex));
        memcpy(vertices, inputData.vertices, vCount*sizeof(Vertex));
    }

    if(inputData.fCount != 0){
        fCount=inputData.fCount;
        free(faces);
        faces=(uint32_t*)malloc(fCount*sizeof(int)*3);
        memcpy(faces, inputData.faces, fCount*sizeof(int)*3);
    }else{
        fCount=0;
    }

    return 0;
}


//getters
int Mesh::getVCount(){
    return vCount;
}

int Mesh::getFCount(){
    return fCount;
}

Vertex* Mesh::getVertices(){//unsafe
    return vertices;
}

uint32_t* Mesh::getFaces(){//unsafe
    return faces;
}

MeshData Mesh::getMeshData(){
    MeshData toRet;
    if(vCount != 0){
        Vertex* tmpVertices=(Vertex*)malloc(vCount*sizeof(Vertex));
        memcpy(tmpVertices,vertices,vCount*sizeof(Vertex));
        toRet.vCount=vCount;
        toRet.vertices=tmpVertices;
    }
    if(fCount != 0){
        uint32_t* tmpFaces=(uint32_t*)malloc(fCount*sizeof(int)*3);
        memcpy(tmpFaces,faces,fCount*sizeof(int)*3);
        toRet.fCount=fCount;
        toRet.faces=tmpFaces;
    }
    return toRet;
}