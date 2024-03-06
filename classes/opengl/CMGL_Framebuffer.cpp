#include "CMGL_Framebuffer.hpp"


//constructors
CMGL_Framebuffer::CMGL_Framebuffer(){
    glGenFramebuffers(1, &ID);
    framebufferType = GL_FRAMEBUFFER;
}

CMGL_Framebuffer::CMGL_Framebuffer(FramebufferData inData){
    glGenFramebuffers(1, &ID);
    framebufferType = inData.framebufferType;
}


//destructors
CMGL_Framebuffer::~CMGL_Framebuffer(){
    glDeleteFramebuffers(1, &ID);
}


//setters
int CMGL_Framebuffer::setColorAttachment(uint32_t ID){
    bind();
    glFramebufferTexture2D(framebufferType, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ID, 0);
    unbind();
    return 0;
}

int CMGL_Framebuffer::setDepthAttachment(uint32_t ID){
    bind();
    glFramebufferTexture2D(framebufferType, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, ID, 0);
    unbind();
    return 0;
}



//getters
uint32_t CMGL_Framebuffer::getID(){
    return ID;
}

uint32_t CMGL_Framebuffer::getType(){
    return framebufferType;
}


//utility
void CMGL_Framebuffer::bind(){
    glBindFramebuffer(framebufferType, ID);
}

void CMGL_Framebuffer::unbind(){
    glBindFramebuffer(framebufferType, 0);
}