#pragma once


// CPublic �Ի���

class CPublic : public CDialog
{
	DECLARE_DYNAMIC(CPublic)

public:
	CPublic(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPublic();

// �Ի�������
	enum { IDD = IDD_PUBLIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int ODBC(CString sql);
	void Conn(void);
	void Close(void);
	int Insert(CString sql);
};
