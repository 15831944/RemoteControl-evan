// RemoteControl.h : main header file for the RemoteControl application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "IniFile.h"

// CRemoteControlApp:
// See RemoteControl.cpp for the implementation of this class
//

class CRemoteControlApp : public CBCGPWinApp
{
public:
	CIniFile m_IniFile;
	// ClientContext 地址为主键
	bool m_bIsQQwryExist;
	bool m_bIsDisablePopTips;
	CView* m_pConnectView; // 主连接视图
	CRemoteControlApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState ();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRemoteControlApp theApp;