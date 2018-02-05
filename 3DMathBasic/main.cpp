#include <iostream>
#include <string>
#include "Vector_3D.h"

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
int main() {
	cout << "Everything is OK!!!" << endl;
	Vector_3D v1(21,34,12);
	print_v("v1",v1);
	Vector_3D v2(v1);
	print_v("v2",v2);
	v2.zero();
	print_v("After zero() v2",v2);
	double magic = v1.vectorMag();
	cout << "v1 magic :"<<magic << endl;
	Vector_3D v3 = -v1;
	print_v("v3(-v1)",v3);
	Vector_3D v4(2, 4, 6);
	Vector_3D v5 = 2 * v4;
	print_v("2*v4(2,4,6)",v5);
	v5 = v4 * 2;
	print_v("v4(2,4,6)*2",v5);
	Vector_3D v6 = v4 / 2;
	print_v("v4/2",v6);

	v5 *= 2;
	v6 /= 2;
	print_v("v5*=2",v5);
	print_v("v6/=2",v6);
	Vector_3D v7(1.8,2.2,3.7);
	Vector_3D v8(2.2,5.8,9.3);
	Vector_3D v9 = v7 - v8;
	Vector_3D v10 = v7 + v8;
	print_v("v7-v8",v9);
	print_v("v7+v8",v10);
	Vector_3D v11(3,4,5);
	v11.normalize();
	print_v("v11(3,4,5) normalize()",v11);
	system("pause");
	return 0;
};