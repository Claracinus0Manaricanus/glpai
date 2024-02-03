# Purpose
To create and manager window objects using glfw. Abstraction for window management.

# private data
- GLFWwindow* ID<br>
Handler for window.

# public functions
- Window(WindowData inputData)  
Constructor for Window class. Sets opengl version, opengl profile, window initials.<hr>
- GLFWwindow* getid()  
Used to access handler.<hr>
- ivec2 getResolution()  
Used to access current resolution.<hr>
- int changeAttrib(int attrib, int value)  
Used to change a specific attrbitue about window.<hr>
- int makeContext()  
sets this window as opengl context.