# Location
classes/system/

# Purpose
To create and manager window objects using glfw. Abstraction for window management.

# Protected Data
- GLFWwindow* ID  
Handler for window.

# Public Functions
- Window(WindowData inputData)  
Constructor for Window class. Sets opengl version, opengl profile, window initials.
- GLFWwindow* getid()  
Used to access handler.
- ivec2 getResolution()  
Used to access current resolution.
- int changeAttrib(int attrib, int value)  
Used to change a specific attrbitue about window.
- int makeContext()  
sets this window as opengl context.