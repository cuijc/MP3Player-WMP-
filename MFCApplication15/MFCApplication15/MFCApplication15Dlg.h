
// MFCApplication15Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "cwmpplayer4.h"
#include"dia1.h"


// CMFCApplication15Dlg �Ի���
class CMFCApplication15Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication15Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION15_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CListCtrl m_list;
	char m_filename;
	CString filename;
	CString pathname;
	afx_msg void OnBnClickedButton3();
	CWMPPlayer4 m_player;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	int m_Row;
	int m_Col;
	afx_msg void OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList2(NMHDR *pNMHDR, LRESULT *pResult);
};
