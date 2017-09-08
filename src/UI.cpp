/*
 * ui.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */
#include <iostream>
#include "../include/UI.h"

using namespace std;

string AppTitle = "Denavit-Hartenberg notation";
string SubWindowName = "Add Joint";

HWND input[ INPUT_BOXES ];

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
LRESULT CALLBACK WindowProcChild( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

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
	hwnd_main = CreateWindow( AppTitle.c_str() , AppTitle.c_str() , WS_OVERLAPPEDWINDOW , CW_USEDEFAULT , CW_USEDEFAULT , mainWinSizeX , mainWinSizeY , NULL , NULL , hInst , NULL );
	if ( ! hwnd_main ) return 0;
	return 1;
}

int initChildWindow( HINSTANCE & hInst ) {
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

int createChildWindow( HWND & hwnd_main , HWND & hwnd_child , HINSTANCE & hInst ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , SubWindowName.c_str() , SubWindowName.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , childWinSizeX , childWinSizeY , hwnd_main , NULL , hInst , NULL );
	if ( ! hwnd_child ) return 0;
	fillChildWindow( hwnd_child , hInst );
	return 1;
}

void fillMainWindow( HWND & hwnd_main , HINSTANCE & hInst ) {
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 0 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_ADD_JOINT , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Show position" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 30 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_SHOW_CHAIN , hInst , NULL );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Remove joint" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 60 , 150 , 30 , hwnd_main , ( HMENU ) ID_BUTTON_REMOVE_JOINT , hInst , NULL );
}

void fillChildWindow( HWND & hwnd_child , HINSTANCE & hInst ) {
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Offset " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 20 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Angle of Joint " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 40 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Segment Length " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 60 , 150 , 20 , hwnd_child , NULL , hInst , NULL ) , " Twist Angle " );
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 80 , 310 , 30 , hwnd_child , ( HMENU ) ID_BUTTON_ADD , hInst , NULL );
	int x_offset, y_offset;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i++ ) {
		i % 2 ? x_offset = 235 : x_offset = 150;
		input[ i ] = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER | ES_NUMBER, x_offset , y_offset , 75 , 20 , hwnd_child , NULL , hInst , NULL );
		if ( x_offset == 235 ) y_offset += 20;
	}
	for ( unsigned int i = 0 ; i < INPUT_BOXES / 2 ; i++ ) {
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | ES_CENTER , 225 , i * 20 , 10 , 20 , hwnd_child , NULL , hInst , NULL ) , "." );
	}
}
