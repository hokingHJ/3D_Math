#include <assert.h>
#include "Matrix3x3.h"
#include "Vector_3D.h"
#include "MathUtil.h"

//Matrix multiplication.It looks boring.
Matrix3x3 operator*(const Matrix3x3 &a, const Matrix3x3 &b)
{
	Matrix3x3 m;
	m.m11 = a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
	m.m12 = a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
	m.m13 = a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;

	m.m21 = a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
	m.m22 = a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
	m.m23 = a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

	m.m31 = a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
	m.m32 = a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
	m.m33 = a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;
	return m;
}
//It is from here.As if I grip something about the distinction of left value and right value.
Vector_3D operator*(const Vector_3D & v, const Matrix3x3 & m)
{
	Vector_3D vec(
		v.getX() * m.m11 + v.getY() * m.m21 + v.getZ() * m.m31,
		v.getX() * m.m12 + v.getY() * m.m22 + v.getZ() * m.m32,
		v.getX() * m.m13 + v.getY() * m.m23 + v.getZ() * m.m33
	);
	return vec;
}

Matrix3x3 & operator*=(Matrix3x3 & a, const Matrix3x3 & b)
{				
	a = a*b;
	return a;
}	

Vector_3D &operator*=(Vector_3D & v, const Matrix3x3 & m)
{
	v = v * m;
	return v;
}
//Initialize specifically the rotation matrix  circling with a spcial axis and degree. 
void Matrix3x3::setRotateMatrix(int axis, double theta)
{
	double sin, cos;
	sinCos(&sin,&cos,theta);
	switch (axis) {
	case 1:
		m11 = 1.0; m12 = 0.0; m13 = 0.0;
		m21 = 0.0; m22 = cos; m23 = sin;
		m31 = 0.0; m32 = -sin; m33 = cos;
		break;
	case 2:
		m11 = cos; m12 = 0.0; m13 = -sin;
		m21 = 0.0; m22 = 1.0; m23 = 0.0;
		m31 = sin; m32 = 0.0; m33 = cos;
		break;
	case 3:
		m11 = cos; m12 = sin; m13 = 0.0;
		m21 = -sin; m22 = cos; m23 = 0.0;
		m31 = 0.0; m32 = 0.0; m33 = 1.0;
		break;
	default:
		assert(false);
	}
}

void Matrix3x3::setScaleMatrix(const Vector_3D & vector)
{
	m11 = vector.getX(); m12 = 0.0; m13 = 0.0;
	m21 = 0.0; m22 = vector.getY(); m23 = 0.0;
	m31 = 0.0; m32 = 0.0; m33 = vector.getZ();
}

bool Matrix3x3::setPorjectMatrix(Vector_3D & vector) 
{	//Maybe it is not necessary,but if the vector is not a unit vector,
	//everything will be terrible.
	if (vector.normalize()) {
		m11 = 1 - vector.getX() * vector.getX();
		m22 = 1 - vector.getY() * vector.getY();
		m33 = 1 - vector.getZ() * vector.getZ();

		m12 = m21 = -vector.getX() * vector.getY();
		m13 = m31 = -vector.getX() * vector.getZ();
		m23 = m32 = -vector.getY() * vector.getZ();
		return true;
	}
	return false;
}

void Matrix3x3::setReflect(int axis)
{
	switch(axis) {
	case 1:
		m11 = -1.0;		m12 = 0;		m13 = 0;
		m21 = 0;		m22 = 1.0;		m23 = 0;
		m31 = 0;		m32 = 0;		m33 = 1.0;
		break;
	case 2:
		m11 = 1.0;		m12 = 0;		m13 = 0;
		m21 = 0;		m22 = -1.0;		m23 = 0;
		m31 = 0;		m32 = 0;		m33 = 1.0;
		break;
	case 3:
		m11 = 1.0;		m12 = 0;		m13 = 0;
		m21 = 0;		m22 = 1.0;		m23 = 0;
		m31 = 0;		m32 = 0;		m33 = -1.0;
		break;
	default :
		assert(false);
	}
}

bool Matrix3x3::setReflect(Vector_3D & vector)
{
	if (vector.normalize()) {
		double vx = vector.getX();
		double vy = vector.getY();
		double vz = vector.getZ();
		m11 = 1.0 - 2.0 * vx * vx;
		m22 = 1.0 - 2.0 * vy * vy;
		m33 = 1.0 - 2.0 * vz * vz;
		
		m12 = m21 = -2.0 * vx * vy;
		m13 = m31 = -2.0 * vx * vz;
		m23 = m32 = -2.0 * vy * vz;
	}
	return false;
}

void Matrix3x3::setShear(int axis, double fcoef, double scoef)
{
	switch (axis) {
	case 1:
		//Shear in X axis direction.
		m11 = 1.0;		m12 = fcoef;		m13 = scoef;
		m21 = 0;		m22 = 1.0;			m23 = 0;
		m31 = 0;		m32 = 0;			m33 = 1.0;
		break;
	case 2:
		//Shear in Y axis direction.
		m11 = 1.0;		m12 = 0;	m13 = 0;
		m21 = fcoef;	m22 = 1.0;	m23 = scoef;
		m31 = 0;		m32 = 0;	m33 = 1.0;
		break;
	case 3:
		//Shear in Z axis direction.
		m11 = 1.0;		m12 = 0;		m13 = 0;
		m21 = 0;		m22 = 1.0;		m23 = 0;
		m31 = fcoef;	m32 = scoef;	m33 = 1.0;
		break;
	default:
		assert(false);
	}
}
