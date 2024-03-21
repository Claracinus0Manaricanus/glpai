#ifndef CMGL_FRAMEBUFFER
#define CMGL_FRAMEBUFFER

#include "../system/T0.hpp"
#include <GL/glew.h>

class CMGL_Framebuffer{
protected:
    uint32_t ID = 0;
    uint32_t framebufferType = 0;
    int width=0, height=0;

public:
    //constructors
    CMGL_Framebuffer();
    CMGL_Framebuffer(FramebufferData inData);

    //destructors
    ~CMGL_Framebuffer();

    //setters
    int setColorAttachment(uint32_t ID);
    int setDepthAttachment(uint32_t ID);

    //getters
    uint32_t getID();
    uint32_t getType();

    //utility
    void setViewport();
    void bind();
    void unbind();

};

#endif