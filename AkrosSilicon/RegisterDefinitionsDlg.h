#pragma once


// CRegisterDefinitionsDlg dialog

class CRegisterDefinitionsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRegisterDefinitionsDlg)

public:
	CRegisterDefinitionsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRegisterDefinitionsDlg();
	void PostNcDestroy();

	CWnd* mp_Parent;

// Dialog Data
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REGISTER_DEFINITION };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedIdok();
};
