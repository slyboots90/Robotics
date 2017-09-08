/*
 * ui.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */
#include "../../include/UI/MainWindow.h"
#include "../../include/UI/CommonID.h"

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
	hwnd_main = CreateWindow( AppTitle.c_str() , AppTitle.c_str() , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , MAIN_WIN_SIZE_X , MAIN_WIN_SIZE_Y , NULL , NULL , hInst , NULL );
	if ( ! hwnd_main ) return 0;
	return 1;
}

void fillMainWindow( HWND & hwnd_main , HINSTANCE & hInst ) {
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 0 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_ADD_JOINT , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Show position" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 30 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_SHOW_POS , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Remove joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 60 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_REMOVE_JOINT , hInst , NULL );
}
