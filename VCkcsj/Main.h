#pragma once


// Main 对话框

class Main : public CDialog
{
	DECLARE_DYNAMIC(Main)

public:
	Main(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Main();

// 对话框数据
	enum { IDD = IDD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTologin();
	afx_msg void OnBnClickedNewuser();
	afx_msg void OnBnClickedCancel();
};
