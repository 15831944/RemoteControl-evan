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
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CSettingView::OnBnClickedMfcbutton1)
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


void CSettingView::OnBnClickedMfcbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
