#include "CMGL_Renderer.hpp"

//constructors
CMGL_Renderer::CMGL_Renderer(){

}

//rendering functions
int CMGL_Renderer::renderGenericArray(CMGL_Base* toRender, int vCount, CMGL_Program &renderPrg){
    renderPrg.use();

    toRender->bind();
    
    glDrawArrays(GL_TRIANGLES, 0, vCount);

    return 0;
}

int CMGL_Renderer::renderGenericElement(CMGL_Base* toRender, int fCount, CMGL_Program &renderPrg){
    renderPrg.use();

    toRender->bind();
    
    glDrawElements(GL_TRIANGLES, fCount*3, GL_UNSIGNED_INT, (void*)0);

    return 0;
}


//CMGL_GameObject rendering
int CMGL_Renderer::renderGameObjectsA(CMGL_GameObject* objects, int objectsCount, CMGL_Program& renderPrg){
    renderPrg.use();
    
    for(int i = 0; i < objectsCount; i++){
        objects[i].bind();
        glDrawArrays(GL_TRIANGLES, 0, objects[i].getVCount());
    }

    return 0;
}

int CMGL_Renderer::renderGameObjectsE(CMGL_GameObject* objects, int objectsCount, CMGL_Program& renderPrg){
    renderPrg.use();
    
    for(int i = 0; i < objectsCount; i++){
        objects[i].bind();
        glDrawElements(GL_TRIANGLES, objects[i].getFCount()*3, GL_UNSIGNED_INT, (void*)0);
    }

    return 0;
}