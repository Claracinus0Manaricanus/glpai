//implement a mapping system so the COU knows which data and how to send it to GPU
//example:
//func(void* data, struct map* usage, CMGL_Program prgToUse);
#ifndef CMGL_RENDERER
#define CMGL_RENDERER

#include "CMGL_GameObject.hpp"
#include "CMGL_Base.hpp"
#include "../graphics/CMGL_Program.hpp"

class CMGL_Renderer{
protected:


public:
    //constructors
    CMGL_Renderer();

    //rendering functions
    int renderGenericArray(CMGL_Base* toRender, int vCount, CMGL_Program &renderPrg);
    int renderGenericElement(CMGL_Base* toRender, int fCount, CMGL_Program &renderPrg);

};

#endif