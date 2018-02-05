#include <iostream>
#include <string>
#include "Vector_3D.h"
#include "Matrix3x3.h"
#include "MathUtil.h"

using namespace std;

/**
	2018-02-04/night.Sunday.
		Now I beggin to study some basic knowledge about computer graphics,so I choose 
	C++ language for my tool.
		Firstly,I have to learn the IDE's introduction.And then I arbitrarily knocked some code,
	as you can see.Fortunately,it really works good.I am glad to have a grate start.

*/
void print_v(string name,Vector_3D &vector) {
	cout << name<<":"<<"[" << vector.getX() << "," << vector.getY()<< "," << vector.getZ()<< "]" << endl;
}

void print_m(string name,Matrix3x3 &matrix) {
	cout << name << ":" << endl;
	cout << matrix.m11 << "\t" << matrix.m12 << "\t" << matrix.m13 << endl;
	cout << matrix.m21 << "\t" << matrix.m22 << "\t" << matrix.m23 << endl;
	cout << matrix.m31 << "\t" << matrix.m32 << "\t" << matrix.m33 << endl;
}
int main() {
	cout << "Everything is OK!!!" << endl;
	Matrix3x3 m1;
	Vector_3D v1(10.0,0.0,0.0),v2;
	m1.setRotateMatrix(2,PI);
	v2 = v1 * m1;
	print_v("v2",v2);
	system("pause");
	return 0;
};