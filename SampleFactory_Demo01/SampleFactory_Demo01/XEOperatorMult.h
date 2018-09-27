#pragma once
#include "XEOperatorBase.h"

class XEOperatorMult : public XEOperatorBase
{
public:
	XEOperatorMult(EOperatorType eType);
	virtual ~XEOperatorMult(){}
	virtual float   Calculate();
};