// Main.cpp : 实现文件
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Main.h"
#include "Login.h"
#include "Register.h"
#include "afxdb.h"
#include "Public.h"

// Main 对话框

IMPLEMENT_DYNAMIC(Main, CDialog)

Main::Main(CWnd* pParent /*=NULL*/)
	: CDialog(Main::IDD, pParent)
{
//	CPublic conn;
//	conn.Conn();
}

Main::~Main()
{
}

void Main::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Main, CDialog)
	ON_BN_CLICKED(TOLOGIN, &Main::OnBnClickedTologin)
	ON_BN_CLICKED(NEWUSER, &Main::OnBnClickedNewuser)
	ON_BN_CLICKED(CANCEL, &Main::OnBnClickedCancel)
END_MESSAGE_MAP()


// Main 消息处理程序

void Main::OnBnClickedTologin()
{
	// TODO: 在此添加控件通知处理程序代码
	Login dlg;
	ShowWindow(SW_HIDE);
	dlg.DoModal();
	ShowWindow(SW_SHOW);
}

void Main::OnBnClickedNewuser()
{
	// TODO: 在此添加控件通知处理程序代码
	Register dlg;
	ShowWindow(SW_HIDE);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//做数据库插入处理
	}
	else if (nResponse == IDCANCEL)
	{
		//  “取消”来关闭对话框的代码
	}
	ShowWindow(SW_SHOW);
}

void Main::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
