#pragma once


// Main �Ի���

class Main : public CDialog
{
	DECLARE_DYNAMIC(Main)

public:
	Main(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Main();

// �Ի�������
	enum { IDD = IDD_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTologin();
	afx_msg void OnBnClickedNewuser();
	afx_msg void OnBnClickedCancel();
};
