
// HotelSearchDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CHotelSearchDlg �Ի���
class CHotelSearchDlg : public CDialogEx
{
// ����
public:
	CHotelSearchDlg(CWnd* pParent = NULL);	// ��׼���캯��
	//~CHotelSearchDlg();

// �Ի�������
	enum { IDD = IDD_HOTELSEARCH_DIALOG };

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
//	CEdit m_strFind;
	CString m_strFind;

	const char *path = "F:\\����\\Դ�������\\kaifang.txt";		//��ѯ��·��
	const char *respath = "F:\\����\\Դ�������\\kaifangres.txt";	//��ѯ�����·��

	char **pp = NULL;
	int n = 10001574;
	afx_msg void OnBnClickedButtonSearch();

public:
	int GetFileColumn();
	void InitMem();		//

	CString m_label;
	CListBox m_list;
};
