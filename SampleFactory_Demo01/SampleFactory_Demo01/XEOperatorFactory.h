#pragma once
#include "stdafx.h"
#include "XEOpeatorInclude.h"
class XEOperatorFactory
{
public:
	static XEOperatorBase* CreateOperator(int nType);
};