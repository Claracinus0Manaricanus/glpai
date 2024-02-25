# Location
classes/opengl/

# Purpose
To abstract rendering functions.

# Public Functions
- CMGL_Renderer();  
Constructor.
- int renderGenericArray(CMGL_Base* toRender, int length, int vCount, CMGL_Program &renderPrg);
- int renderGenericElement(CMGL_Base* toRender, int length, int fCount, CMGL_Program &renderPrg);