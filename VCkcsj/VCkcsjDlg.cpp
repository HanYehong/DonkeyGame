// VCkcsjDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "VCkcsjDlg.h"
#include "time.h"
#include "Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
int x1=0,y1=0,x2=0,y2=0;
CRect rc;
CWnd *pWnd= NULL;
static int donkey_number=0;
BOOL click=FALSE;
static CFont font;
BOOL down=FALSE;


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CVCkcsjDlg �Ի���




CVCkcsjDlg::CVCkcsjDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVCkcsjDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCkcsjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVCkcsjDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
//	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CVCkcsjDlg ��Ϣ�������

BOOL CVCkcsjDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	srand(time(NULL));

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	GetDlgItem(IDC_STATIC_NUMBER)->SetWindowText("0");
	font.CreatePointFont(150, "����");
	GetDlgItem(IDC_STATIC1)->SetFont(&font);
	GetDlgItem(IDC_STATIC2)->SetFont(&font);
	GetDlgItem(IDC_STATIC_NUMBER)->SetFont(&font);
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVCkcsjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVCkcsjDlg::OnPaint()
{
	CPaintDC dc(this);
	//���´�����ӱ���ͼƬ
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BEIJING);  //����ͼID
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	
	//���´�������������¿����
	

	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVCkcsjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVCkcsjDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(click==FALSE)
	{
		GetWindowRect(&rc);
		pWnd = GetDlgItem( IDC_STATIC ); //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��
		CRect rectL;
		GetDlgItem(IDC_STATIC)->GetWindowRect(&rectL); //��ȡ��ѡ�еĿؼ���С
		ScreenToClient(&rectL);  //ת��Ϊ�ͻ�������
		if(point.x> rectL.left+20&&point.x <rectL.left+60) 
		{
			if(point.y <rectL.top+60&&point.y> rectL.top+20)
			{	
				x1 = rand()%700;  
				y1 = rand()%300;
				pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //�Ѱ�ť�Ƶ�����x1,y1
			//	Invalidate( TRUE ); 
			//	UpdateWindow();  
			}
		}
	}
	else
	{
		x1 = point.x;  
		y1 = point.y;
		pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //�Ѱ�ť�Ƶ�����x1,y1
	//	Invalidate( TRUE ); 
	//	UpdateWindow();  
	}
	
	CDialog::OnMouseMove(nFlags, point);
}


BOOL CVCkcsjDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	SetCursor(LoadCursor(NULL,   IDC_CURSOR2));
	if(down==TRUE)
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR2));
	else
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	return   TRUE;

//	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

/*HBRUSH CVCkcsjDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
if( IDC_STATIC1  ==  pWnd->GetDlgCtrlID())//�жϷ�����Ϣ�Ŀռ��Ƿ��Ǹþ�̬�ı���
     {
         pDC->SetTextColor(RGB(255,0,0));//�����ı���ɫΪ��ɫ
         pDC->SetBkMode(OPAQUE);//�����ı�����ģʽΪ͸��
         pDC->SetBkColor(RGB(0,0,255));//�����ı�����Ϊ��ɫ
        hbr=CreateSolidBrush(RGB(0,255,0));//�ؼ��ı���ɫΪ��ɫ
    }
	return hbr;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
}*/

void CVCkcsjDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	down=TRUE;
	GetWindowRect(&rc);
	pWnd = GetDlgItem( IDC_STATIC ); //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��
	CRect rectL;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rectL); //��ȡ��ѡ�еĿؼ���С
	ScreenToClient(&rectL);  //ת��Ϊ�ͻ�������
	if((point.x> rectL.left&&point.x <rectL.left+20&&point.y <rectL.top+80&&point.y> rectL.top)||
			(point.x> rectL.left+60&&point.x <rectL.left+80&&point.y <rectL.top+80&&point.y> rectL.top)||
			(point.x> rectL.left&&point.x <rectL.left+80&&point.y <rectL.top+20&&point.y> rectL.top)||
			(point.x> rectL.left&&point.x <rectL.left+80&&point.y <rectL.top+80&&point.y> rectL.top+60)) 
	{
			click=TRUE;
	} 
	CDialog::OnLButtonDown(nFlags, point);
}

void CVCkcsjDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	down=FALSE;
	GetWindowRect(&rc);
//	CWnd *pWnd1 = GetDlgItem( IDC_STATIC_ZHALAN ); //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��
	CRect rectL;
	GetDlgItem(IDC_STATIC_ZHALAN)->GetWindowRect(&rectL); //��ȡ��ѡ�еĿؼ���С
	ScreenToClient(&rectL);  //ת��Ϊ�ͻ�������
	if(point.y>rectL.top) 
	{
			donkey_number++;
	//		CButton *b=(CButton*)GetDlgItem(IDC_EDIT_NUMBER);
			CString str;
			str.Format(_T("%d"),donkey_number);
			LPCTSTR pStr = LPCTSTR(str);
			GetDlgItem(IDC_STATIC_NUMBER)->SetWindowText(str);
	//		b->SetWindowTextW(pStr);
			x1 = rand()%700;  
			y1 = rand()%300;
			pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //�Ѱ�ť�Ƶ�����x1,y1
			Invalidate();
	}
	click=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}

void CVCkcsjDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(0);

	CDialog::OnClose();
}
