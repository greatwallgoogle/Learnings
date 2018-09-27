// SampleFactory_Demo01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XEOpeatorInclude.h"
#include "XEOperatorFactory.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//��C++������������ʵ��һ������������̨����Ҫ����������������������õ������
//ʹ�ü򵥹���ģʽ�����ڼ̳С���̬������ϡ�
//1. �ⲿͨ�������麯�����麯��ʱ������Ҫ֪���������ھ���Ĳ�����
//2. ͨ���̳У���������ʵ�־���ĺ������ܡ�
//3. ��չ�¹���ʱ��ֻ��Ҫ3�����裺1�����Ӿ�������ࣻ2�����Ӳ������͵�ö�٣�3�����ݲ��������޸ļ򵥹����д�������ķ�����
//4. ���ڱ������ԣ���������ӿ�����ƽ���ȹ��ܣ�ֻ��Ҫ����һ�����������������һ��N�η����������࣬���޸ļ򵥹���������������ķ������ɣ�
//   ͬʱ�������޸����еĹ��ܡ�
//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	float fValue1 = 0, fValue2 = 0;
	cout << "Please input first num:";
	cin >> fValue1;
	cout << "Please input second num:";
	cin >> fValue2;

	cout << "Please input type<0:Add��1:Sub��2:Mul��3:Div>:";
	int nOperator;
	cin >> nOperator;

	XEOperatorBase* pOperator = XEOperatorFactory::CreateOperator(nOperator);
	if (pOperator)
	{
		pOperator->SetValue1(fValue1);
		pOperator->SetValue2(fValue2);
		float fRes = pOperator->Calculate();
		cout << "The result is : " << fRes << endl;
	}

	if (pOperator)
	{
		delete pOperator;
		pOperator = NULL;
	}
	system("pause");
	return 0;
}
