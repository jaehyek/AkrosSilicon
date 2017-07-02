
// AkrosSiliconView.h : interface of the CAkrosSiliconView class
//

#pragma once

#include "SerialCtrl.h"
#include "afxwin.h"
#include "SelectPortDlg.h"
#include "RegisterDefinitionsDlg.h"
#include "AkrosSiliconDoc.h"

class CAkrosSiliconView : public CFormView
{
protected: // create from serialization only
	CAkrosSiliconView();
	DECLARE_DYNCREATE(CAkrosSiliconView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_AKROSSILICON_FORM };
#endif

// Attributes
public:
	CAkrosSiliconDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CAkrosSiliconView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strReg00;
	CString m_strReg00_7;
	CString m_strReg00_6;
	CString m_strReg00_5;
	CString m_strReg00_4;
	CString m_strReg00_3;
	CString m_strReg00_2;
	CString m_strReg00_1;
	CString m_strReg00_0;
	afx_msg void OnEnKillfocusMfcmaskededitReg00();
	afx_msg void OnEnKillfocusMfcmaskededitReg00_Bits(UINT idctrl);

	SerialCtrl m_serialctrl;
	BOOL m_boolAlarmAndPowerStatus_R00;
	BOOL m_boolInterruptMask_R01;
	BOOL m_boolInterruptStatus_R02;
	afx_msg void OnBnClickedSelectAll();
	afx_msg void OnBnClickedClearAll();
	afx_msg void OnBnClickedRead();
	afx_msg void OnBnClickedWrite();
	CListBox m_listReadOut;
	afx_msg void OnViewShowregisterdefinitions();
	CRegisterDefinitionsDlg* mp_dlgRegisterDefinition;
};

#ifndef _DEBUG  // debug version in AkrosSiliconView.cpp
inline CAkrosSiliconDoc* CAkrosSiliconView::GetDocument() const
   { return reinterpret_cast<CAkrosSiliconDoc*>(m_pDocument); }
#endif

