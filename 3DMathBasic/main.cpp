#include <iostream>
#include "Vector_3D.h"

using namespace std;

/**
	2018-02-04/night.Sunday.
		Now I beggin to study some basic knowledge about computer graphics,so I choose 
	C++ language for my tool.
		Firstly,I have to learn the IDE's introduction.And then I arbitrarily knocked some code,
	as you can see.Fortunately,it really works good.I am glad to have a grate start.

*/
void print_v(Vector_3D &vector) {
	cout << "[" << vector.getX() << "," << vector.getY()<< "," << vector.getZ()<< "]" << endl;
}

int main() {
	cout << "Everything is OK!!!" << endl;
	Vector_3D v1(21,34,12);
	print_v(v1);
	Vector_3D v2(v1);
	print_v(v2);
	v2.zero();
	print_v(v2);
	float magic = vectorMag(v1);
	cout << magic << endl;
	Vector_3D v3 = -v1;
	print_v(v3);
	print_v(v1);
	system("pause");
	return 0;
};