#pragma once
#include <string>
#include "CashSuper.h"

class CashContext
{
private:
		CashSuper *m_pCs;
public:
	CashContext(CashSuper *cs);
	~CashContext(void);

	const double GetTotalPrice() const; 
};

