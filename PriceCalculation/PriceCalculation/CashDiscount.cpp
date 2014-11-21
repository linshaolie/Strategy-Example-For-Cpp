#include "stdafx.h"
#include "CashDiscount.h"


CashDiscount::CashDiscount(int num, double price, double rebate)
	:CashSuper(num, price)
{
	m_moneyRebate = rebate;
}


CashDiscount::~CashDiscount(void)
{
}

const double CashDiscount::GetTotalPrice() const
{
	return (m_num*m_price*m_moneyRebate);
}