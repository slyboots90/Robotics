/*
 * AddJoint.cpp
 *
 *  Created on: 22 sep. 2017
 *      Author: mateusz.fraszczynski
 */

// Include UI
#include "../../include/UI/AddJoint.h"
#include "../../include/UI/CommonID.h"
// Include Classes
// Include libs

AddJoint::AddJoint( HWND & hwnd , HINSTANCE & hInst , DHparam * dhp ) : hwnd_child( 0 ) , hInstRef( hInst ) , dhpPtr( dhp ) {
	this->initWindow( );
	this->createWindow( hwnd );
}

AddJoint::~AddJoint() {

}

LRESULT AddJoint::WndProc( UINT msg , WPARAM wparam , LPARAM lparam ) {
	printf ("deb msg \n");
	switch ( msg ) {
		case WM_PAINT: {
			break;
		}
		case WM_CREATE: {
			fillWindow();
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD: {
					if ( this->verifyAndAddValues( ) ) {
						RedrawWindow( GetParent( hwnd_child ) , NULL , NULL , RDW_INVALIDATE | RDW_UPDATENOW );
						DestroyWindow( hwnd_child );
						MessageBox(  NULL , " Successful added joint ! " , "Success !" , MB_ICONINFORMATION );
					} else {
						DestroyWindow( hwnd_child );
						MessageBox( NULL , " Failed to add joint ! ", "Failed !" , MB_ICONINFORMATION );
					}
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
			return DefWindowProc( hwnd_child , msg , wparam , lparam );
	}
	return 0;
}

void AddJoint::initWindow( ) {
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

void AddJoint::createWindow( HWND & hwnd_parent ) {
	hwnd_child = CreateWindowEx( WS_EX_APPWINDOW , subWindowName.c_str() , subWindowName.c_str() ,  WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP , CW_USEDEFAULT , CW_USEDEFAULT , WIN_AJ_SIZE_X , WIN_AJ_SIZE_Y , hwnd_parent , NULL , hInstRef , NULL );
	if ( ! hwnd_child ) return;
	WindowHandler::s_NotifyWindows.insert( pair < HWND , WindowHandler * > ( hwnd_child , this ) );
	SendMessage( hwnd_child , WM_CREATE , 0 , 0 );
	printf ("AddJoint - %d \n" , hwnd_child );
	ShowWindow( hwnd_child , SW_SHOW );
    UpdateWindow( hwnd_child );
}

void AddJoint::fillWindow( ) {
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 0 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Segment Length " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 20 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Twist Angle " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 40 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Segment Offset " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 60 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Angle of Joint " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 80 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Joint Type " );
	SetWindowText( CreateWindowEx( WS_EX_CLIENTEDGE , "STATIC" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , 0 , 100 , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) , " Angle Units " );
	listbox.push_back( CreateWindowEx( WS_EX_CLIENTEDGE , "COMBOBOX" , NULL , WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST , 150 , 80 , 150 , 100 , hwnd_child , NULL , hInstRef , NULL ) );
	SendMessage( listbox.back() , CB_ADDSTRING , 0 , ( LPARAM ) "Rotational" );
	SendMessage( listbox.back() , CB_ADDSTRING , 0 , ( LPARAM ) "Linear" );
	SendMessage( listbox.back() , CB_SETCURSEL , ( WPARAM ) 0 , 0 );			// Set default value to Rotational
	listbox.push_back( CreateWindowEx( WS_EX_CLIENTEDGE , "COMBOBOX" , NULL , WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST , 150 , 100 , 150 , 100 , hwnd_child , NULL , hInstRef , NULL ) );
	SendMessage( listbox.back() , CB_ADDSTRING , 0 , ( LPARAM ) "Degrees" );
	SendMessage( listbox.back() , CB_ADDSTRING , 0 , ( LPARAM ) "Radians" );
	SendMessage( listbox.back() , CB_SETCURSEL , ( WPARAM ) 0 , 0 );			// Set default value to Degrees
	CreateWindowEx( WS_EX_CLIENTEDGE , "BUTTON" , "Add" , WS_CHILD | WS_VISIBLE | WS_BORDER , 0 , 120 , 300 , 40 , hwnd_child , ( HMENU ) ID_BUTTON_ADD , hInstRef , NULL );
	int x_offset = 150 , y_offset = 0;
	for ( unsigned int i = 0 ; i < EDIT_BOXES ; i++ ) {
		inputbox.push_back( CreateWindowEx( WS_EX_CLIENTEDGE , "EDIT" , NULL , WS_CHILD | WS_VISIBLE | SS_LEFT | ES_CENTER , x_offset , y_offset , 150 , 20 , hwnd_child , NULL , hInstRef , NULL ) );
		y_offset += 20;
	}
}

bool AddJoint::verifyAndAddValues(  ) {
	if ( dhpPtr == NULL ) return false;
	jointParams jParams;
	vector < HWND > ::iterator listboxIt = listbox.begin();
	INT selected_type = SendMessage( * listboxIt , CB_GETCURSEL , 0 , 0 );
	if ( selected_type == 0 ) {
		jParams.type = Rotational;
	} else if ( selected_type == 1 ) {
		jParams.type = Linear;
	}
	listboxIt++;
	INT selected_units = SendMessage( * listboxIt , CB_GETCURSEL , 0 , 0 );
	if ( selected_units == 0 ) {
		jParams.unit = Degrees;
	} else if ( selected_units == 1 ) {
		jParams.unit = Radians;
	}
	vector < HWND > ::iterator inputboxIt = inputbox.begin();
	for ( unsigned int i = 0 ; i < inputbox.size() ; i++ , inputboxIt++ ) {
		double value = this->getValuesFromWindow( * inputboxIt );
		if ( value == ERROR_DOUBLE_VALUE ) return false;
		switch ( i ) {
				case 0:
					//TODO add range here and in UI ( help info )
					if ( ! ( value < MAX_A_INPUT_VALUE && value > MIN_A_INPUT_VALUE ) ) return false;
					jParams.a = value;
					break;
				case 1: {
					if ( jParams.unit == Degrees ) {
						if ( ! ( value < 360 && value > -360 ) ) return false;
					} else if ( jParams.unit == Radians ) {
						if ( ! ( value < 2 * PI && value > -2 * PI ) ) return false;
					} else {
						printf ( "ERROR: Joint Params unit not found ! ");
						return false;
					}
					jParams.alpha = value;
					break;
				}
				case 2:
					if ( ! ( value < MAX_D_INPUT_VALUE && value > MIN_D_INPUT_VALUE ) ) return false;
					jParams.d = value;
					break;
				case 3: {
					if ( jParams.unit == Degrees ) {
						if ( ! ( value < 360 && value > -360 ) ) return false;
					} else if ( jParams.unit == Radians ) {
						if ( ! ( value < 2 * PI && value > -2 * PI ) ) return false;
					} else {
						printf ( "ERROR: Joint Params unit not found ! ");
						return false;
					}
					jParams.theta = value;
					break;
				}
				default:
					break;
		}
	}
	dhpPtr->addJointParams( jParams );
	return true;
}
