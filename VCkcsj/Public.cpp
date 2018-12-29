// Public.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "Public.h"
#include "afxdb.h"

CDatabase m_db;
CRecordset rs;
// CPublic �Ի���

IMPLEMENT_DYNAMIC(CPublic, CDialog)

CPublic::CPublic(CWnd* pParent /*=NULL*/)
	: CDialog(CPublic::IDD, pParent)
{

}

CPublic::~CPublic()
{
}

void CPublic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPublic, CDialog)
END_MESSAGE_MAP()


// CPublic ��Ϣ�������

int CPublic::ODBC(CString sql)
{      
	Conn();         
	CString result=_T("");       
	TRY        
	{       
		rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);  
  //�򿪲�ѯ��¼       
		rs.GetFieldValue(_T("username"),result);
	}       
	CATCH(CDBException,ex)        
	{            
//	  AfxMessageBox(ex->m_strError);   
//	  AfxMessageBox(ex->m_strStateNativeOrigin);        
	}
	AND_CATCH(CMemoryException,pEx)   
	{            
		pEx->ReportError();            
		AfxMessageBox(_T("memory exception"));     
	}  
	END_CATCH   
	Close();
	if(result=="")
		return 0;
	else
		return 1;
}

void CPublic::Conn(void)
{
	TRY   
	{      
		m_db.OpenEx(_T("DSN=Test;"),CDatabase::noOdbcDialog);//���ӵ�һ����ΪTest������Դ 
		rs.m_pDatabase = &m_db;   
	}  
//�����쳣��Ϣ  
	CATCH(CDBException,ex)  
	{      
		AfxMessageBox(ex->m_strError);  
		AfxMessageBox(ex->m_strStateNativeOrigin);   
	}   
	AND_CATCH(CMemoryException,pEx)   
	{   
		pEx->ReportError();   
		AfxMessageBox(_T("memory exception"));   
	}
	AND_CATCH(CException,ex)   
	{      
		TCHAR szError[100];      
		ex->GetErrorMessage(szError,100);      
		AfxMessageBox(szError);   
	}   
	END_CATCH  
//	MessageBox(L"���ӳɹ�");  
}

void CPublic::Close(void)
{
	rs.Close();
	m_db.Close();
}

int CPublic::Insert(CString sql)
{
	Conn();
	TRY   
	{      
		m_db.ExecuteSQL(sql);
	}  
//�����쳣��Ϣ  
	CATCH(CDBException,ex)  
	{        
		Close();
		return 0;
	}   
	AND_CATCH(CMemoryException,pEx)   
	{   
		Close();
		return 0;
	}
	AND_CATCH(CException,ex)   
	{       
		Close();
		return 0;
	}   
	END_CATCH  
	Close();
	return 1;
}
