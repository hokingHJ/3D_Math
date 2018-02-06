/*
This is a vector class.
*/
#ifndef __VECTOR_3D_H_INCLUDE__
#define __VECTOR_3D_H_INCLUDE__

#include <math.h>
#include "MathUtil.h"
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
	Vector_3D(const Vector_3D &vector) : x(vector.x),y(vector.y),z(vector.z){}
	Vector_3D(double x, double y, double z) : x(x), y(y), z(z){}
	//Make zero.
	void zero() {
		x = y = z = 0.0;
	}
	Vector_3D operator -() const{
		return Vector_3D(-x,-y,-z);
	}


	Vector_3D operator +(const Vector_3D &vector) const{
		return Vector_3D(x + vector.getX(), y + vector.getY(), z + vector.getZ());
	}
	//It just returns a new Vector_3D object and do not modify anything of this object.
	Vector_3D operator -(const Vector_3D &vector) const{
		return Vector_3D(x - vector.getX(), y - vector.getY(), z - vector.getZ());
	}
	Vector_3D operator *(double coef) const{
		return Vector_3D(coef * x, coef * y, coef * z);
	}
	double operator *(const Vector_3D &vector) const{
		return x * vector.getX() + y * vector.getY() + z * vector.getZ();
	}
	Vector_3D operator /(double coef) const{
		if (coef != 0) {
			double reciprocal = 1.0f / coef;
			return Vector_3D(reciprocal * x,reciprocal * y,reciprocal * z);
		}
		return Vector_3D();
	}

	void operator +=(const Vector_3D &vector) {
		x += vector.getX();
		y += vector.getY();
		z += vector.getZ();
	}
	void operator -=(const Vector_3D &vector) {
		x -= vector.getX();
		y -= vector.getY();
		z -= vector.getZ();
	}

	//The mehtod will chang the values of this object.So no 'cosnt'.
	void operator *=(double coef) {
		//The operator * has been overload and 
		//I don't want to chang the value respectively.like x*=coef.
		//But,it is not necessary to create a new Vector_3D when modifying the object itself.
		//like  *this = *this * coef;
		x *= coef;
		y *= coef;
		z *= coef;
	}

	//The mehtod will chang the values of this object.So no 'cosnt'.
	bool operator /=(double coef) {
		if (coef != 0) {
			x /= coef;
			y /= coef;
			z /= coef;
			return true;
		}
		return false;
	}

	bool isZeroVector() {
		return x==0 && y==0 && z==0;
	}

	//Normalize the vector and then the vector's magic will always be one;
	//And this manipulation will change the object's variables,so no const;
	bool normalize() {
		double magic = this->vectorMag();
		if (magic != 0) {
			*this /= magic;
			return true;
		}
		return false;
	}

	//Compute a vector's magic. 
	double vectorMag() const{
		return sqrt(x*x+y*y+z*z);
	}

	//Compute the cross-multiplication.It is still a vector.
	Vector_3D cross(const Vector_3D &vector) const {
		return Vector_3D(
			y * vector.getZ() - z * vector.getY(),
			z * vector.getX() - x * vector.getZ(),
			x * vector.getZ() - y * vector.getX()
		);
	}


	//Compute the object's radian with another. 
	double arccos_arc(const Vector_3D &vector) const{
		return acos(*this * vector/(this->vectorMag() * vector.vectorMag()));
	}


	//Compute the objects's degree with another.
	double arccos_deg(const Vector_3D &vector) const {
		return arccos_arc(vector) * 180 / PI;
	}


	//Compute the distentce between two vectors.
	double distance(const Vector_3D &vector) {
		return (*this - vector).vectorMag();
	}


	//This method should be describe by "const",althouth,
	//it just return a value rather than a reference.
	//It is not necessary to worry about modification.
	double getX() const{
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

