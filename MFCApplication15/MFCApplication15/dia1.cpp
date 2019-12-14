// dia1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication15.h"
#include "dia1.h"
#include "afxdialogex.h"


// dia1 对话框

IMPLEMENT_DYNAMIC(dia1, CDialogEx)

dia1::dia1(CWnd* pParent /*=NULL*/)
	: CDialogEx(dia1::IDD, pParent)
{

}

dia1::~dia1()
{
}

void dia1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(dia1, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &dia1::OnEnChangeEdit1)
END_MESSAGE_MAP()


// dia1 消息处理程序


void dia1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015


	m_edit.GetWindowText(change); 
	




	// TODO:  在此添加控件通知处理程序代码
}
