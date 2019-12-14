#pragma once
#include "afxwin.h"


// dia1 对话框

class dia1 : public CDialogEx
{
	DECLARE_DYNAMIC(dia1)

public:
	dia1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~dia1();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString change;
	CEdit m_edit;
};
