#ifndef __MATRIX_H_INCLUDE__
#define __MATRIX_H_INCLUDE__
/*
	A matrix definition.
*/
class Vector_3D;
class Matrix3x3 {
public:
	double m11, m12, m13;
	double m21, m22, m23;
	double m31, m32, m33;
	void setRotateMatrix(int axis,double theta);
	void setScaleMatrix(const Vector_3D &vector);
	bool setPorjectMatrix(Vector_3D &vector);
	void setReflect(int axis);
	bool setReflect(Vector_3D & vector);
	void setShear(int axis,double fcoef,double scoef);
};

//Below,there are two function.Both of them return a value rather a reference 
//( like Matrix3x3 & operator *(const Matrix3x3 &a,const Matrix3x3 &b)),because
//they just do some boring compulating and change nothing about the parameters,of course,
//they also can do that.if i just use that form ,the compiler will not be happy.
Matrix3x3 operator *(const Matrix3x3 &a,const Matrix3x3 &b);
Vector_3D operator *(const Vector_3D &v,const Matrix3x3 &m);

//According to the convention,the first parameter will be override by the operator's result.
//So,it is necessary for the first parameter to be accessed.
Matrix3x3 &operator *=(Matrix3x3 &a, const Matrix3x3 &b);
Vector_3D &operator *=(Vector_3D &v,const Matrix3x3 &m);

#endif // !__MATRIX_H_INCLUDE__

