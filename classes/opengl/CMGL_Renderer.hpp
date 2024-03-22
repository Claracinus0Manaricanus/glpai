//implement a mapping system so the COU knows which data and how to send it to GPU
//example:
//func(void* data, struct map* usage, CMGL_Program prgToUse);
#ifndef CMGL_RENDERER
#define CMGL_RENDERER

#include "CMGL_GameObject.hpp"
#include "CMGL_Framebuffer.hpp"
#include "CMGL_Base.hpp"
#include "../graphics/CMGL_Program.hpp"

class CMGL_Renderer{
public:
    //constructors
    CMGL_Renderer();

    //CMGL_GameObject rendering
    static int renderGameObjects(CMGL_GameObject* objects, int objectsCount, CMGL_Framebuffer& FB, CMGL_Program& renderPrg);
    static int renderGameObjects(CMGL_GameObject* objects, int objectsCount, CMGL_Program& renderPrg);

};

#endif