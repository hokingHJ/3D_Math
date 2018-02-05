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
	double x, y, z;
public:
	Vector_3D(){}
	//Copy-constructor.
	Vector_3D(const Vector_3D &vector) : x(vector.x),y(vector.y),z(vector.z){}
	Vector_3D(double x, double y, double z) : x(x), y(y), z(z){}
	void zero() {
		x = y = z = 0.0;
	}
	Vector_3D operator -() {
		return Vector_3D(-x,-y,-z);
	}
	Vector_3D operator *(double coef) const{
		return Vector_3D(coef * x, coef * y, coef * z);
	}
	Vector_3D operator /(double coef) const{
		float reciprocal = 1.0f / coef;
		return Vector_3D(reciprocal * x,reciprocal * y,reciprocal * z);
	}
	//It just returns a new Vector_3D object and do not modify anything of this object.
	Vector_3D operator -(const Vector_3D &vector) {
		return Vector_3D(x - vector.getX(),y - vector.getY(),z - vector.getZ());
	}
	Vector_3D operator +(const Vector_3D &vector) {
		return Vector_3D(x + vector.getX(), y + vector.getY(), z + vector.getZ());
	}
	//The mehtod will chang the values of this object.So no 'cosnt'.
	Vector_3D operator *=(float coef) {
		//The operator * has been overload and I don't want to chang the value respectively.like x*=coef.
		*this = *this * coef;
		return *this;
	}
	//The mehtod will chang the values of this object.So no 'cosnt'.
	Vector_3D operator /=(float coef) {
		//The same reason above.
		*this = *this / coef;
		return *this;
	}
	void normalize() {
		*this /= vectorMag();
	}
	double vectorMag() const{
		return sqrt(x*x+y*y+z*z);
	}
	//This method should be describe by "const",althouth,it just return a value rather than a reference.
	//It is not necessary to worry about modification.
	double getX() const {
		return this->x;
	}
	double getY()  const{
		return this->y;
	}
	double getZ() const {
		return this->z;
	}
};
inline Vector_3D operator *(double coef,const Vector_3D &vector) {
	return Vector_3D(coef * vector.getX(), coef * vector.getY(), coef * vector.getZ());
}
#endif

