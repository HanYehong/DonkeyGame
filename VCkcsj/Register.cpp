// Register.cpp : 实现文件
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Register.h"
#include "afxdb.h"
#include "Public.h"


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialog)

Register::Register(CWnd* pParent /*=NULL*/)
	: CDialog(Register::IDD, pParent)
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Register, CDialog)
	ON_BN_CLICKED(IDOK, &Register::OnBnClickedOk)
END_MESSAGE_MAP()


// Register 消息处理程序

void Register::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CPublic conn;
	CString sql=_T("");
	CString str;
	CString str2;
	CString str3;
	GetDlgItemText(IDC_USERNAME,str);
	GetDlgItemText(IDC_PASSWORD,str2);
	GetDlgItemText(IDC_PASSWORD2,str3);
	char *p1=(char*)(LPCTSTR)str2;
	char *p2=(char*)(LPCTSTR)str3;
	if(strcmp(p1,p2)==0)
	{
		sql.Append("insert into mem values('");
		sql.Append(str);
		sql.Append("','");
		sql.Append(str2);
		sql.Append("')");
		int i=conn.Insert(sql);
		if(i==1)
		{
			MessageBox("注册成功！");
			OnOK();
		}
		else
		{
			MessageBox("用户名已存在！");
		}
	}
	else
	{
		MessageBox("密码不一致！");
	}
}
