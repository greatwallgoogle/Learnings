#include "stdafx.h"
#include "XEOperatorSub.h"


XEOperatorSub::XEOperatorSub(EOperatorType eType)
	:XEOperatorBase(eType)
{
}

float XEOperatorSub::Calculate()
{
	return m_fValue1 - m_fValue2;
}
