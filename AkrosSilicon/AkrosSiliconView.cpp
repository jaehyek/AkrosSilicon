
// AkrosSiliconView.cpp : implementation of the CAkrosSiliconView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AkrosSilicon.h"
#endif

#include "AkrosSiliconDoc.h"
#include "AkrosSiliconView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAkrosSiliconView

IMPLEMENT_DYNCREATE(CAkrosSiliconView, CFormView)

BEGIN_MESSAGE_MAP(CAkrosSiliconView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_KILLFOCUS(IDC_MFCMASKEDEDIT_REG00, &CAkrosSiliconView::OnEnKillfocusMfcmaskededitReg00)
	//ON_EN_KILLFOCUS(IDC_MFCMASKEDEDIT_REG00_7, &CAkrosSiliconView::OnEnKillfocusMfcmaskededitReg007)
	ON_CONTROL_RANGE(EN_KILLFOCUS, IDC_MFCMASKEDEDIT_REG00_7, IDC_MFCMASKEDEDIT_REG00_0, &CAkrosSiliconView::OnEnKillfocusMfcmaskededitReg00_Bits)
	ON_BN_CLICKED(IDC_SELECT_ALL, &CAkrosSiliconView::OnBnClickedSelectAll)
	ON_BN_CLICKED(IDC_CLEAR_ALL, &CAkrosSiliconView::OnBnClickedClearAll)
	ON_BN_CLICKED(IDC_READ, &CAkrosSiliconView::OnBnClickedRead)
	ON_BN_CLICKED(IDC_WRITE, &CAkrosSiliconView::OnBnClickedWrite)
	ON_COMMAND(ID_VIEW_SHOWREGISTERDEFINITIONS, &CAkrosSiliconView::OnViewShowregisterdefinitions)
END_MESSAGE_MAP()

// CAkrosSiliconView construction/destruction

CAkrosSiliconView::CAkrosSiliconView()
	: CFormView(IDD_AKROSSILICON_FORM)
	, m_strReg00(_T("0x11"))
	, m_strReg00_7(_T("0"))
	, m_strReg00_6(_T("0"))
	, m_strReg00_5(_T("0"))
	, m_strReg00_4(_T("1"))
	, m_strReg00_3(_T("0"))
	, m_strReg00_2(_T("0"))
	, m_strReg00_1(_T("0"))
	, m_strReg00_0(_T("1"))
	, m_boolAlarmAndPowerStatus_R00(FALSE)
	, m_boolInterruptMask_R01(FALSE)
	, m_boolInterruptStatus_R02(FALSE)
	, mp_dlgRegisterDefinition(NULL)
{
	// TODO: add construction code here

}

CAkrosSiliconView::~CAkrosSiliconView()
{
}

void CAkrosSiliconView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00, m_strReg00);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_7, m_strReg00_7);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_6, m_strReg00_6);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_5, m_strReg00_5);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_4, m_strReg00_4);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_3, m_strReg00_3);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_2, m_strReg00_2);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_1, m_strReg00_1);
	DDX_Text(pDX, IDC_MFCMASKEDEDIT_REG00_0, m_strReg00_0);
	DDX_Check(pDX, IDC_ALARM_AND_POWER_STATUS_0X0, m_boolAlarmAndPowerStatus_R00);
	DDX_Check(pDX, IDC_INTERRUPT_MASK_0X1, m_boolInterruptMask_R01);
	DDX_Check(pDX, IDC_INTERRUPT_STATUS_0X2, m_boolInterruptStatus_R02);
	DDX_Control(pDX, IDC_LIST_READ_OUT, m_listReadOut);
}

BOOL CAkrosSiliconView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CAkrosSiliconView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CSelectPortDlg cselectportdlg;
	if (cselectportdlg.DoModal() == IDOK)
	{
		int nport = cselectportdlg.m_nPort;
		CString strPortname;

		strPortname.Format(_T("\\\\.\\COM%d"), nport);

		if (m_serialctrl.OpenPort(CString(_T("19200")), strPortname) == FALSE)
		{
			AfxMessageBox(_T("Can't open the Port"));
		}


	}
	else
	{

	}

	

}

void CAkrosSiliconView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAkrosSiliconView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CAkrosSiliconView diagnostics

#ifdef _DEBUG
void CAkrosSiliconView::AssertValid() const
{
	CFormView::AssertValid();
}

void CAkrosSiliconView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CAkrosSiliconDoc* CAkrosSiliconView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAkrosSiliconDoc)));
	return (CAkrosSiliconDoc*)m_pDocument;
}
#endif //_DEBUG


// CAkrosSiliconView message handlers


void CAkrosSiliconView::OnEnKillfocusMfcmaskededitReg00()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	wchar_t *end = NULL;
	long value = wcstol(m_strReg00, &end, 16);

	if (value & 0x80) m_strReg00_7 = "1";  else m_strReg00_7 = "0";
	if (value & 0x40) m_strReg00_6 = "1";  else m_strReg00_6 = "0";
	if (value & 0x20) m_strReg00_5 = "1";  else m_strReg00_5 = "0";
	if (value & 0x10) m_strReg00_4 = "1";  else m_strReg00_4 = "0";
	if (value & 0x08) m_strReg00_3 = "1";  else m_strReg00_3 = "0";
	if (value & 0x04) m_strReg00_2 = "1";  else m_strReg00_2 = "0";
	if (value & 0x02) m_strReg00_1 = "1";  else m_strReg00_1 = "0";
	if (value & 0x01) m_strReg00_0 = "1";  else m_strReg00_0 = "0";

	UpdateData(FALSE);
}


void CAkrosSiliconView::OnEnKillfocusMfcmaskededitReg00_Bits(UINT idctrl)
{
	// TODO: Add your control notification handler code here
	int total = 0;
	UpdateData(TRUE);

	if (m_strReg00_7 == "1") total += 0x80;
	if (m_strReg00_6 == "1") total += 0x40;
	if (m_strReg00_5 == "1") total += 0x20;
	if (m_strReg00_4 == "1") total += 0x10;
	if (m_strReg00_3 == "1") total += 0x08;
	if (m_strReg00_2 == "1") total += 0x04;
	if (m_strReg00_1 == "1") total += 0x02;
	if (m_strReg00_0 == "1") total += 0x01;

	m_strReg00.Format(_T("0x%x"), total);

	UpdateData(FALSE);
}


void CAkrosSiliconView::OnBnClickedSelectAll()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_boolAlarmAndPowerStatus_R00 = TRUE;
	m_boolInterruptMask_R01 = TRUE;
	m_boolInterruptStatus_R02 = TRUE;
	UpdateData(FALSE);

}


void CAkrosSiliconView::OnBnClickedClearAll()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_boolAlarmAndPowerStatus_R00 = FALSE;
	m_boolInterruptMask_R01 = FALSE;
	m_boolInterruptStatus_R02 = FALSE;
	UpdateData(FALSE);
}


void CAkrosSiliconView::OnBnClickedRead()
{
	// TODO: Add your control notification handler code here
	//UpdateData(TRUE);
	unsigned char data[256];
	unsigned long readlength;
	m_serialctrl.Read(data, sizeof(data), readlength);

	data[0] = 0x01;		// address
	data[1] = 0xab;		// data

	CString strOutput;
	strOutput.Format(_T("%02X:%02X"), data[0], data[1]);


	m_listReadOut.AddString(strOutput);

	//UpdateData(FALSE);

}


void CAkrosSiliconView::OnBnClickedWrite()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_boolAlarmAndPowerStatus_R00 == TRUE)
	{
		char data[2];
		unsigned long written;
		wchar_t *end = NULL;
		long value = wcstol(m_strReg00, &end, 16);

		
		data[0] = 0;
		data[1] = (char)value;
		m_serialctrl.Write(data, 2, written);

		if (written != sizeof(data))
			AfxMessageBox(_T("Fail to write"));
	}
}


void CAkrosSiliconView::OnViewShowregisterdefinitions()
{
	// TODO: Add your command handler code here
	if (mp_dlgRegisterDefinition == NULL)
	{

		mp_dlgRegisterDefinition = new CRegisterDefinitionsDlg(this);
		if (mp_dlgRegisterDefinition)
		{
			mp_dlgRegisterDefinition->Create(CRegisterDefinitionsDlg::IDD, GetDesktopWindow());
			mp_dlgRegisterDefinition->ShowWindow(SW_SHOW);
		}
		else
			AfxMessageBox(_T("Can't creat Windows"));
	}
	else
	{
		mp_dlgRegisterDefinition->SetForegroundWindow();
	}

}


