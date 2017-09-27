/*
 * ShowPosition.cpp
 *
 *  Created on: 26 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/ShowPosition.h"
// Include Classes
// Include libs

ShowPosition::ShowPosition( HWND & hwnd , HINSTANCE & hInst , DHparam * dhp ) : hwnd_child( 0 ) , hInstRef( hInst ) , dhpPtr( dhp ) {
	this->initWindow( );
	this->createWindow( hwnd );
}

ShowPosition::~ShowPosition() {

}

LRESULT ShowPosition::WndProc( UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd_child , & r );
			dc = BeginPaint( hwnd_child , & ps );
			int y_offset = WIN_SP_DRAW_TAB_Y;
			for ( unsigned int i = 0 ; i < WIN_SP_TABLE_COLUMNS ; i++ , y_offset += WIN_SP_COLUMN_HIGH ) {
				drawRowInTable( dc , WIN_SP_DRAW_TAB_X , y_offset );
			}
			this->fillRowsInTable( dc );
			EndPaint( hwnd_child , & ps );
			break;
		}
		case WM_CREATE: {
			fillWindow();
			break;
		}
		case WM_COMMAND: {
			break;
		}
		case WM_DESTROY: {
			DestroyWindow( hwnd_child );
			break;
		}
		default:
			return DefWindowProc( hwnd_child , msg , wparam , lparam );
	}
	return 0;
}

void ShowPosition::initWindow( ) {
	WNDCLASS wc;
	if ( GetClassInfo( hInstRef , subWindowName.c_str() , &wc ) ) return;
	WNDCLASSEX wcx;
	wcx.cbSize = sizeof( wcx );
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WindowProcHandler;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInstRef;
	wcx.hIcon = LoadIcon( NULL , IDI_APPLICATION );
	wcx.hCursor = LoadCursor( NULL , IDC_ARROW );
	wcx.hbrBackground = ( HBRUSH ) COLOR_WINDOWFRAME;
	wcx.lpszMenuName =  NULL;
	wcx.lpszClassName = subWindowName.c_str();
	wcx.hIconSm = ( HICON ) LoadImage( hInstRef , MAKEINTRESOURCE( 5 ) , IMAGE_ICON , GetSystemMetrics( SM_CXSMICON ) , GetSystemMetrics( SM_CYSMICON ) , LR_DEFAULTCOLOR );
	if ( ! RegisterClassEx( & wcx ) ) return;
}

void ShowPosition::createWindow( HWND & hwnd_parent ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , subWindowName.c_str() , subWindowName.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_SP_SIZE_X , WIN_SP_SIZE_Y , hwnd_parent , NULL , hInstRef , NULL );
	if ( ! hwnd_child ) return;
	WindowHandler::s_NotifyWindows.insert( pair < HWND , WindowHandler * > ( hwnd_child , this ) );
	SendMessage( hwnd_child , WM_CREATE , 0 , 0 );
	printf ("ShowPosition - %d \n" , hwnd_child );
	ShowWindow( hwnd_child , SW_SHOW );
    UpdateWindow( hwnd_child );
}

void ShowPosition::fillWindow( ) {
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Position X " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 20 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Position Y " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 40 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Position Z " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 150 , 0 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , doubleToString( getXpos( ) ).c_str() );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 150 , 20 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , doubleToString( getYpos( ) ).c_str() );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 150 , 40 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , doubleToString( getZpos( ) ).c_str() );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 80 , 300 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Rotation Matrix " );
}

double ShowPosition::getXpos( ) {
	if( dhpPtr != NULL ) return dhpPtr->getPositionX();
	return 0;
}

double ShowPosition::getYpos( ) {
	if( dhpPtr != NULL ) return dhpPtr->getPositionY();
	return 0;
}

double ShowPosition::getZpos( ) {
	if( dhpPtr != NULL ) return dhpPtr->getPositionZ();
	return 0;
}

void ShowPosition::drawRowInTable( HDC & dc , int x_start , int y_start ) {
	int x_current = x_start;
	int y_current = y_start;
	for ( unsigned int i = 0 ; i < ROTMATRIXSIZE ; i++ ) {
		MoveToEx( dc , x_current , y_current , NULL );
		x_current += WIN_SP_COLUMN_WIDTH;
		LineTo( dc , x_current , y_current );
		y_current += WIN_SP_COLUMN_HIGH;
		LineTo( dc , x_current , y_current );
		x_current -= WIN_SP_COLUMN_WIDTH;
		LineTo( dc , x_current , y_current );
		y_current -= WIN_SP_COLUMN_HIGH;
		LineTo( dc , x_current , y_current );
		x_current += WIN_SP_COLUMN_WIDTH;
	}
}

void ShowPosition::fillRowsInTable( HDC & dc ) {
	shared_ptr < Matrix > rot_M = dhpPtr->getRotationalMatrix();
	for ( unsigned int i = 0 ; i < ROTMATRIXSIZE ; i++ ) {
		const vector < double > * row_ptr = rot_M->getRow( i );
		for ( unsigned int j = 0 ; j < WIN_SP_TABLE_COLUMNS ; j++ ) {
			ostringstream ss_value;
			ss_value << row_ptr->at( j );
			string str_value = ss_value.str();
			TextOut( dc , WIN_SP_TEXT_OFFSET_X + ( j * WIN_SP_COLUMN_WIDTH ) , WIN_SP_TEXT_OFFSET_Y + ( i * WIN_SP_COLUMN_HIGH ) , TEXT( str_value.c_str() ) , str_value.size() );
		}
	}
}
