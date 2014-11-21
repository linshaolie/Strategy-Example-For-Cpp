
// PriceCalculationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PriceCalculation.h"
#include "PriceCalculationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPriceCalculationDlg 对话框



CPriceCalculationDlg::CPriceCalculationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriceCalculationDlg::IDD, pParent)
	, m_iNum(0)
	, m_dPrice(0.0)
	, m_dTotal(0.0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPriceCalculationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_CALCULATE_METHOR, m_cbCalculateMethor);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_iNum);
	DDV_MinMaxInt(pDX, m_iNum, 0, 1000000);
	DDX_Text(pDX, IDC_EDIT_COUNT, m_dPrice);
	DDX_Text(pDX, IDC_TOTAL, m_dTotal);
}

BEGIN_MESSAGE_MAP(CPriceCalculationDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPriceCalculationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_RESET, &CPriceCalculationDlg::OnBnClickedBtnReset)
END_MESSAGE_MAP()


// CPriceCalculationDlg 消息处理程序

BOOL CPriceCalculationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_cbCalculateMethor.AddString("正常收费");
	m_cbCalculateMethor.AddString("打8折");
	m_cbCalculateMethor.AddString("满300减100");

	m_cbCalculateMethor.SetCurSel(2);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPriceCalculationDlg::OnPaint()
{
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
HCURSOR CPriceCalculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPriceCalculationDlg::OnBnClickedOk()
{
	UpdateData(TRUE);		//更新数据

	CString sCalculateMethor;
	m_cbCalculateMethor.GetLBText(m_cbCalculateMethor.GetCurSel(), sCalculateMethor);

	CashContext *cc;
	
	if(sCalculateMethor == "打8折")
	{
		cc =  new CashContext(new CashDiscount(m_iNum, m_dPrice, 0.8));
	}
	else if(sCalculateMethor == "满300减100")
	{
		cc =  new CashContext(new CashReturn(m_iNum, m_dPrice, 300, 100));
	}
	else
	{
		cc = new CashContext(new CashNormal(m_iNum, m_dPrice));
	}

	CString saleRecord;
	saleRecord.Format("商品单价：%.2lf元，数量：%d， %s 总价：%.2lf", m_dPrice, m_iNum, sCalculateMethor, cc->GetTotalPrice());
	((CListBox*)GetDlgItem(IDC_LIST_SALE_RECORD))->AddString(saleRecord);

	CString sTotal;
	m_dTotal += cc->GetTotalPrice();		//计算总计
	sTotal.Format("%lf",m_dTotal);
	SetDlgItemText(IDC_TOTAL, sTotal);

	UpdateData(FALSE);

	delete cc;
	//CDialog::OnOK();
}


void CPriceCalculationDlg::OnBnClickedBtnReset()
{
	m_iNum = 0;
	m_dPrice = 0.0;
	m_dTotal = 0.0;
	((CListBox*)GetDlgItem(IDC_LIST_SALE_RECORD))->ResetContent();

	UpdateData(FALSE);
//	CDialog::OnOK();
}
