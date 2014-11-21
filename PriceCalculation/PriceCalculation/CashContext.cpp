#include "stdafx.h"
#include "CashContext.h"
#include "CashNormal.h"
#include "CashDiscount.h"
#include "CashReturn.h"



CashContext::CashContext(CashSuper *cs)
{
	this->m_pCs = cs ;
}

CashContext::~CashContext(void)
{
	delete m_pCs ;
}

const double CashContext::GetTotalPrice() const
{
	return m_pCs->GetTotalPrice();
}