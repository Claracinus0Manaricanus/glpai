#ifndef TYPES_H
#define TYPES_H

#define PI 3.14159265f
#define PI2 6.2831853f
#define HORIZONTAL 0
#define VERTICAL 1

#include <math.h>
#include <stdexcept>
#include <cstdint>


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

	vec2 operator*(vec2 a){
		vec2 ret;

		ret.x=x*a.x;
		ret.y=y*a.y;

		return ret;
	}

	vec2& operator=(int a){
		x=a;
		y=a;

		return *this;
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

	vec3& operator+=(vec3 n){//the problem child
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

struct vertex{
	vec2 tex={0,0};//x,y
	vec3 pos={0,0,0},nor={0,0,0};//x,y,z
	vec4 col={1,1,1,1};//x,y,z,w

	vertex operator=(vertex a){//not tested
		return {a.tex,a.pos,a.nor,a.col};
	}
};

#endif