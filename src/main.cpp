//============================================================================
// Name        : Main.cpp
// Author      : Mateusz Fraszczynski
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Denavit-Hartenberg notation implementation in C++, Ansi-style
//============================================================================

#include "../include/HelperFunctions.h"
// Include UI
#include "../include/UI/MainWindow.h"
#include "../include/UI/AddJointWindow.h"
#include "../include/UI/ShowPositionWindow.h"
#include "../include/UI/ChangeValueOfJointParamWindow.h"
#include "../include/UI/CommonID.h"
// Include Classes
#include "../include/Matrix.h"
#include "../include/MatrixTest.h"
#include "../include/DHparam.h"
#include "../include/Timer.h"
// Include libs
#include <iostream>
#include <windows.h>

using namespace std;

HINSTANCE hInst;
HWND hwnd_AJ;
HWND hwnd_SP;
HWND hwnd_JP;

DHparam * dhp = NULL;

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
LRESULT CALLBACK WindowProcChild_AddJoint( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
LRESULT CALLBACK WindowProcChild_ShowPosition( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
LRESULT CALLBACK WindowProcChild_ChangeJointParam( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );

// SAVE for future
// HDC hdc = GetWindowDC( hwnd );
// ReleaseDC( hwnd , hdc );

int WinMain( HINSTANCE hInst_l , HINSTANCE , LPSTR , int nCmdShow ) {

	#ifdef DEBUG
	    printf("RUNNING DEBUG BUILD\n");
	    MatrixTest start;
	#else
	    printf("Running... this is a release build.");
	#endif

	HWND hwnd_main;

	if ( ! initWindows( hwnd_main , hInst ) ) return 0;
	createMainWindow( hwnd_main , hInst );

	dhp = new DHparam();

	ShowWindow( hwnd_main , nCmdShow );
	UpdateWindow( hwnd_main );

	MSG msg;
	while ( GetMessage( & msg , NULL , 0 , 0 ) > 0 ) {
		TranslateMessage( & msg );
		DispatchMessage( & msg );
	}
	delete dhp;
	return msg.wParam;
}

LRESULT CALLBACK WindowProc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd , & r );
			dc = BeginPaint( hwnd , & ps );
			DrawText( dc , "Welcome in DH" , -1 , & r , DT_SINGLELINE | DT_CENTER | DT_VCENTER );
			int y_offset = MAIN_DRAW_TAB_Y;
			for ( unsigned int i = 0 ; i < dhp->getNoOfJoints() + 1 ; i++ , y_offset += MAIN_COLUMN_HIGH ) {
				drawRowInMainWindowTable( dc , MAIN_DRAW_TAB_X , y_offset  );
			}
			fillRowsInMainWindowTable( dc , dhp );
			updateButtons( hwnd , hInst , dhp );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_CREATE: {
			fillMainWindow( hwnd , hInst );
			break;
		}
		case WM_DESTROY:
			PostQuitMessage( 0 );
			break;
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD_JOINT: {
					//TODO hwnd_AJ and hInst should be local in main
					if ( ! createAddJointWindow( hwnd , hwnd_AJ , hInst ) ) break;
					ShowWindow( hwnd_AJ , SW_SHOW );
				    UpdateWindow( hwnd_AJ );
				    //EnumChildWindows
				}
				break;
				case ID_BUTTON_SHOW_POS: {
					if ( ! createShowPositionWindow( hwnd , hwnd_SP , hInst ) ) break;
					ShowWindow( hwnd_SP , SW_SHOW );
				    UpdateWindow( hwnd_SP );
				}
				break;
				case ID_BUTTON_REMOVE_JOINT: {
				    if ( IDYES == MessageBox( hwnd , "Are you sure you want to remove last joint ?" , "Remove Joint" , MB_ICONEXCLAMATION | MB_YESNO ) ) {
				    	if ( removeLastJoint( dhp ) ) {
				    		RedrawWindow( hwnd , NULL , NULL , RDW_ERASE | RDW_INVALIDATE | RDW_UPDATENOW );
				    		MessageBox(  NULL , " Successful remove of last joint ! " , "Success !" , MB_ICONINFORMATION );
				    	} else {
				    		MessageBox( NULL , " Failed to remove joint ! ", "Failed !" , MB_ICONINFORMATION );
				    	}
				    }
				}
				break;
				case ID_BUTTON_CHANGE_VALUE_BEGIN ... ID_BUTTON_CHANGE_VALUE_END: {
					if ( ! createChangeValueOfJointParamWindow( hwnd , hwnd_JP , hInst , wparam ) ) break;
					ShowWindow( hwnd_JP , SW_SHOW );
				    UpdateWindow( hwnd_JP );
				}
				break;
			}
			break;
		}
		case WM_PARENTNOTIFY:
			break;
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
}

LRESULT CALLBACK WindowProcChild_AddJoint( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			break;
		}
		case WM_CREATE: {
			fillAddJointWindow( hwnd , hInst );
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_ADD: {
					if ( verifyAndAddValues( dhp ) ) {
						RedrawWindow( GetParent( hwnd ) , NULL , NULL , RDW_INVALIDATE | RDW_UPDATENOW );
						DestroyWindow( hwnd );
						MessageBox(  NULL , " Successful added joint ! " , "Success !" , MB_ICONINFORMATION );
					} else {
						DestroyWindow( hwnd );
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
			DestroyWindow( hwnd );
			break;
		}
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
}

LRESULT CALLBACK WindowProcChild_ShowPosition( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd , & r );
			dc = BeginPaint( hwnd , & ps );
			int y_offset = WIN_SP_DRAW_TAB_Y;
			for ( unsigned int i = 0 ; i < WIN_SP_TABLE_COLUMNS ; i++ , y_offset += WIN_SP_COLUMN_HIGH ) {
				drawRowInShowPositionWindowTable( dc , WIN_SP_DRAW_TAB_X , y_offset );
			}
			fillRowsInShowPositionWindowTable( dc , dhp );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_CREATE: {
			fillShowPositionWindow( hwnd , hInst , dhp );
			break;
		}
		case WM_COMMAND: {
			break;
		}
		case WM_DESTROY: {
			DestroyWindow( hwnd );
			break;
		}
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
	}
	return 0;
}

LRESULT CALLBACK WindowProcChild_ChangeJointParam( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam ) {
	static int joint_index = -1;
	switch ( msg ) {
		case WM_PAINT: {
			PAINTSTRUCT ps;
			HDC dc;
			RECT r;
			GetClientRect( hwnd , & r );
			dc = BeginPaint( hwnd , & ps );
			EndPaint( hwnd , & ps );
			break;
		}
		case WM_CREATE: {
			if ( lparam == WIN_JP_LPCREATE ) {			// Because we need wparam with joint index
				joint_index = wparam - ID_BUTTON_CHANGE_VALUE_BEGIN;
				fillChangeValueOfJointParamWindow( hwnd , hInst , dhp , joint_index );
			}
			break;
		}
		case WM_COMMAND: {
			switch( wparam ) {
				case ID_BUTTON_CHANGE: {
					if ( verifyAndChangeValue( dhp , joint_index ) ) {
						RedrawWindow( GetParent( hwnd ) , NULL , NULL , RDW_INVALIDATE | RDW_UPDATENOW );
						DestroyWindow( hwnd );
						MessageBox(  NULL , " Successful change joint value ! " , "Success !" , MB_ICONINFORMATION );
					} else {
						DestroyWindow( hwnd );
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
			DestroyWindow( hwnd );
			break;
		}
		default:
			return DefWindowProc( hwnd , msg , wparam , lparam );
		}
	return 0;
}
