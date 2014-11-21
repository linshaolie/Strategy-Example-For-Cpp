#pragma once
#include "cashsuper.h"
class CashDiscount : public CashSuper
{
private:
	double m_moneyRebate;		//Дђел
public:
	CashDiscount(int num, double price, double rebate);
	~CashDiscount(void);

	const double GetTotalPrice() const;
};

