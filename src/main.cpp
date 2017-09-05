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
#include <windows.h>

using namespace std;

void dh( void );

string AppTitle = "DHparams";
#define winSizeX 500
#define winSizeY 100

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WinMain( HINSTANCE hInst , HINSTANCE , LPSTR , int nCmdShow ) {

	WNDCLASS wc;
	HWND hwnd;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon( NULL , IDI_WINLOGO );
	wc.hCursor = LoadCursor( NULL , IDC_ARROW );
	wc.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = AppTitle.c_str();

	if ( ! RegisterClass( & wc ) ) return 0;

	hwnd = CreateWindow( AppTitle.c_str() , AppTitle.c_str() , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , winSizeX , winSizeY , NULL , NULL , hInst , NULL );

	if ( ! hwnd ) return 0;

	ShowWindow( hwnd , nCmdShow );
	UpdateWindow( hwnd );

	while ( GetMessage( & msg , NULL , 0 , 0 ) > 0 ) {
		TranslateMessage( & msg );
		DispatchMessage( & msg );
	}
	return 0;
}

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd , & r );
			dc = BeginPaint( hwnd , & ps );
			DrawText( dc , "Hello World" , -1 , & r , DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
}

//int main() {
//#ifdef DEBUG_BUILD
//    printf("RUNNING DEBUG BUILD");
//    MatrixTest start;
//#else
//    printf("Running... this is a release build.");
//#endif
//	//dh();
//	return 0;
//}

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
	kin.designateCoordinates();
}
