// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Login.h"
#include "VCkcsjDlg.h"
#include "Public.h"


// Login 对话框

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


// Login 消息处理程序

void Login::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
		MessageBox("用户名不存在或者密码错误！");
	}
	else
	{
		MessageBox("登录成功！");
		CVCkcsjDlg dlg;
		OnOK();
		dlg.DoModal();
	}
}

