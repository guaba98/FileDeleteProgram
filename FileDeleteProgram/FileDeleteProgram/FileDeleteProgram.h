
// FileDeleteProgram.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFileDeleteProgramApp:
// �� Ŭ������ ������ ���ؼ��� FileDeleteProgram.cpp�� �����Ͻʽÿ�.
//

class CFileDeleteProgramApp : public CWinApp
{
public:
	CFileDeleteProgramApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFileDeleteProgramApp theApp;