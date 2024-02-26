# Location
classes/base/

# Purpose
This class is used to keep 3 dimensional size, position and orientation data.

# Protected Data
- vec3 Position={0,0,0};
- vec3 Rotation={0,0,0};
- vec3 Scale={1,1,1};

# Public Functions
- Transform();  
No parameter constructor.
-
- Transform(TransformData inputTransform);  
A contructor to initialize protected data to desired values.
-
- ~Transform();  
Destructor.
-
-
- void loadData(TransformData inputTransform);  
Used for changing protected data.
-
- void setPosition(vec3 newPosition);  
Sets Position.
-
- void setRotation(vec3 newRotation);  
Sets Rotation.
-
- void setScale(vec3 newScale);  
Just take a guess?
-
- void move(vec3 movement);  
Adds movement on Position.
-
- void rotate(vec3 rotation);  
Adds rotation on Rotation.
-
- void scale(vec3 scaleToAdd);  
It's your imagination.
-
-
- TransformData getTransformData();  
Returns TransformData values.
-
- vec3 getPosition();  
Returns Position vector.
-
- vec3 getRotation();  
Returns Rotation vector.
-
- vec3 getScale();  
Returns Scale vector.
