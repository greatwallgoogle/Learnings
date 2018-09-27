#pragma once

class XEOperatorBase
{
public:
	//��������ö�٣������������ӣ����翪����N�η��ȵȣ�ÿ��ö�ٶ���Ӧһ�����ࡣ
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

	// �����з�����ȡ������
	void            SetValue1(float fTempValue){ m_fValue1 = fTempValue; }
	void			SetValue2(float fTempValue){ m_fValue2 = fTempValue; }
	virtual float   Calculate() = 0;

protected:
	float			m_fValue1;
	float			m_fValue2;
	EOperatorType	m_eType;
private:
};