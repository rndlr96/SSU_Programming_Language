
// TicTacToe.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTicTacToeApp:
// �� Ŭ������ ������ ���ؼ��� TicTacToe.cpp�� �����Ͻʽÿ�.
//

class CTicTacToeApp : public CWinApp
{
public:
	CTicTacToeApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTicTacToeApp theApp;