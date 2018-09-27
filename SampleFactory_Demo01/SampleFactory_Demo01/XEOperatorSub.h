#pragma once
#include "XEOperatorBase.h"

class XEOperatorSub : public XEOperatorBase
{
public:
	XEOperatorSub(EOperatorType eType);
	virtual ~XEOperatorSub(){}
	virtual float   Calculate();
private:

};
