/*
 * ui.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */
// Include UI
#include "../../include/UI/MainWindow.h"
#include "../../include/UI/CommonID.h"
// Include libs
#include <iostream>

using namespace std;

string AppTitle = "Denavit-Hartenberg notation";

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

int initMainWindow( HWND & hwnd_main , HINSTANCE & hInst ) {
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
	return 1;
}

int createMainWindow( HWND & hwnd_main , HINSTANCE & hInst ) {
	hwnd_main = CreateWindow( AppTitle.c_str() , AppTitle.c_str() , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , MAIN_WIN_SIZE_X , MAIN_WIN_SIZE_Y , NULL , NULL , hInst , NULL );
	if ( ! hwnd_main ) return 0;
	fillMainWindow( hwnd_main , hInst );
	return 1;
}

void fillMainWindow( HWND & hwnd_main , HINSTANCE & hInst ) {
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 0 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_ADD_JOINT , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Show position" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 30 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_SHOW_POS , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Remove joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 60 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_REMOVE_JOINT , hInst , NULL );
}

void drawRowInMainWindowTable( HDC & dc , int x_start , int y_start ) {
	int x_current = x_start;
	int y_current = y_start;
	for ( unsigned int i = 0 ; i < TABLE_COLUMNS ; i++ ) {
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

void fillRowsInMainWindowTable( HDC & dc , DHparam * dhp ) {
	for ( unsigned int i = 0 ; i < dhp->getNoOfJoints() + 1 ; i++ ) {
		if ( ! i ) {
			TextOut( dc , 230 , 38 , TEXT( "Joint" ) , 5 );
			TextOut( dc , 230 + 100 , 38 , TEXT( "  d  " ) , 5 );
			TextOut( dc , 230 + 200 , 38 , TEXT( "theta" ) , 5 );
			TextOut( dc , 230 + 300 , 38 , TEXT( "  r  " ) , 5 );
			TextOut( dc , 230 + 400 , 38 , TEXT( "alpha" ) , 5 );
		} else {
			const jointParams * params = dhp->getJointParams( i - 1 );
			if ( params == NULL ) return;
			for ( unsigned int j = 0 ; j < TABLE_COLUMNS ; j++ ) {
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
