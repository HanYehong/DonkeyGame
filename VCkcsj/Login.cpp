// Login.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Login.h"
#include "VCkcsjDlg.h"
#include "Public.h"


// Login �Ի���

IMPLEMENT_DYNAMIC(Login, CDialog)

Login::Login(CWnd* pParent /*=NULL*/)
	: CDialog(Login::IDD, pParent)
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Login, CDialog)
	ON_BN_CLICKED(IDOK, &Login::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Login ��Ϣ�������

void Login::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPublic conn;
	CString sql=_T("select * from mem where username='");
	CString str;
	GetDlgItemText(IDC_USER,str);
	sql.Append(str);
	sql.Append("' and password='");
	CString str2;
	GetDlgItemText(IDC_PWD,str2);
	sql.Append(str2);
	sql.Append("'");
	int i=conn.ODBC(sql);
	if(i==0)
	{
		MessageBox("�û��������ڻ����������");
	}
	else
	{
		MessageBox("��¼�ɹ���");
		CVCkcsjDlg dlg;
		OnOK();
		dlg.DoModal();
	}
}

