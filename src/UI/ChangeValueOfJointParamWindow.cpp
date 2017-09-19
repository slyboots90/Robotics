/*
 * ChangeValueOfJointParamWindow.cpp
 *
 *  Created on: 18 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/ChangeValueOfJointParamWindow.h"
#include "../../include/UI/CommonID.h"
// Include Classes
// Include libs
#include <iostream>

using namespace std;

string SubWindowName_JP = "Change value of joint param";

LRESULT CALLBACK WindowProcChild_ChangeJointParam( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

int initChangeValueOfJointParamWindow( HINSTANCE & hInst ) {
	WNDCLASSEX wcx;
	wcx.cbSize = sizeof( wcx );
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WindowProcChild_ChangeJointParam;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInst;
	wcx.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	wcx.hCursor = LoadCursor( NULL , IDC_ARROW );
	wcx.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wcx.lpszMenuName =  NULL;
	wcx.lpszClassName = SubWindowName_JP.c_str();
	wcx.hIconSm = ( HICON ) LoadImage( hInst , MAKEINTRESOURCE( 5 ) , IMAGE_ICON , GetSystemMetrics( SM_CXSMICON ) , GetSystemMetrics( SM_CYSMICON ) , LR_DEFAULTCOLOR );
	if ( ! RegisterClassEx( & wcx ) ) return 0;
	return 1;
}

int createChangeValueOfJointParamWindow( HWND & hwnd_main , HWND & hwnd_child , HINSTANCE & hInst , WPARAM wparam ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , SubWindowName_JP.c_str() , SubWindowName_JP.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_JP_SIZE_X , WIN_JP_SIZE_Y , hwnd_main , NULL , hInst , NULL );
	if ( ! hwnd_child ) return 0;
	SendMessage( hwnd_child , WM_CREATE , wparam , ( LPARAM ) WIN_JP_LPCREATE );		// WIN_JP_LPCREATE: need to pass wparam with joint index to the window
	return 1;
}

void fillChangeValueOfJointParamWindow( HWND & hwnd_child , HINSTANCE & hInst , DHparam * dhp , unsigned int index ) {

}
