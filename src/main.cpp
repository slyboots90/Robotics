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
#include <sstream>
#include "../include/UI.h"

using namespace std;

#define SIG_SUCCESS				500
#define SIG_FAILED				501

#define DRAW_ROW				700
#define DRAW_TAB_X				200
#define DRAW_TAB_Y				 30
#define COLUMN_WIDTH 			100
#define COLUMN_HIGH				 30

HINSTANCE hInst;
HWND hwnd_main;
HWND hwnd_child;

extern HWND input[ INPUT_BOXES ];

DHparam * dhp = NULL;
unsigned int no_of_joints;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
LRESULT CALLBACK WindowProcChild(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

bool verifyAndAddValues( );
double getValues( unsigned int );
void drawRow( HDC , int , int );
void fillRows( HDC );

int WinMain( HINSTANCE hInst_l , HINSTANCE , LPSTR , int nCmdShow ) {

	#ifdef DEBUG
	    printf("RUNNING DEBUG BUILD\n");
	    MatrixTest start;
	#else
	    printf("Running... this is a release build.");
	#endif

	if ( ! initMainWindow( hwnd_main , hInst ) ) return 0;
	if ( ! initChildWindow( hInst ) ) return 0;
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
			DrawText( dc , "Welcom in DH" , -1 , & r , DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			int y_offset = DRAW_TAB_Y;
			for ( unsigned int i = 0 ; i < no_of_joints + 1 ; i++ , y_offset += 30 ) {
				drawRow( dc , DRAW_TAB_X , y_offset  );
			}
			fillRows( dc );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD_JOINT: {
					if ( ! createChildWindow( hwnd_main , hwnd_child , hInst ) ) break;
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
					if ( verifyAndAddValues( ) ) {
						no_of_joints++;
						HDC hdc = GetWindowDC( hwnd_main );
						SendMessage( hwnd_main , WM_PAINT , ( WPARAM ) hdc , 0 );
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

bool verifyAndAddValues( ) {
	if ( dhp == NULL ) return false;
	jointParams jParams;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i += 2 ) {
		double value = getValues( i );
		switch ( i ) {
				case 0:
					jParams.d = value;
					break;
				case 2: {
					if ( ! (value < 360 && value > -360) ) return false;
					jParams.theta = value;
					break;
				}
				case 4:
					jParams.r = value;
					break;
				case 6: {
					if ( ! (value < 360 && value > -360) ) return false;
					jParams.alpha = value;
					break;
				}
				default:
					break;
		}
	}
	dhp->addJointParams( jParams );
	return true;
}

double getValues( unsigned int index ) {
	TCHAR buff_h[ 20 ];
	TCHAR buff_l[ 20 ];
	GetWindowText( input[ index ] , buff_h , 20 );
	GetWindowText( input[ index + 1 ] , buff_l , 20 );
	string doubl_h = buff_h ;
	string doubl_l = buff_l ;
	string string_v = doubl_h + "." + doubl_l;
	double double_v = atof( string_v.c_str( ) );
	return double_v;
}

void drawRow( HDC dc , int x_start , int y_start ) {
	int x_current = x_start;
	int y_current = y_start;
	for ( unsigned int i = 0 ; i < 5 ; i++ ) {
		MoveToEx( dc , x_current , y_current , NULL );
		x_current += COLUMN_WIDTH;
		LineTo( dc , x_current , y_current );
		y_current += COLUMN_HIGH;
		LineTo( dc , x_current , y_current );
		x_current -= COLUMN_WIDTH;
		LineTo( dc , x_current , y_current );
		y_current -= COLUMN_HIGH;
		LineTo( dc , x_current , y_current );
		x_current += COLUMN_WIDTH;
	}
}

void fillRows( HDC dc ) {
	for ( unsigned int i = 0 ; i < no_of_joints + 1 ; i++ ) {
		if ( ! i ) {
			TextOut( dc , 230 , 38 , TEXT( "Joint" ) , 5 );
			TextOut( dc , 230 + 100 , 38 , TEXT( "  d  " ) , 5 );
			TextOut( dc , 230 + 200 , 38 , TEXT( "theta" ) , 5 );
			TextOut( dc , 230 + 300 , 38 , TEXT( "  r  " ) , 5 );
			TextOut( dc , 230 + 400 , 38 , TEXT( "alpha" ) , 5 );
		} else {
			const jointParams * params = dhp->getJointParams( i - 1 );
			if ( params == NULL ) return;
			for ( unsigned int j = 0 ; j < 5 ; j++ ) {
				ostringstream ss_value;
				string str_value;
				switch ( j ) {
					case 0: {
						ss_value << i;
						str_value = ss_value.str();
						break;
					}
					case 1: {
						ss_value << params->d;
						str_value = ss_value.str();
						break;
					}
					case 2: {
						ss_value << params->theta;
						str_value = ss_value.str();
						break;
					}
					case 3: {
						ss_value << params->r;
						str_value = ss_value.str();
						break;
					}
					case 4: {
						ss_value << params->alpha;
						str_value = ss_value.str();
						break;
					}
				}
				TextOut( dc , 230 + ( j * 100 ) , 38 + ( i * COLUMN_HIGH ) , TEXT( str_value.c_str() ) , str_value.size() );
			}
		}
	}
}
