// RemoteControlDoc.h : interface of the CRemoteControlDoc class
//


#pragma once


class CRemoteControlDoc : public CDocument
{
protected: // create from serialization only
	CRemoteControlDoc();
	DECLARE_DYNCREATE(CRemoteControlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
//	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CRemoteControlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DeleteContents();
};


