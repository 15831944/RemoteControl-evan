// MainFrm.h : interface of the CMainFrame class
//


#pragma once

#include "TabSDIFrameWnd.h"

#define CFrameWnd CTabSDIFrameWnd
class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:
	
	void Activate(UINT nPort, UINT nMaxConnections);
// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar			m_wndStatusBar;
	CToolBar			m_wndToolBar;
// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnToolbarReset(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()


};
