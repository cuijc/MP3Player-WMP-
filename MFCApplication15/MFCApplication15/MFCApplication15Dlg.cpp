
// MFCApplication15Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication15.h"
#include "MFCApplication15Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CMFCApplication15Dlg::OnNMDblclkList)
//	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CMFCApplication15Dlg::OnNMClickList)
END_MESSAGE_MAP()



// CMFCApplication15Dlg 对话框



CMFCApplication15Dlg::CMFCApplication15Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication15Dlg::IDD, pParent)
	, m_filename(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication15Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_OCX1, m_player);
}

BEGIN_MESSAGE_MAP(CMFCApplication15Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication15Dlg::OnBnClickedButton1)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication15Dlg::OnLbnSelchangeList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CMFCApplication15Dlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication15Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication15Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication15Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication15Dlg::OnBnClickedButton5)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CMFCApplication15Dlg::OnDblclkList2)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CMFCApplication15Dlg::OnClickList2)
END_MESSAGE_MAP()


// CMFCApplication15Dlg 消息处理程序

BOOL CMFCApplication15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication15Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication15Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication15Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码



	
CFileDialog opendlg (TRUE,_T("*"),_T("*.mp3"),OFN_OVERWRITEPROMPT, _T("所有文件(*.*;)|*.*||"),NULL); 

if (opendlg.DoModal()==IDOK)
	{
	filename=opendlg.GetFileName();
	pathname=opendlg.GetPathName();
	} 
	m_list.InsertItem(0,filename);
	
	


}


void CMFCApplication15Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CMFCApplication15Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
	

		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication15Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	
	m_player.put_URL(pathname);
}


void CMFCApplication15Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteItem(m_list.GetNextItem(-1,LVNI_SELECTED)); 
}


void CMFCApplication15Dlg::OnBnClickedButton4()
{
	dia1 dia;
	dia.DoModal();
	
	CString a;
	a=dia.change;//获取子窗口传回的值
	
//	LPNMITEMACTIVATE temp ;//将传进来的消息转换成LPNMITEMACTIVAT
	//NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR

//	nItem = temp->iItem;//获得行号
//	nSubItem = temp->iSubItem;//获得列号
	
	m_list.SetItemText(m_Row,m_Col,a);

	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication15Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCApplication15Dlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)//全局（没用）
	{
		LPNMITEMACTIVATE pNMDItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	*pResult=0;
}


void CMFCApplication15Dlg::OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)//（控件响应）
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
		
 
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;     // 
	CRect rc;    
	m_Row = pNMListView->iItem;//获得选中的行  
	m_Col = pNMListView->iSubItem;//获得选中列 
	m_player.put_URL(pathname);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}



void CMFCApplication15Dlg::OnClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_Row = pNMListView->iItem;//获得选中的行  
	m_Col = pNMListView->iSubItem;//获得选中列 
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
