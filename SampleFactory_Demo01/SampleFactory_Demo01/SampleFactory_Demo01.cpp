// SampleFactory_Demo01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XEOpeatorInclude.h"
#include "XEOperatorFactory.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
//用C++面向对象的语言实现一个计算器控制台程序，要求输入两个数和运算符，得到结果。
//使用简单工厂模式，基于继承、多态减少耦合。
//1. 外部通过调用虚函数或纯虚函数时，不需要知道函数体内具体的操作。
//2. 通过继承，在子类中实现具体的函数功能。
//3. 扩展新功能时，只需要3个步骤：1、增加具体的子类；2、增加操作类型的枚举；3、根据操作类型修改简单工厂中创建对象的方法。
//4. 对于本例而言，若后续添加开方、平方等功能，只需要增加一个开方操作的子类和一个N次方操作的子类，并修改简单工厂创建操作对象的方法即可，
//   同时还不必修改已有的功能。
//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	float fValue1 = 0, fValue2 = 0;
	cout << "Please input first num:";
	cin >> fValue1;
	cout << "Please input second num:";
	cin >> fValue2;

	cout << "Please input type<0:Add，1:Sub，2:Mul，3:Div>:";
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
