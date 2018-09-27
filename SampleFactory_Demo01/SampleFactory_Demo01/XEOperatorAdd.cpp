#include "stdafx.h"
#include "XEOperatorAdd.h"

XEOperatorAdd::XEOperatorAdd(EOperatorType eType)
	:XEOperatorBase(eType)
{
}

float XEOperatorAdd::Calculate()
{
	return m_fValue1 + m_fValue2;
}
