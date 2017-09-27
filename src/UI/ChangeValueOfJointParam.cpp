/*
 * ChangeValueOfJointParam.cpp
 *
 *  Created on: 27 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/ChangeValueOfJointParam.h"
#include "../../include/UI/CommonID.h"
// Include Classes
// Include libs


ChangeValueOfJointParam::ChangeValueOfJointParam( HWND & hwnd , HINSTANCE & hInst , DHparam * dhp , WPARAM wparam ) : hwnd_child( 0 ) , hInstRef( hInst ) , dhpPtr( dhp ) , changeBox( 0 ) {
	this->initWindow( );
	jointIndex = wparam - ID_BUTTON_CHANGE_VALUE_BEGIN;
	this->createWindow( hwnd );
}

ChangeValueOfJointParam::~ChangeValueOfJointParam() {

}

LRESULT ChangeValueOfJointParam::WndProc( UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			break;
		}
		case WM_CREATE: {
			fillWindow( );
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_CHANGE: {
					if ( verifyAndChangeValue( ) ) {
						RedrawWindow( GetParent( hwnd_child ) , NULL , NULL , RDW_INVALIDATE | RDW_UPDATENOW );
						DestroyWindow( hwnd_child );
						MessageBox(  NULL , " Successful change joint value ! " , "Success !" , MB_ICONINFORMATION );
					} else {
						DestroyWindow( hwnd_child );
						MessageBox( NULL , " Failed to change joint value ! ", "Failed !" , MB_ICONINFORMATION );
					}
				}
					break;
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
			return DefWindowProc( hwnd_child , msg , wparam , lparam );
		}
	return 0;
}

void ChangeValueOfJointParam::initWindow( ) {
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

void ChangeValueOfJointParam::createWindow( HWND & hwnd_parent ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , subWindowName.c_str() , subWindowName.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_JP_SIZE_X , WIN_JP_SIZE_Y , hwnd_parent , NULL , hInstRef , NULL );
	if ( ! hwnd_child ) return;
	WindowHandler::s_NotifyWindows.insert( pair < HWND , WindowHandler * > ( hwnd_child , this ) );
	printf ("ChangeValueOfJointParam - %d \n" , hwnd_child );
	SendMessage( hwnd_child , WM_CREATE , 0 , 0 );
	ShowWindow( hwnd_child , SW_SHOW );
    UpdateWindow( hwnd_child );
}

void ChangeValueOfJointParam::fillWindow( ) {
	if ( dhpPtr == NULL ) return;
		string joint_type , str_old_value;
		double old_value = 0;
		const jointParams * params = dhpPtr->getJointParams( jointIndex );
		if ( params->type == Linear ) {
			joint_type = "Linear Joint - d value";
			old_value = params->d;
		} else if ( params->type == Rotational ) {
			joint_type = "Rotational Joint - theta value";
			old_value = params->theta;
		}
		str_old_value = doubleToString( old_value );
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 20 , 20 , 300 , 20 , hwnd_child , NULL , hInstRef , NULL ) , joint_type.c_str() );
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 20 , 40 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Old Value " );
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 170 , 40 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , str_old_value.c_str() );
		SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 20 , 60 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " New Value " );
		changeBox = CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 170 , 60 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL );
		CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Change" , WS_CHILD | WS_VISIBLE | WS_BORDER , 20 , 80 , 300 , 30 , hwnd_child , ( HMENU ) ID_BUTTON_CHANGE , hInstRef , NULL );
}

bool ChangeValueOfJointParam::verifyAndChangeValue( ) {
	if( dhpPtr == NULL ) return false;
	const jointParams * params = dhpPtr->getJointParams( jointIndex );
	double value = getValuesFromWindow( changeBox );
	if ( value == ERROR_DOUBLE_VALUE ) return false;
	if ( params->type == Linear ) {
		if ( ! ( value < MAX_D_INPUT_VALUE && value > MIN_D_INPUT_VALUE ) ) return false;
	} else if ( params->type == Rotational ) {
		if ( params->unit == Degrees ) {
			if ( ! ( value < 360 && value > -360 ) ) return false;
		} else if ( params->unit == Radians ) {
			if ( ! ( value < 2 * PI && value > -2 * PI ) ) return false;
		} else {
			printf ( "ERROR: Joint Params unit not found ! ");
			return false;
		}
	} else {
		return false;
	}
	return dhpPtr->updateJointValue( jointIndex , value );
}
