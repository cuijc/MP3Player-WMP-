
// MFCApplication15.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication15App:
// �йش����ʵ�֣������ MFCApplication15.cpp
//

class CMFCApplication15App : public CWinApp
{
public:
	CMFCApplication15App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication15App theApp;