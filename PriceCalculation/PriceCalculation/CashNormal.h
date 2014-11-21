#pragma once
#include "cashsuper.h"

class CashNormal : public CashSuper
{

public:
	CashNormal(int num, double price);
	~CashNormal(void);

	const double GetTotalPrice() const ;
};

