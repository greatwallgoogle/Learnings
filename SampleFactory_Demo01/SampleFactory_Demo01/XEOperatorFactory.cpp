#include "stdafx.h"
#include "XEOperatorFactory.h"

XEOperatorBase* XEOperatorFactory::CreateOperator(int nType)
{
	XEOperatorBase* pOperator = NULL;
	XEOperatorBase::EOperatorType eOpeartorType = (XEOperatorBase::EOperatorType)nType;
	switch (nType)
	{
	case XEOperatorBase::TOT_ADD:
		pOperator = new XEOperatorAdd(eOpeartorType);
		break;
	case XEOperatorBase::TOT_SUB:
		pOperator = new XEOperatorSub(eOpeartorType);
		break;
	case XEOperatorBase::TOT_MULT:
		pOperator = new XEOperatorMult(eOpeartorType);
		break;
	case XEOperatorBase::TOT_DIV:
		pOperator = new XEOperatorDiv(eOpeartorType);
		break;
	default:
		break;
	}
	return pOperator;
}
