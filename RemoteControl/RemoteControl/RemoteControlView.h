// RemoteControlView.h : interface of the CRemoteControlView class
//


#pragma once
#include "RemoteControlDoc.h"

class CRemoteControlView : public CListView
{
protected: // create from serialization only
	CRemoteControlView();
	DECLARE_DYNCREATE(CRemoteControlView)

// Attributes
public:
	CRemoteControlDoc* GetDocument() const;
	CListCtrl *m_pListCtrl;
// Operations
public:

// Overrides
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CRemoteControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg LRESULT OnChangeVisualManager(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnMyinitialupdate(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in RemoteControlView.cpp
inline CRemoteControlDoc* CRemoteControlView::GetDocument() const
   { return reinterpret_cast<CRemoteControlDoc*>(m_pDocument); }
#endif

