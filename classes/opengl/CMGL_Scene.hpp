#ifndef CMGL_SCENE
#define CMGL_SCENE

#include <vector>
#include "CMGL_GameObject.hpp"

class CMGL_Scene{
private:
    std::vector<CMGL_GameObject*> g_objects();

public:
    //constructors
    CMGL_Scene();
    CMGL_Scene(SceneData sceneDat);

    //destructors
    ~CMGL_Scene();

    //adders

    //removers

    //getters
};

#endif