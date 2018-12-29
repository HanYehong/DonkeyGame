#pragma once


// CPublic 对话框

class CPublic : public CDialog
{
	DECLARE_DYNAMIC(CPublic)

public:
	CPublic(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPublic();

// 对话框数据
	enum { IDD = IDD_PUBLIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int ODBC(CString sql);
	void Conn(void);
	void Close(void);
	int Insert(CString sql);
};
