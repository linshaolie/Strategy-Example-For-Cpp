#pragma once
#include "cashsuper.h"
class CashReturn : public CashSuper
{
private:
	double m_moneyCondiction;
	double m_moneyReturn;
public:
	CashReturn(int num, double price, double moneyCondiction, double moneyReturn);
	~CashReturn(void);

	const double GetTotalPrice() const;
};

