#pragma once
class CashSuper
{
protected:
	int m_num;
	double m_price;
	
	CashSuper(int num, double price);
public:
	const virtual double GetTotalPrice() const=0;
};

