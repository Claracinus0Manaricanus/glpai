#include "CMGL_Renderer.hpp"

//constructors
CMGL_Renderer::CMGL_Renderer(){}


//CMGL_GameObject rendering
int CMGL_Renderer::renderGameObjects(CMGL_GameObject* objects, int objectsCount, CMGL_Framebuffer& FB, CMGL_Program& renderPrg){
    FB.bind();

    renderPrg.use();
    
    for(int i = 0; i < objectsCount; i++){
        objects[i].bind();
        if(objects[i].getFCount() == 0)
            glDrawArrays(GL_TRIANGLES, 0, objects[i].getVCount());
        else
            glDrawElements(GL_TRIANGLES, objects[i].getFCount()*3, GL_UNSIGNED_INT, (void*)0);
    }

    FB.bind();
    return 0;
}

int CMGL_Renderer::renderGameObjects(CMGL_GameObject* objects, int objectsCount, CMGL_Program& renderPrg){
    renderPrg.use();
    
    for(int i = 0; i < objectsCount; i++){
        objects[i].bind();
        if(objects[i].getFCount() == 0)
            glDrawArrays(GL_TRIANGLES, 0, objects[i].getVCount());
        else
            glDrawElements(GL_TRIANGLES, objects[i].getFCount()*3, GL_UNSIGNED_INT, (void*)0);
    }

    return 0;
}