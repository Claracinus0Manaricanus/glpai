#ifndef TYPES_H
#define TYPES_H

#define PI 3.14159265f
#define PI2 6.2831853f
#define HORIZONTAL 0
#define VERTICAL 1

#include <math.h>


struct vec2int{
	int x,y;

	vec2int& operator*(int a){
		x*=a;
		y*=a;

		return *this;
	}

	vec2int& operator=(int a){
		x=a;
		y=a;

		return *this;
	}
};


struct vec2{
	float x,y;

	vec2& operator*(int a){
		x*=a;
		y*=a;

		return *this;
	}

	vec2& operator*(vec2 a){
		x*=a.x;
		y*=a.y;

		return *this;
	}

	vec2& operator=(int a){
		x=a;
		y=a;

		return *this;
	}
};


struct vec3{
	float x,y,z;
	
	vec3& operator+(vec3 n){
		x+=n.x;
		y+=n.y;
		z+=n.z;

		return *this;
	}

	vec3& operator-(vec3 n){
		x-=n.x;
		y-=n.y;
		z-=n.z;

		return *this;
	}

	vec3& operator*(vec3 n){
		x*=n.x;
		y*=n.y;
		z*=n.z;

		return *this;
	}

	vec3& operator*(float a){
		x*=a;
		y*=a;
		z*=a;

		return *this;
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

	vec3& operator/(float a){
		x/=a;
		y/=a;
		z/=a;
		
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

	vec4& operator+(vec4 n){
		x+=n.x;
		y+=n.y;
		z+=n.z;
		w+=n.w;

		return *this;
	}

	vec4& operator*(int a){
		x*=a;
		y*=a;
		z*=a;
		w*=a;
		
		return *this;
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

namespace vectors{
	//vector calculations
	float dot(vec3 a, vec3 b);	
	float dot(vec2 a, vec2 b);	
	vec3 normalize(vec3 a);	
	vec2 normalize(vec2 a);
}

#endif