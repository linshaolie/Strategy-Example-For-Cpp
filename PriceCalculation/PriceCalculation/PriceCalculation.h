
// PriceCalculation.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPriceCalculationApp:
// �йش����ʵ�֣������ PriceCalculation.cpp
//

class CPriceCalculationApp : public CWinApp
{
public:
	CPriceCalculationApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPriceCalculationApp theApp;