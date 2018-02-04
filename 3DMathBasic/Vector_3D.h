#ifndef __VECTOR_3D_H_INCLUDE__
#define __VECTOR_3D_H_INCLUDE__

#include <math.h>
/*
		This class is crated for a 3D vector,a mathematical concept,that contain three numbers
	(x,y,z) respectively representing different dimensions.
		I think the variables in the class should be modified by private,that symblizes a good 
	encapsulation of the class.
*/

class Vector_3D {
private:
	float x, y, z;
public:
	Vector_3D(){}
	Vector_3D(const Vector_3D &vector) : x(vector.x),y(vector.y),z(vector.z){}
	Vector_3D(float a, float b, float c) : x(a), y(b), z(c){}
	void zero() {
		x = y = z = 0.0f;
	}
	Vector_3D operator -() {
		return Vector_3D(-x,-y,-z);
	}
	float getX() const {
		return x;
	}
	float getY()  const{
		return y;
	}
	float getZ() const {
		return z;
	}
};
inline float vectorMag(Vector_3D v) {
	return sqrt(v.getX()* v.getX() + v.getY() * v.getY() + v.getZ() * v.getZ());
}
#endif

