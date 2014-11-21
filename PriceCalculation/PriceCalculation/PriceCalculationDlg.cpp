
// PriceCalculationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PriceCalculation.h"
#include "PriceCalculationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPriceCalculationDlg �Ի���



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


// CPriceCalculationDlg ��Ϣ�������

BOOL CPriceCalculationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_cbCalculateMethor.AddString("�����շ�");
	m_cbCalculateMethor.AddString("��8��");
	m_cbCalculateMethor.AddString("��300��100");

	m_cbCalculateMethor.SetCurSel(2);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPriceCalculationDlg::OnPaint()
{
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
HCURSOR CPriceCalculationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPriceCalculationDlg::OnBnClickedOk()
{
	UpdateData(TRUE);		//��������

	CString sCalculateMethor;
	m_cbCalculateMethor.GetLBText(m_cbCalculateMethor.GetCurSel(), sCalculateMethor);

	CashContext *cc;
	
	if(sCalculateMethor == "��8��")
	{
		cc =  new CashContext(new CashDiscount(m_iNum, m_dPrice, 0.8));
	}
	else if(sCalculateMethor == "��300��100")
	{
		cc =  new CashContext(new CashReturn(m_iNum, m_dPrice, 300, 100));
	}
	else
	{
		cc = new CashContext(new CashNormal(m_iNum, m_dPrice));
	}

	CString saleRecord;
	saleRecord.Format("��Ʒ���ۣ�%.2lfԪ��������%d�� %s �ܼۣ�%.2lf", m_dPrice, m_iNum, sCalculateMethor, cc->GetTotalPrice());
	((CListBox*)GetDlgItem(IDC_LIST_SALE_RECORD))->AddString(saleRecord);

	CString sTotal;
	m_dTotal += cc->GetTotalPrice();		//�����ܼ�
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
