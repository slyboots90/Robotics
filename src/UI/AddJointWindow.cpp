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

//TODO avoid global if possible
HWND input[ INPUT_BOXES ];
HWND listbox;

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
	return 1;
}

void fillAddJointWindow( HWND & hwnd_child , HINSTANCE & hInst ) {
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Offset " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 20 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Angle of Joint " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 40 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Length " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 60 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Twist Angle " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 80 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Angle units " );
	listbox = CreateWindowEx( WS_EX_CLIENTEDGE , "COMBOBOX" , NULL , WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST , 150 , 80 , 150 , 100 , hwnd_child , NULL , hInst , NULL );
	SendMessage( listbox , CB_ADDSTRING , 0 , ( LPARAM ) "Degrees" );
	SendMessage( listbox , CB_ADDSTRING , 0 , ( LPARAM ) "Radians" );
	SendMessage( listbox , CB_SETCURSEL , (WPARAM) 0 , 0 );			// Set default value to Degrees
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 100 , 300 , 30 , hwnd_child , ( HMENU ) ID_BUTTON_ADD , hInst , NULL );
	int x_offset = 150 , y_offset = 0;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		input[ i ] = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , x_offset , y_offset , 150 , 20 , hwnd_child , NULL , hInst , NULL );
		y_offset += 20;
	}
}
