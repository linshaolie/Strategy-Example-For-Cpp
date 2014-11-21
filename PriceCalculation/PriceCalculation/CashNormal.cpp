#include "stdafx.h"
#include "CashNormal.h"


CashNormal::CashNormal(int num, double price):CashSuper(num, price)
{
	
}


CashNormal::~CashNormal(void)
{
}

const double CashNormal::GetTotalPrice() const
{
	return (m_num*m_price);
}