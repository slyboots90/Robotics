/*
 * ShowPosition.cpp
 *
 *  Created on: 11 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/ShowPositionWindow.h"
// Include Classes
// Include libs
#include <iostream>

using namespace std;

string SubWindowName_SP = "Show Position";

LRESULT CALLBACK WindowProcChild_ShowPosition( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

int initShowPositionWindow( HINSTANCE & hInst ) {
	WNDCLASSEX wcx;
	wcx.cbSize = sizeof( wcx );
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WindowProcChild_ShowPosition;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInst;
	wcx.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	wcx.hCursor = LoadCursor( NULL , IDC_ARROW );
	wcx.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wcx.lpszMenuName =  NULL;
	wcx.lpszClassName = SubWindowName_SP.c_str();
	wcx.hIconSm = ( HICON ) LoadImage( hInst , MAKEINTRESOURCE( 5 ) , IMAGE_ICON , GetSystemMetrics( SM_CXSMICON ) , GetSystemMetrics( SM_CYSMICON ) , LR_DEFAULTCOLOR );
	if ( ! RegisterClassEx( & wcx ) ) return 0;
	return 1;
}

int createShowPositionWindow( HWND & hwnd_main , HWND & hwnd_child , HINSTANCE & hInst ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , SubWindowName_SP.c_str() , SubWindowName_SP.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_SP_SIZE_X , WIN_SP_SIZE_Y , hwnd_main , NULL , hInst , NULL );
	if ( ! hwnd_child ) return 0;
	fillShowPositionWindow( hwnd_child , hInst );
	return 1;
}

void fillShowPositionWindow( HWND & hwnd_child , HINSTANCE & hInst ) {

}
