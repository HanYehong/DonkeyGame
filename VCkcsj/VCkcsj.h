// VCkcsj.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVCkcsjApp:
// �йش����ʵ�֣������ VCkcsj.cpp
//

class CVCkcsjApp : public CWinApp
{
public:
	CVCkcsjApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVCkcsjApp theApp;