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