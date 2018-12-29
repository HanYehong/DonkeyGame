// VCkcsjDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "VCkcsj.h"
#include "VCkcsjDlg.h"
#include "time.h"
#include "Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
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

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CVCkcsjDlg 对话框




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


// CVCkcsjDlg 消息处理程序

BOOL CVCkcsjDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	srand(time(NULL));

	// 将“关于...”菜单项添加到系统菜单中。
	GetDlgItem(IDC_STATIC_NUMBER)->SetWindowText("0");
	font.CreatePointFont(150, "隶书");
	GetDlgItem(IDC_STATIC1)->SetFont(&font);
	GetDlgItem(IDC_STATIC2)->SetFont(&font);
	GetDlgItem(IDC_STATIC_NUMBER)->SetFont(&font);
	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CVCkcsjDlg::OnPaint()
{
	CPaintDC dc(this);
	//以下代码添加背景图片
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BEIJING);  //背景图ID
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	
	//以下代码产生随机数的驴坐标
	

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CVCkcsjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVCkcsjDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(click==FALSE)
	{
		GetWindowRect(&rc);
		pWnd = GetDlgItem( IDC_STATIC ); //获取控件指针，IDC_BUTTON1为控件ID号
		CRect rectL;
		GetDlgItem(IDC_STATIC)->GetWindowRect(&rectL); //获取被选中的控件大小
		ScreenToClient(&rectL);  //转化为客户区坐标
		if(point.x> rectL.left+20&&point.x <rectL.left+60) 
		{
			if(point.y <rectL.top+60&&point.y> rectL.top+20)
			{	
				x1 = rand()%700;  
				y1 = rand()%300;
				pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //把按钮移到窗口x1,y1
			//	Invalidate( TRUE ); 
			//	UpdateWindow();  
			}
		}
	}
	else
	{
		x1 = point.x;  
		y1 = point.y;
		pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //把按钮移到窗口x1,y1
	//	Invalidate( TRUE ); 
	//	UpdateWindow();  
	}
	
	CDialog::OnMouseMove(nFlags, point);
}


BOOL CVCkcsjDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
if( IDC_STATIC1  ==  pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
     {
         pDC->SetTextColor(RGB(255,0,0));//设置文本颜色为红色
         pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
         pDC->SetBkColor(RGB(0,0,255));//设置文本背景为蓝色
        hbr=CreateSolidBrush(RGB(0,255,0));//控件的背景色为绿色
    }
	return hbr;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
}*/

void CVCkcsjDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	down=TRUE;
	GetWindowRect(&rc);
	pWnd = GetDlgItem( IDC_STATIC ); //获取控件指针，IDC_BUTTON1为控件ID号
	CRect rectL;
	GetDlgItem(IDC_STATIC)->GetWindowRect(&rectL); //获取被选中的控件大小
	ScreenToClient(&rectL);  //转化为客户区坐标
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	down=FALSE;
	GetWindowRect(&rc);
//	CWnd *pWnd1 = GetDlgItem( IDC_STATIC_ZHALAN ); //获取控件指针，IDC_BUTTON1为控件ID号
	CRect rectL;
	GetDlgItem(IDC_STATIC_ZHALAN)->GetWindowRect(&rectL); //获取被选中的控件大小
	ScreenToClient(&rectL);  //转化为客户区坐标
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
			pWnd->SetWindowPos( NULL,x1,y1,0,0,SWP_NOZORDER | SWP_NOSIZE ); //把按钮移到窗口x1,y1
			Invalidate();
	}
	click=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}

void CVCkcsjDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);

	CDialog::OnClose();
}
