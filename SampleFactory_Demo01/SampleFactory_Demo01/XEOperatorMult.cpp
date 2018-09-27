#include "stdafx.h"
#include "XEOperatorMult.h"


XEOperatorMult::XEOperatorMult(EOperatorType eType)
	:XEOperatorBase(eType)
{
}

float XEOperatorMult::Calculate()
{
	return m_fValue1 * m_fValue2;
}
