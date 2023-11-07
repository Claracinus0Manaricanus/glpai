#ifndef TYPES_H
#define TYPES_H

#define PI 3.14159265f
#define PI2 6.2831853f
#define HORIZONTAL 0
#define VERTICAL 1

#include <math.h>


struct vec2int{
	int x,y;

	vec2int operator*(int a){
		vec2int temp;

		temp.x=x*a;
		temp.y=y*a;

		return temp;
	}

	vec2int operator=(int a){
		vec2int temp;

		temp.x=a;
		temp.y=a;

		return temp;
	}
};


struct vec2{
	float x,y;

	vec2 operator*(int a){
		vec2 temp;

		temp.x=x*a;
		temp.y=y*a;

		return temp;
	}

	vec2 operator*(vec2 a){
		vec2 temp;

		temp.x=x*a.x;
		temp.y=y*a.y;

		return temp;
	}

	vec2 operator=(int a){
		vec2 temp;

		temp.x=a;
		temp.y=a;

		return temp;
	}
};


struct vec3{
	float x,y,z;
	
	vec3 operator+(vec3 n){
		vec3 temp;

		temp.x=x+n.x;
		temp.y=y+n.y;
		temp.z=z+n.z;

		return temp;
	}

	vec3 operator-(vec3 n){
		return {x-n.x,y-n.y,z-n.z};
	}

	vec3 operator*(vec3 n){
		vec3 temp;

		temp.x=x*n.x;
		temp.y=y*n.y;
		temp.z=z*n.z;

		return temp;
	}

	vec3 operator*(float a){
		vec3 temp;

		temp.x=x*a;
		temp.y=y*a;
		temp.z=z*a;

		return temp;
	}

	vec3 operator=(float a){
		vec3 temp;

		temp.x=a;
		temp.y=a;
		temp.z=a;

		return temp;
	}

	vec3 operator=(int a){
		vec3 temp;

		temp.x=a;
		temp.y=a;
		temp.z=a;

		return temp;
	}

	vec3 operator+=(vec3 n){//the problem child
		return (*this)+n;
	}
};


struct vec4{
	float x=0,y=0,z=0,w=0;

	vec4 operator+(vec4 n){
		vec4 temp;

		temp.x=x+n.x;
		temp.y=y+n.y;
		temp.z=z+n.z;
		temp.w=w+n.w;

		return temp;
	}

	vec4 operator*(int a){
		vec4 temp;

		temp.x=x*a;
		temp.y=y*a;
		temp.z=z*a;
		temp.w=w*a;
		
		return temp;
	}

	vec4 operator=(int a){
		vec4 temp;

		temp.x=a;
		temp.y=a;
		temp.z=a;
		temp.w=a;

		return temp;
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