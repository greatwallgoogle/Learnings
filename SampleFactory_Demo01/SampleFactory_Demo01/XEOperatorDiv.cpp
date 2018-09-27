#include "stdafx.h"

#include "XEOperatorDiv.h"

XEOperatorDiv::XEOperatorDiv(EOperatorType eType)
	:XEOperatorBase(eType)
{
}

float XEOperatorDiv::Calculate()
{
	if (abs(m_fValue2) < 1e-7)
		return 0;

	return m_fValue1 / m_fValue2;
}
