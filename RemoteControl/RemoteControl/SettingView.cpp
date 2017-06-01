// SettingView.cpp : implementation file
//

#include "stdafx.h"
#include "RemoteControl.h"
#include "SettingView.h"


// CSettingView

IMPLEMENT_DYNCREATE(CSettingView, CFormView)

CSettingView::CSettingView()
	: CFormView(IDD_SETTINGVIEW)
{

}

CSettingView::~CSettingView()
{
}

void CSettingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSettingView, CFormView)
END_MESSAGE_MAP()


// CSettingView diagnostics

#ifdef _DEBUG
void CSettingView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSettingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSettingView message handlers
