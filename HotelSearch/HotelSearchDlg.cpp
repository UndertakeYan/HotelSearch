
// HotelSearchDlg.cpp : ʵ���ļ�
//
#define _CRT_SERCURE_NO_WARNINGS
#include "stdafx.h"
#include "HotelSearch.h"
#include "HotelSearchDlg.h"
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
END_MESSAGE_MAP()


// CHotelSearchDlg �Ի���



CHotelSearchDlg::CHotelSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHotelSearchDlg::IDD, pParent)
	, m_strFind(_T(""))
	, m_label(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHotelSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_FIND, m_strFind);
	DDX_Text(pDX, IDC_EDIT_FIND, m_strFind);
	DDX_Text(pDX, IDC_STATIC_LABEL, m_label);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(CHotelSearchDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CHotelSearchDlg::OnBnClickedButtonSearch)
END_MESSAGE_MAP()


// CHotelSearchDlg ��Ϣ�������

BOOL CHotelSearchDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	InitMem();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHotelSearchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHotelSearchDlg::OnPaint()
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
HCURSOR CHotelSearchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CHotelSearchDlg::GetFileColumn()
{
	int i = 0;
	FILE *pfr;
	pfr = fopen(path, "r");//��ȡ�ļ�
	if (pfr == NULL)
	{
		printf("�ļ�����ʧ��");
		return -1;
	}
	else
	{
		while (!feof(pfr))
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);//��ȡһ��
			i++;

		}
		fclose(pfr);
		return i;
	}
}

void CHotelSearchDlg::InitMem()
{
	//m_label = _T("���ڼ����ڴ�");
	//int n = GetFileColumn();
	pp = (char **)malloc(n*(sizeof(char *)));//����ָ��ָ��һ����ָ̬������
	memset(pp, 0, n*sizeof(char *));//�ڴ�����

	FILE *pfr;
	pfr = fopen(path, "r");//��ȡ�ļ�
	if (pfr == NULL)
	{
		AfxMessageBox(_T("�ļ�����ʧ��"));
		return ;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);//��ȡһ��
			int length = strlen(str);//��ȡ����
			pp[i] = (char *)malloc(length + 1);//�����ڴ�
			if (pp[i] != NULL)
			{
				strcpy(pp[i], str);//��������
			}
		}
		fclose(pfr);
	}
	//AfxMessageBox(_T("�ڴ�������"));
	m_label = _T("�ڴ�������");
	UpdateData(FALSE);
}

void CHotelSearchDlg::OnBnClickedButtonSearch()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//InitMem();
	//int n = GetFileColumn();
	UpdateData(TRUE);
	FILE *fpw = fopen(respath, "w");
	if (fpw == NULL)
	{
		AfxMessageBox(_T("�ļ�����ʧ��"));
		return;
	}
	char findstr[20] = { 0 };

	//m_strFind = GetDlgItemText(IDC_EDIT_FIND);
	strcpy(findstr, (LPSTR)(LPCTSTR)m_strFind);

	for (int i = 0; i < n - 1; i++)
	{

		char *p = strstr(pp[i], findstr);
		if (p != NULL)
		{
			m_list.AddString((LPCTSTR)p);
			//AfxMessageBox((LPCTSTR)p);
			fputs(p, fpw);
		}
	}
	fclose(fpw);
}

