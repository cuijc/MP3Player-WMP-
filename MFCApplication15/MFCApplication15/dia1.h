#pragma once
#include "afxwin.h"


// dia1 �Ի���

class dia1 : public CDialogEx
{
	DECLARE_DYNAMIC(dia1)

public:
	dia1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~dia1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString change;
	CEdit m_edit;
};
