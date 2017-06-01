#pragma once
#include "stdafx.h"
#include "CustomTabCtrl.h"

#define IDC_TABCTRL 100
// CTabSDIFrameWnd frame

class CTabSDIFrameWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CTabSDIFrameWnd)
protected:
	CTabSDIFrameWnd();           // protected constructor used by dynamic creation
	virtual ~CTabSDIFrameWnd();

public:
	CCustomTabCtrl& GetTabCtrl() { return m_wndTab; }
	BOOL AddView(CString sLabel, CView* pView, CString sTooltip);
	void DeleteContents();
	BOOL DeleteActiveView();
	BOOL SetCurView(int nNdx);
protected:
	//{{AFX_MSG(CTabSDIFrameWnd)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg void OnSelchangeTabctrl(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickTabctrl(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()

protected:
	CCustomTabCtrl m_wndTab;
};


