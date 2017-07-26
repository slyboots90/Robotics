//============================================================================
// Name        : Matrix.cpp
// Author      : Mateusz Fraszczynski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/matrix.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	matrix Eva(1,5);
	//matrix Adam;

	cout << "Eva dimensionX: " << (int) Eva.verifyMatrixDimensionX() << " Eva dimensionY: " << (int) Eva.verifyMatrixDimensionY() << endl;
	//cout << "Adam dimensionX: " << (int) Adam.verifyMatrixDimensionX() << " Adam dimensionY: " << (int) Adam.verifyMatrixDimensionY() << endl;

	//cout << "Eva CapacityX: " << (int) Eva.verifyMatrixCapacityX() << " Eva CapacityY: " << (int) Eva.verifyMatrixCapacityY() << endl;
	//cout << "Adam CapacityX: " << (int) Adam.verifyMatrixCapacityX() << " Adam CapacityY: " << (int) Adam.verifyMatrixCapacityY() << endl;
/*
	Eva.addRow(5);
	Adam.addColumn(7);

	cout << "Eva dimensionX: " << (int) Eva.verifyMatrixDimensionX() << " Eva dimensionY: " << (int) Eva.verifyMatrixDimensionY() << endl;
	cout << "Adam dimensionX: " << (int) Adam.verifyMatrixDimensionX() << " Adam dimensionY: " << (int) Adam.verifyMatrixDimensionY() << endl;

	//cout << "Eva CapacityX: " << (int) Eva.verifyMatrixCapacityX() << " Eva CapacityY: " << (int) Eva.verifyMatrixCapacityY() << endl;
	//cout << "Adam CapacityX: " << (int) Adam.verifyMatrixCapacityX() << " Adam CapacityY: " << (int) Adam.verifyMatrixCapacityY() << endl;
*/

	return 0;
}



