/*
 * AddJointWindow.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */
// Include UI
#include "../../include/UI/AddJointWindow.h"
#include "../../include/UI/CommonID.h"
// Include libs
#include <iostream>

using namespace std;

string SubWindowName_AJ = "Add Joint";

HWND input[ INPUT_BOXES ];

LRESULT CALLBACK WindowProcChild_AddJoint( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

int initAddJointWindow( HINSTANCE & hInst ) {
	WNDCLASSEX wcx;
	wcx.cbSize = sizeof( wcx );
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WindowProcChild_AddJoint;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInst;
	wcx.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	wcx.hCursor = LoadCursor( NULL , IDC_ARROW );
	wcx.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wcx.lpszMenuName =  NULL;
	wcx.lpszClassName = SubWindowName_AJ.c_str();
	wcx.hIconSm = ( HICON ) LoadImage( hInst , MAKEINTRESOURCE( 5 ) , IMAGE_ICON , GetSystemMetrics( SM_CXSMICON ) , GetSystemMetrics( SM_CYSMICON ) , LR_DEFAULTCOLOR );
	if ( ! RegisterClassEx( & wcx ) ) return 0;
	return 1;
}

int createAddJointWindow( HWND & hwnd_main , HWND & hwnd_child , HINSTANCE & hInst ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , SubWindowName_AJ.c_str() , SubWindowName_AJ.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_AJ_SIZE_X , WIN_AJ_SIZE_Y , hwnd_main , NULL , hInst , NULL );
	if ( ! hwnd_child ) return 0;
	fillAddJointWindow( hwnd_child , hInst );
	return 1;
}

void fillAddJointWindow( HWND & hwnd_child , HINSTANCE & hInst ) {
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Offset " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 20 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Angle of Joint " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 40 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Length " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 60 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Twist Angle " );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 80 , 310 , 30 , hwnd_child , ( HMENU ) ID_BUTTON_ADD , hInst , NULL );
	int x_offset, y_offset = 0;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		i % 2 ? x_offset = 235 : x_offset = 150;
		input[ i ] = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER, x_offset , y_offset , 75 , 20 , hwnd_child , NULL , hInst , NULL );
		if ( x_offset == 235 ) y_offset += 20;
	}
	for ( unsigned int i = 0 ; i < INPUT_BOXES / 2 ; i++ ) {
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | ES_CENTER , 225 , i * 20 , 10 , 20 , hwnd_child , NULL , hInst , NULL ) , "." );
	}
}
