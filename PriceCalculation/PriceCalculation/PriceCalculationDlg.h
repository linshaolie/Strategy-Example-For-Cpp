
// PriceCalculationDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "CashContext.h"
#include "CashNormal.h"
#include "CashDiscount.h"
#include "CashReturn.h"

// CPriceCalculationDlg 对话框
class CPriceCalculationDlg : public CDialog
{
private:
	double m_dTotal;
	CComboBox m_cbCalculateMethor;
	int m_iNum;
	double m_dPrice;
// 构造
public:
	CPriceCalculationDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PRICECALCULATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnBnClickedBtnReset();
};
