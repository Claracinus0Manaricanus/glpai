# Location
classes/system/

# Purpose
This class is used to import image data from files.

# Protected Data
- uint8_t* imgData=NULL;
- int iHeight=1,iWidth=1,iChannel=4;

# Public Functions
- Image();  
Constructor.
-
- Image(ImageData data);  
Constructor.
-
- ~Image();  
Destructor
-
-
- int load(ImageData data);  
Used to change loaded image.
-
-
- int width();  
Used to get images width in pixels.
-
- int height();  
Used to get images height in pixels.
-
- int spectrum();  
Used to get images channells. RGBA
-
- uint8_t* getDataP();  
Returns data location. Does not copy returns original data use carefully.
-
-
- int reset();  
Resets the data to defaults.