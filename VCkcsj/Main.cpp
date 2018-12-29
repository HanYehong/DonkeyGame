// Main.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Main.h"
#include "Login.h"
#include "Register.h"
#include "afxdb.h"
#include "Public.h"

// Main �Ի���

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


// Main ��Ϣ�������

void Main::OnBnClickedTologin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Login dlg;
	ShowWindow(SW_HIDE);
	dlg.DoModal();
	ShowWindow(SW_SHOW);
}

void Main::OnBnClickedNewuser()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Register dlg;
	ShowWindow(SW_HIDE);
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//�����ݿ���봦��
	}
	else if (nResponse == IDCANCEL)
	{
		//  ��ȡ�������رնԻ���Ĵ���
	}
	ShowWindow(SW_SHOW);
}

void Main::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}
