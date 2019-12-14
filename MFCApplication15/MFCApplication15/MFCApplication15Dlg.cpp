
// MFCApplication15Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication15.h"
#include "MFCApplication15Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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



// CMFCApplication15Dlg �Ի���



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


// CMFCApplication15Dlg ��Ϣ�������

BOOL CMFCApplication15Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication15Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication15Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication15Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



	
CFileDialog opendlg (TRUE,_T("*"),_T("*.mp3"),OFN_OVERWRITEPROMPT, _T("�����ļ�(*.*;)|*.*||"),NULL); 

if (opendlg.DoModal()==IDOK)
	{
	filename=opendlg.GetFileName();
	pathname=opendlg.GetPathName();
	} 
	m_list.InsertItem(0,filename);
	
	


}


void CMFCApplication15Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CMFCApplication15Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
	

		*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMFCApplication15Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	m_player.put_URL(pathname);
}


void CMFCApplication15Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_list.DeleteItem(m_list.GetNextItem(-1,LVNI_SELECTED)); 
}


void CMFCApplication15Dlg::OnBnClickedButton4()
{
	dia1 dia;
	dia.DoModal();
	
	CString a;
	a=dia.change;//��ȡ�Ӵ��ڴ��ص�ֵ
	
//	LPNMITEMACTIVATE temp ;//������������Ϣת����LPNMITEMACTIVAT
	//NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR

//	nItem = temp->iItem;//����к�
//	nSubItem = temp->iSubItem;//����к�
	
	m_list.SetItemText(m_Row,m_Col,a);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication15Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMFCApplication15Dlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)//ȫ�֣�û�ã�
	{
		LPNMITEMACTIVATE pNMDItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	*pResult=0;
}


void CMFCApplication15Dlg::OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)//���ؼ���Ӧ��
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
		
 
	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;     // 
	CRect rc;    
	m_Row = pNMListView->iItem;//���ѡ�е���  
	m_Col = pNMListView->iSubItem;//���ѡ���� 
	m_player.put_URL(pathname);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}



void CMFCApplication15Dlg::OnClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_Row = pNMListView->iItem;//���ѡ�е���  
	m_Col = pNMListView->iSubItem;//���ѡ���� 
		*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
