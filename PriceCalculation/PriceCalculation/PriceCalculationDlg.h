
// PriceCalculationDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "CashContext.h"
#include "CashNormal.h"
#include "CashDiscount.h"
#include "CashReturn.h"

// CPriceCalculationDlg �Ի���
class CPriceCalculationDlg : public CDialog
{
private:
	double m_dTotal;
	CComboBox m_cbCalculateMethor;
	int m_iNum;
	double m_dPrice;
// ����
public:
	CPriceCalculationDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PRICECALCULATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnBnClickedBtnReset();
};
