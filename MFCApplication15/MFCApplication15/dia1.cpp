// dia1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication15.h"
#include "dia1.h"
#include "afxdialogex.h"


// dia1 �Ի���

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


// dia1 ��Ϣ�������


void dia1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015


	m_edit.GetWindowText(change); 
	




	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
