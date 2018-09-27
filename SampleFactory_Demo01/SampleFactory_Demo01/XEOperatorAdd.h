#pragma once
#include "XEOperatorBase.h"
class XEOperatorAdd : public XEOperatorBase
{
public:
	XEOperatorAdd(EOperatorType eType);
	virtual ~XEOperatorAdd(){}
	virtual float   Calculate();
private:

};
