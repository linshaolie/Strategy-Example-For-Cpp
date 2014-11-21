#include "stdafx.h"
#include "CashReturn.h"


CashReturn::CashReturn(int num, double price,
	double moneyCondiction, double moneyReturn):CashSuper(num, price)
{
	m_moneyCondiction = moneyCondiction;
	m_moneyReturn = moneyReturn;
}


CashReturn::~CashReturn(void)
{
}

const double CashReturn::GetTotalPrice() const
{
	double result = m_num*m_price;
	if(result >= m_moneyCondiction)
	{
		result = result - ((int)(result/m_moneyCondiction))*m_moneyReturn; 
	}
	return result;
}