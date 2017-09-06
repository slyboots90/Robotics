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

string AppTitle = "Denavit-Hartenberg notation";
string SubWindowName = "Add Joint";
#define mainWinSizeX 800
#define mainWinSizeY 500
#define childWinSizeX 320
#define childWinSizeY 200

#define ID_BUTTON_ADD_JOINT 	101
#define ID_BUTTON_SHOW_CHAIN 	102
#define ID_BUTTON_REMOVE_JOINT 	103
#define ID_BUTTON_ADD 			104

HINSTANCE hInst;
HWND hwnd_main;
HWND hwnd_child;
HWND button_add_joint;
HWND button_show_chain;
HWND button_remove_joint;
HWND button_add;
HWND d_input;
HWND theta_input;
HWND r_input;
HWND alpha_input;

DHparam * dhp = NULL;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
LRESULT CALLBACK WindowProcChild(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
int initMainWindow( );
void fillMainWindow( );
int initChildWindow( );
void fillChildWindow( );
int createChildWindow( );

int WinMain( HINSTANCE hInst_l , HINSTANCE , LPSTR , int nCmdShow ) {

	#ifdef DEBUG
	    printf("RUNNING DEBUG BUILD\n");
	    MatrixTest start;
	#else
	    printf("Running... this is a release build.");
	#endif

	if ( ! initMainWindow( ) ) return 0;
	if ( ! initChildWindow( ) ) return 0;
	fillMainWindow( );

	dhp = new DHparam();

	ShowWindow( hwnd_main , nCmdShow );
	UpdateWindow( hwnd_main );

	MSG msg;
	while ( GetMessage( & msg , NULL , 0 , 0 ) > 0 ) {
		TranslateMessage( & msg );
		DispatchMessage( & msg );
	}
	delete dhp;
	return msg.wParam;
}

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd , & r );
			dc = BeginPaint( hwnd , & ps );
			DrawText( dc , "Welcom in DH" , -1 , & r , DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD_JOINT: {
					if ( ! createChildWindow( ) ) break;
					ShowWindow( hwnd_child , SW_SHOW );
				    UpdateWindow( hwnd_child );
					break;
				}
				case ID_BUTTON_SHOW_CHAIN:
					MessageBox( hwnd , "Test", "..." , MB_ICONINFORMATION );
					break;
				case ID_BUTTON_REMOVE_JOINT:
					MessageBox( hwnd , "Test", "..." , MB_ICONINFORMATION );
					break;
				}
			break;
		}
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
}

LRESULT CALLBACK WindowProcChild( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	static jointParams jParams;
	switch ( msg ) {
		case WM_PAINT: {
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD: {
//					TCHAR buff[1024];
//					GetWindowText(d_input, buff, 1024);
//					jParams.d = stod(buff);
//					GetWindowText(theta_input, buff, 1024);
//					jParams.theta = stod(buff);
//					GetWindowText(r_input, buff, 1024);
//					jParams.r = stod(buff);
//					GetWindowText(alpha_input, buff, 1024);
//					jParams.alpha = stod(buff);
					DestroyWindow( hwnd_child );
					break;
				}
				default:
					break;
			}
			break;
		}
		case WM_DESTROY: {
			DestroyWindow( hwnd_child );
			break;
		}
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
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
	kin.designateCoordinates( );
}

int initMainWindow( ) {
	WNDCLASS wc;
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
	hwnd_main = CreateWindow( AppTitle.c_str() , AppTitle.c_str() , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , mainWinSizeX , mainWinSizeY , NULL , NULL , hInst , NULL );
	if ( ! hwnd_main ) return 0;
	return 1;
}

int initChildWindow( ) {
	WNDCLASSEX wcx;
	wcx.cbSize = sizeof( wcx );
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WindowProcChild;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInst;
	wcx.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	wcx.hCursor = LoadCursor( NULL , IDC_ARROW );
	wcx.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wcx.lpszMenuName =  NULL;
	wcx.lpszClassName = SubWindowName.c_str();
	wcx.hIconSm = ( HICON ) LoadImage( hInst , MAKEINTRESOURCE( 5 ) , IMAGE_ICON , GetSystemMetrics( SM_CXSMICON ) , GetSystemMetrics( SM_CYSMICON ) , LR_DEFAULTCOLOR );
	if ( ! RegisterClassEx( & wcx ) ) return 0;
	return 1;
}

int createChildWindow( ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , SubWindowName.c_str() , SubWindowName.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , childWinSizeX , childWinSizeY , hwnd_main , NULL , hInst , NULL );
	if ( ! hwnd_child ) return 0;
	fillChildWindow( );
	return 1;
}

void fillMainWindow( ) {
	button_add_joint = CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 0 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_ADD_JOINT , hInst , NULL );
	button_show_chain = CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Show chain" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 30 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_SHOW_CHAIN , hInst , NULL );
	button_remove_joint = CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Remove joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 60 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_REMOVE_JOINT , hInst , NULL );
}

void fillChildWindow( ) {
	HWND hStatic_d = CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	SetWindowText( hStatic_d , " Segment Offset " );
	HWND hStatic_theta = CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 30 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	SetWindowText( hStatic_theta , " Angle of Joint " );
	HWND hStatic_r = CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 60 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	SetWindowText( hStatic_r , " Segment Length " );
	HWND hStatic_alpha = CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 90 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	SetWindowText( hStatic_alpha , " Twist Angle " );
	button_add_joint = CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 120 , 300 , 30 , hwnd_child , ( HMENU ) ID_BUTTON_ADD , hInst , NULL );
	d_input = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER , 150 , 0 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	theta_input = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER , 150 , 30 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	r_input = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER , 150 , 60 , 150 , 30 , hwnd_child , NULL , hInst , NULL );
	alpha_input = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER , 150 , 90 , 150 , 30 , hwnd_child , NULL , hInst , NULL );

}
