//============================================================================
// Name        : Matrix.cpp
// Author      : Mateusz Fraszczynski
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/Matrix.h"
#include "../include/MatrixTest.h"
#include "../include/DHparam.h"
#include "../include/Timer.h"

using namespace std;

void test(void);
void dh(void);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	MatrixTest start;
	test();
	dh();
	return 0;
}

void test() {

	//Matrix Eva(4,3);
	//Eva.printMatrix();
//	Matrix Adam;

//	Matrix Pankracy;
//
//	Adam.addColumn();
//	Adam.addColumn();
//	Adam.addColumn();
//	Adam.addColumn();
//	Adam.addRow();
//	Adam.addRow();
//	Adam.addRow();

//
//	Pankracy.addColumn();
//	Pankracy.addColumn();
//	Pankracy.addColumn();
//	Pankracy.addRow();
//	Pankracy.addRow();
//
	vector<double> a1, a2, a3, a4, a5;
	vector<double> b1, b2, b3;
	vector<double> c1, c2, c3;

	a1.push_back(7);
	a1.push_back(5);
	a1.push_back(8);
	a1.push_back(6);
	a1.push_back(2);

	a2.push_back(4);
	a2.push_back(2);
	a2.push_back(1);
	a2.push_back(12);
	a2.push_back(33);

	a3.push_back(9);
	a3.push_back(0);
	a3.push_back(2);
	a3.push_back(7);
	a3.push_back(23);

	a4.push_back(14);
	a4.push_back(16);
	a4.push_back(6);
	a4.push_back(4);
	a4.push_back(8);

	a5.push_back(7);
	a5.push_back(5);
	a5.push_back(8);
	a5.push_back(6);
	a5.push_back(2);
//
	b1.push_back(3);
	b1.push_back(9);
	b1.push_back(0);
	b1.push_back(1);

	b2.push_back(0);
	b2.push_back(8);
	b2.push_back(2);
	b2.push_back(2);

	b3.push_back(78);
	b3.push_back(1);
	b3.push_back(5);
	b3.push_back(6);
//
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
//
//	Eva.fillRowWithData(&a1, 0);
//	Eva.fillRowWithData(&a2, 1);
//	Eva.fillRowWithData(&a3, 2);
//	Eva.fillRowWithData(&a4, 3);
//
//	Adam.fillRowWithData(&b1, 0);
//	Adam.fillRowWithData(&b2, 1);
//	Adam.fillRowWithData(&b3, 2);
//	Adam.fillRowWithData(&b1, 3);
////
//	Pankracy.fillRowWithData(&c1, 0);
//	Pankracy.fillRowWithData(&c2, 1);
//	Pankracy.fillRowWithData(&c3, 2);

	//Eva.printMatrix();
	//Adam.printMatrix();
	//Pankracy.printMatrix();

	//cout << "Eva dimensionX: " << (int) Eva.verifyMatrixDimensionX() << " Eva dimensionY: " << (int) Eva.verifyMatrixDimensionY() << endl;
	//cout << "Adam dimensionX: " << (int) Adam.verifyMatrixDimensionX() << " Adam dimensionY: " << (int) Adam.verifyMatrixDimensionY() << endl;

	Timer * a = new Timer;
	//Matrix Ziom(4,4);
	//Ziom.fillRowWithData(&c3, 0);
	//Ziom.printMatrix();
	//Ziom = Eva * Adam;
	//Pankracy + Adam;
	{
		Matrix rrrr(5,5);
		rrrr.fillRowWithData(&a1, 0);
		rrrr.fillRowWithData(&a2, 1);
		rrrr.fillRowWithData(&a3, 2);
		rrrr.fillRowWithData(&a4, 3);
		rrrr.fillRowWithData(&a5, 4);
		printf( "TUTUTUT");
		rrrr.printMatrix();
		//rrrr.printMatrix();
#include <stdio.h>
		//printf ("Det : %d \n" , rrrr.det() );
		//printf ("rank : %d \n" , rrrr.rank() );
		//Adam.printMatrix();
		//Ziom = rrrr - Adam;
		//Ziom = rrrr + Adam;
		//Ziom = rrrr * Adam;
		//Ziom.printMatrix();
		//Ziom =  rrrr * 2;
	}
	delete a;
	Timer * ax = new Timer;
	Matrix s(5,5);
	double tab0[5] = { 4 ,  3 ,-5, 2, 3};
	double tab1[5] = {8 ,6 ,-7, 4, 2};
	double tab2[5] = {4 ,3 ,-8, 2, 7};
	double tab3[5] = {4 ,3 ,1 ,2, -5};
	double tab4[5] = {8 ,6 ,-1 ,4, -6};
	s.fillRowWithData(tab0, 0);
	s.fillRowWithData(tab1, 1);
	s.fillRowWithData(tab2, 2);
	s.fillRowWithData(tab3, 3);
	s.fillRowWithData(tab4, 4);
	s.printMatrix();
	printf ("rank : %d \n" , s.rank() );

	s.eraseRow( 0 );
	s.eraseRow( 0 );
	s.printMatrix();
	printf ("rank : %d \n" , s.rank() );
	delete ax;
	Timer * ac = new Timer;
	Matrix sr(5,5);
	double atab0[5] = { 0 ,  3 ,-5, 2, 3};
	double atab1[5] = {8 ,6 ,-7, 4, 2};
	double atab2[5] = {0 ,0 ,0, 3, 0};
	double atab3[5] = {4 ,3 ,1 ,2, -5};
	double atab4[5] = {8 ,6 ,-1 ,4, -6};

	sr.fillRowWithData(atab2, 2);

	sr.printMatrix();
	printf ("rank : %d \n" , sr.rank() );
	delete ac;
	Timer * av = new Timer;
	Matrix srb(5,5);
	double abtab0[5] = { 1 ,  0 ,1, 0, 0};
	double abtab1[5] = {0 ,0 ,0, 1, 0};
	double abtab2[5] = {0 ,1 ,0, 0, 0};
	double abtab3[5] = {0 ,0 ,0 ,0, 0};
	double abtab4[5] = {1 ,0 ,0 ,0, 1};

	srb.fillRowWithData(abtab0, 0);
	srb.fillRowWithData(abtab1, 1);
	srb.fillRowWithData(abtab2, 2);
	srb.fillRowWithData(abtab3, 3);
	srb.fillRowWithData(abtab4, 4);

	srb.printMatrix();
	printf ("rank : %d \n" , srb.rank() );
	delete av;
	Timer * ab = new Timer;
	srb.eraseColumn( 3 );
	srb.eraseColumn( 0 );
	srb.printMatrix();
	printf ("rank : %d \n" , srb.rank() );
	delete ab;

	//}
	//Ziom.printMatrix();
	//{
	//	Matrix Maciek(4,4);
	//}
	//Eva.printMatrix();
	//Adam.printMatrix();
	//{
	//Matrix Huh(4,3);
	//Huh = Adam;
	//}
	//Adam.printMatrix();
}

void dh() {
	DHparam kin;
	jointParams st;
	st.alpha = 30;
	st.d = 4;
	st.r = 12;
	st.theta = 90;
	kin.addJointParams( st );
	kin.addJointParams( st );
	kin.transformation( 2 );
}
