#ifndef MESH_HPP
#define MESH_HPP

#include "../system/T0.hpp"
#include <cstring>

class Mesh{
protected:
    Vertex* vertices=NULL;//vertex data
    int vCount=0;//vertex count
    uint32_t* faces=NULL;//indice data
    int fCount=0;//face count, 0 if index buffer (faces) is not used

public:
    //constructors
    Mesh();
    Mesh(MeshData inputData);

    //destructors
    ~Mesh();

    //setters
    int loadData(MeshData inputData);

    //getters
    int getVCount();
    int getFCount();
    Vertex* getVertices();
    uint32_t* getFaces();
    MeshData getMeshData();
};

#endif