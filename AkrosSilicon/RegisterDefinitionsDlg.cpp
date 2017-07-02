// RegisterDefinitionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AkrosSilicon.h"
#include "RegisterDefinitionsDlg.h"
#include "afxdialogex.h"

#include "AkrosSiliconView.h"

// CRegisterDefinitionsDlg dialog

IMPLEMENT_DYNAMIC(CRegisterDefinitionsDlg, CDialogEx)

CRegisterDefinitionsDlg::CRegisterDefinitionsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REGISTER_DEFINITION, pParent)
{
	mp_Parent = pParent;
}

CRegisterDefinitionsDlg::~CRegisterDefinitionsDlg()
{
}

void CRegisterDefinitionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRegisterDefinitionsDlg, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_IDOK, &CRegisterDefinitionsDlg::OnBnClickedIdok)
END_MESSAGE_MAP()


// CRegisterDefinitionsDlg message handlers
void CRegisterDefinitionsDlg::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	if (mp_Parent)
	{
		((CAkrosSiliconView*)mp_Parent)->mp_dlgRegisterDefinition = NULL;
	}
	delete this;
}

void CRegisterDefinitionsDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	if (mp_Parent)
	{
		((CAkrosSiliconView*)mp_Parent)->mp_dlgRegisterDefinition = NULL;
	}
}


void CRegisterDefinitionsDlg::OnBnClickedIdok()
{
	// TODO: Add your control notification handler code here
	DestroyWindow();
}
