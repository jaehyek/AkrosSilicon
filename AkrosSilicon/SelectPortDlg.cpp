// SelectPortDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AkrosSilicon.h"
#include "SelectPortDlg.h"
#include "afxdialogex.h"

#include "EnumSerial.h"

// CSelectPortDlg dialog

IMPLEMENT_DYNAMIC(CSelectPortDlg, CDialogEx)

CSelectPortDlg::CSelectPortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SELECT_PORT, pParent)
{

}

CSelectPortDlg::~CSelectPortDlg()
{
}

void CSelectPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_PORT, m_listPort);
}


BEGIN_MESSAGE_MAP(CSelectPortDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectPortDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectPortDlg message handlers


BOOL CSelectPortDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	int index;

	index = m_listPort.AddString(_T("[No Devices connected]"));
	m_listPort.SetItemData(index, -1);

	CEnumerateSerial::CPortsArray ports;
	CEnumerateSerial::CNamesArray names;

	if (CEnumerateSerial::UsingSetupAPI2(ports, names))
	{
		CString strtemp;
		UINT i;
#ifdef CENUMERATESERIAL_USE_STL
		for (i = 0; i < ports.size(); i++)
		{
			strtemp.Format(_T("%s (COM%u)"), names[i].c_str(), ports[i]);
			int nItem = m_listPort.AddString(strtemp);
			m_listPort.SetItemData(nItem, ports[i]);

		}
#else
		for (i = 0; i<ports.GetSize(); i++)
			_tprintf(_T("COM%u <%s>\n"), ports[i], names[i].operator LPCTSTR());
#endif
	}

	m_listPort.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CSelectPortDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	m_nPort = m_listPort.GetItemData(m_listPort.GetCurSel());

	CDialogEx::OnOK();
}
