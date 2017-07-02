#pragma once
#include "afxwin.h"


// CSelectPortDlg dialog

class CSelectPortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectPortDlg)

public:
	CSelectPortDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectPortDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_PORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listPort;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	int m_nPort;
};
