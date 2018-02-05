/*
This is a math util for compulating some complex arithemetic problems.
*/
#ifndef __MATHUTIL_H_INCLUDE__
#define __MATHUTIL_H_INCLUDE__
#include <math.h>
#define PI 3.1415926535

//Compute the sin and cos value an return to the invoking palce.
inline void sinCos(double *sinValue,double *cosValue,double theta) {
	*sinValue = sin(theta);
	*cosValue = cos(theta);
}
#endif // !__MATHUTIL_H_INCLUDE__

