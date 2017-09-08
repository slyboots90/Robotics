//============================================================================
// Name        : Main.cpp
// Author      : Mateusz Fraszczynski
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Denavit-Hartenberg notation implementation in C++, Ansi-style
//============================================================================

#include "../include/HelperFunctions.h"
// Include UI
#include "../include/UI/MainWindow.h"
#include "../include/UI/AddJointWindow.h"
#include "../include/UI/CommonID.h"
// Include Classes
#include "../include/Matrix.h"
#include "../include/MatrixTest.h"
#include "../include/DHparam.h"
#include "../include/Timer.h"
// Include libs
#include <iostream>
#include <windows.h>

using namespace std;

HINSTANCE hInst;
HWND hwnd_main;
HWND hwnd_child;

DHparam * dhp = NULL;

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
LRESULT CALLBACK WindowProcChild( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

int WinMain( HINSTANCE hInst_l , HINSTANCE , LPSTR , int nCmdShow ) {

	#ifdef DEBUG
	    printf("RUNNING DEBUG BUILD\n");
	    MatrixTest start;
	#else
	    printf("Running... this is a release build.");
	#endif

	if ( ! initMainWindow( hwnd_main , hInst ) ) return 0;
	if ( ! initAddJointWindow( hInst ) ) return 0;
	fillMainWindow( hwnd_main , hInst );

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
			DrawText( dc , "Welcome in DH" , -1 , & r , DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			int y_offset = DRAW_TAB_Y;
			for ( unsigned int i = 0 ; i < dhp->getNoOfJoints() + 1 ; i++ , y_offset += COLUMN_HIGH ) {
				drawRowInMainWindowTable( dc , DRAW_TAB_X , y_offset  );
			}
			fillRowsInMainWindowTable( dc , dhp );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD_JOINT: {
					if ( ! createAddJointWindow( hwnd_main , hwnd_child , hInst ) ) break;
					ShowWindow( hwnd_child , SW_SHOW );
				    UpdateWindow( hwnd_child );
					break;
				}
				case ID_BUTTON_SHOW_POS:
					MessageBox( hwnd , "Test", "..." , MB_ICONINFORMATION );
					break;
				case ID_BUTTON_REMOVE_JOINT:
					MessageBox( hwnd , "Test", "..." , MB_ICONINFORMATION );
					break;
				}
			break;
		}
		case WM_PARENTNOTIFY: {
			switch( wparam ) {
				case SIG_SUCCESS:
					//MessageBox( hwnd , "Successful added joint ! " , "Success !" , MB_ICONINFORMATION );
					break;
				case SIG_FAILED:
					//MessageBox( hwnd , "Failed to add joint ! ", "Failed !" , MB_ICONINFORMATION );
					break;
				default:
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
	switch ( msg ) {
		case WM_PAINT: {
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD: {
					if ( verifyAndAddValues( dhp ) ) {

						//HDC hdc = GetWindowDC( hwnd_main );
						HDC hdc = GetWindowDC( GetTopWindow(hwnd));
						SendMessage( hwnd_main , WM_PAINT , ( WPARAM ) hdc , 0 );
						//TODO remove blinking
						ShowWindow( hwnd_main , SW_HIDE );
						UpdateWindow( hwnd_main );
						ShowWindow( hwnd_main , SW_SHOW );
						ReleaseDC( hwnd_main , hdc );
						//MessageBox( NULL , "Successful added joint ! " , "Success !" , MB_ICONINFORMATION );
						//SendMessage( hwnd_main , WM_PARENTNOTIFY , 0 , 0 );
					} else {
						//SendMessage( hwnd_main , WM_PARENTNOTIFY , 0 , 0 );
					}
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
