//============================================================================
// Name        : Matrix.cpp
// Author      : Mateusz Fraszczynski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "../include/Matrix.h"


using namespace std;

void test(void);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	test();
	return 0;
}

void test() {
	Matrix Eva(4,3);
	Matrix Adam;
	Matrix Pankracy;

	cout << "Eva dimensionX: " << (int) Eva.verifyMatrixDimensionX() << " Eva dimensionY: " << (int) Eva.verifyMatrixDimensionY() << endl;
	cout << "Adam dimensionX: " << (int) Adam.verifyMatrixDimensionX() << " Adam dimensionY: " << (int) Adam.verifyMatrixDimensionY() << endl;


	Adam.addColumn();
	Adam.addColumn();
	Adam.addColumn();
	Adam.addRow();
	Adam.addRow();

	Pankracy.addColumn();
	Pankracy.addColumn();
	Pankracy.addColumn();
	Pankracy.addRow();
	Pankracy.addRow();

	vector<int> a1, a2, a3, a4;
	vector<int> b1, b2, b3;
	vector<int> c1, c2, c3;

	a1.push_back(7);
	a1.push_back(5);
	a1.push_back(8);

	a2.push_back(4);
	a2.push_back(2);
	a2.push_back(1);

	a3.push_back(9);
	a3.push_back(0);
	a3.push_back(2);

	a4.push_back(6);
	a4.push_back(4);
	a4.push_back(8);

	b1.push_back(3);
	b1.push_back(9);
	b1.push_back(0);
	b1.push_back(1);

	b2.push_back(0);
	b2.push_back(8);
	b2.push_back(2);
	b2.push_back(2);

	b3.push_back(7);
	b3.push_back(1);
	b3.push_back(5);
	b3.push_back(6);

	c1.push_back(1);
	c1.push_back(1);
	c1.push_back(1);
	c1.push_back(1);

	c2.push_back(2);
	c2.push_back(2);
	c2.push_back(2);
	c2.push_back(2);

	c3.push_back(3);
	c3.push_back(3);
	c3.push_back(3);
	c3.push_back(3);

	Eva.fillRowWithData(&a1, 0);
	Eva.fillRowWithData(&a2, 1);
	Eva.fillRowWithData(&a3, 2);
	Eva.fillRowWithData(&a4, 3);

	Adam.fillRowWithData(&b1, 0);
	Adam.fillRowWithData(&b2, 1);
	Adam.fillRowWithData(&b3, 2);

	Pankracy.fillRowWithData(&c1, 0);
	Pankracy.fillRowWithData(&c2, 1);
	Pankracy.fillRowWithData(&c3, 2);

	Eva.printMatrix();
	Adam.printMatrix();
	Pankracy.printMatrix();

	cout << "Eva dimensionX: " << (int) Eva.verifyMatrixDimensionX() << " Eva dimensionY: " << (int) Eva.verifyMatrixDimensionY() << endl;
	cout << "Adam dimensionX: " << (int) Adam.verifyMatrixDimensionX() << " Adam dimensionY: " << (int) Adam.verifyMatrixDimensionY() << endl;

	Eva * Adam;
	Pankracy + Adam;

	Eva.printMatrix();
	Adam.printMatrix();
}
