#ifndef TYPES_H
#define TYPES_H

#define PI 3.14159265f
#define PI2 6.2831853f
#define HORIZONTAL 0
#define VERTICAL 1

#include <math.h>
#include <stdexcept>
#include <cstdint>


//vectors
struct ivec2{
	int x,y;

	ivec2 operator*(int a){
		ivec2 ret;

		ret.x=x*a;
		ret.y=y*a;

		return ret;
	}

	ivec2& operator=(int a){
		x=a;
		y=a;

		return *this;
	}
};


struct vec2{
	float x,y;

	vec2 operator*(int a){
		vec2 ret;

		ret.x=x*a;
		ret.y=y*a;

		return ret;
	}

	vec2 operator*(float a){
		vec2 ret;

		ret.x=x*a;
		ret.y=y*a;

		return ret;
	}

	vec2 operator*(vec2 a){
		vec2 ret;

		ret.x=x*a.x;
		ret.y=y*a.y;

		return ret;
	}

	vec2 operator/(float a){
		vec2 ret;

		ret.x=x/a;
		ret.y=y/a;

		return ret;
	}

	vec2 operator+(vec2 a){
		vec2 ret;

		ret.x = x+a.x;
		ret.y = y+a.y;
	
		return ret;
	}

	vec2 operator-(vec2 a){
		vec2 ret;

		ret.x = x-a.x;
		ret.y = y-a.y;
	
		return ret;
	}

	vec2 operator-(){
		vec2 ret;

		ret.x = -x;
		ret.y = -y;
	
		return ret;
	}

	vec2& operator=(int a){
		x=a;
		y=a;

		return *this;
	}

	bool operator==(vec2 a){
		bool ret;
		
		ret = (x==a.x)&&(y==a.y);
		
		return ret;
	}
};


struct vec3{
	float x,y,z;
	
	vec3 operator+(vec3 n){
		vec3 ret;

		ret.x=x+n.x;
		ret.y=y+n.y;
		ret.z=z+n.z;

		return ret;
	}

	vec3 operator-(vec3 n){
		vec3 ret;

		ret.x=x-n.x;
		ret.y=y-n.y;
		ret.z=z-n.z;

		return ret;
	}

	vec3 operator-(){
		vec3 ret;

		ret.x=-x;
		ret.y=-y;
		ret.z=-z;

		return ret;
	}

	vec3 operator*(vec3 n){
		vec3 ret;

		ret.x=x*n.x;
		ret.y=y*n.y;
		ret.z=z*n.z;

		return ret;
	}

	vec3 operator*(float a){
		vec3 ret;

		ret.x=x*a;
		ret.y=y*a;
		ret.z=z*a;

		return ret;
	}

	vec3 operator/(float a){
		vec3 ret;

		ret.x=x/a;
		ret.y=y/a;
		ret.z=z/a;
		
		return ret;
	}

	float& operator[](int i){//optimize
		if(i>2||i<0)
			throw std::invalid_argument("invalid index number for the type vec3, should be between [0,2]");
		
		float* ret=(float*)((char*)this+(i*sizeof(float)));
		
		return *ret;
	}

	vec3& operator=(float a){
		x=a;
		y=a;
		z=a;

		return *this;
	}

	vec3& operator=(int a){
		x=a;
		y=a;
		z=a;

		return *this;
	}

	vec3& operator+=(vec3 n){
		x+=n.x;
		y+=n.y;
		z+=n.z;

		return *this;
	}
};


struct vec4{
	float x=0,y=0,z=0,w=0;

	vec4 operator+(vec4 n){
		vec4 ret;

		ret.x=x+n.x;
		ret.y=y+n.y;
		ret.z=z+n.z;
		ret.w=w+n.w;

		return ret;
	}

	vec4 operator*(int a){
		vec4 ret;

		ret.x=x*a;
		ret.y=y*a;
		ret.z=z*a;
		ret.w=w*a;
		
		return ret;
	}

	vec4& operator=(int a){
		x=a;
		y=a;
		z=a;
		w=a;

		return *this;
	}
};

//Vertex
struct Vertex{
	vec3 pos={0,0,0};//x,y,z
	vec3 nor={0,0,0};//x,y,z
	vec4 col={1,1,1,1};//x,y,z,w
	vec2 tex={0,0};//x,y

	Vertex operator=(Vertex a){//not tested
		return {a.pos,a.nor,a.col,a.tex};
	}
};

//class Datas
struct MeshData{
	uint32_t vCount=0;
	Vertex* vertices=NULL;
	uint32_t fCount=0;
	uint32_t* faces=NULL;
};

struct TransformData{
	vec3 position={0,0,0};
	vec3 rotation={0,0,0};
	vec3 scale={1,1,1};
};

struct FramebufferData{
	uint32_t framebufferType = 0;
};

struct TextureData{
	uint32_t unit = 0;
	uint32_t width = 0;
	uint32_t height = 0;

	uint32_t textureType = 0;// example: GL_TEXTURE_2D
	uint32_t textureFormat = 0;// example: GL_DEPTH_COMPONENT or GL_RGBA
	uint32_t textureDataType = 0;// example: GL_UNSIGNED_BYTE
	uint32_t textureWrap = 0;// example: GL_REPEAT
	uint32_t textureFilter = 0;// example: GL_LINEAR
	
	void* data = NULL;
};

struct ImageData{
	char* imageFile=NULL;
	int desiredChannels=3;//decides how to get data, ex: Gray RGB RGBA
	int flipImage=0;
};

struct CubeMapData{
	char* sides[6];// +X, -X, +Y, -Y, +Z, -Z
	//maybe change to vectors
};

struct ObjectData{
	MeshData mData;
	TransformData trData;
	TextureData texData;
};

struct DirectLightData{
	vec4 color = {1,1,1,1};
	vec3 direction = {0,0,0};
};

struct WindowData{
	ivec2 resolution={800, 600};
	char* name="default";
	int openglVersionMajor=4;
	int openglVersionMinor=5;
	int openglProfile=0;//set by user
};

#endif