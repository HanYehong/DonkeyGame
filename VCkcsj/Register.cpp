// Register.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Register.h"
#include "afxdb.h"
#include "Public.h"


// Register �Ի���

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


// Register ��Ϣ�������

void Register::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			MessageBox("ע��ɹ���");
			OnOK();
		}
		else
		{
			MessageBox("�û����Ѵ��ڣ�");
		}
	}
	else
	{
		MessageBox("���벻һ�£�");
	}
}
