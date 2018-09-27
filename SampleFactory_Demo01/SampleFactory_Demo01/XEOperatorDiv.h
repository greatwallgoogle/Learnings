#pragma once
#include "XEOperatorBase.h"
class XEOperatorDiv : public XEOperatorBase
{
public:
	XEOperatorDiv(EOperatorType eType);
	virtual ~XEOperatorDiv(){}
	virtual float   Calculate();
};
