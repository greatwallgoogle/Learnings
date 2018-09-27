#pragma once

class XEOperatorBase
{
public:
	//操作类型枚举，后续可以增加，例如开方、N次方等等，每个枚举都对应一个子类。
	enum EOperatorType
	{
		TOT_ADD,
		TOT_SUB,
		TOT_MULT,
		TOT_DIV
	};
	XEOperatorBase(EOperatorType eType)
		:m_eType(eType){}
	virtual ~XEOperatorBase(){}

	// 将共有方法提取到基类
	void            SetValue1(float fTempValue){ m_fValue1 = fTempValue; }
	void			SetValue2(float fTempValue){ m_fValue2 = fTempValue; }
	virtual float   Calculate() = 0;

protected:
	float			m_fValue1;
	float			m_fValue2;
	EOperatorType	m_eType;
private:
};