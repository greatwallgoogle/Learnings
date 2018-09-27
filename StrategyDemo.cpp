#include <iostream>

using namespace std;
//策略模式：封装算法，所有的这些算法都是相同的工作，只是具体实现不同。
//用于解决不同时间执行不同业务的问题。

//简单工厂模式：封装具体对象的创建

//将策略模式和简单工厂模式结合使用能够更好的降低耦合度


enum CashType
{
	eCashNormal = 0,
	eCashRabeta = 1,
	eCashReturn = 2
};

//父类
class CashSuper
{
public:
	CashSuper(){}
	~CashSuper(){}
	virtual double acceptCash(double money);
	
};

double CashSuper::acceptCash(double money)
{
	cout<<"CashSuper"<<endl;
	return 0.0;
}

//子类
class CashNormal : public CashSuper
{
public:
	CashNormal()
	{
		cout<<"CashNormal 构造函数.."<<endl;
	}
	~CashNormal()
	{
		cout<<"CashNormal 析构函数.."<<endl;
	}
	double acceptCash(double money)
	{
		return money;
	}
};

//子类
class CashRabeta:public CashSuper
{
public:
	CashRabeta(double mRabeta)
	{
		cout<<"CashRabeta 构造函数.."<<endl;
		rabeta = mRabeta;
	}
	~CashRabeta()
	{
		cout<<"CashRabeta 析构函数.."<<endl;
	}
	double acceptCash(double money)
	{
		return money * rabeta;
	}
private:
	double rabeta;
};

//子类
class CashReturn:public CashSuper
{
public:
	CashReturn(double mMoneyCondition,double mMoneyReturn)
	{
		cout<<"CashReturn 构造函数.."<<endl;
		moneyCondition = mMoneyCondition;
		moneyReturn = mMoneyReturn;
	}
	~CashReturn()
	{
		cout<<"CashReturn 析构函数.."<<endl;
	}
	double acceptCash(double money)
	{
		if (money >= moneyCondition)
		{
			double retain = money - moneyCondition;
			double preferent = moneyCondition - moneyReturn;
			money = retain + preferent;
		}

		return money;
	}
private:
	double moneyCondition,moneyReturn;
};


//
class CashContext
{
public:
	CashContext(CashSuper *mCS)
	{
		cs = mCS;
	}
	~CashContext()
	{
		delete cs;
	}

	double getResult(double money)
	{
		if (cs == NULL)
		{
			cout<<"cs  is NULL"<<endl;
		}
		return cs->acceptCash(money);
	}
private:
	CashSuper *cs;
	
};

//策略模式和简单工厂模式结合
class StrategyFactory
{
public:
	StrategyFactory(int type)
	{
		switch(type)
		{
			case eCashNormal:
			cs = new CashNormal();
			break;
			case eCashRabeta:
			cs = new CashRabeta(0.8);
			break;

			case eCashReturn:
			cs = new CashReturn(300,100);
			break;
		}
	}
	~StrategyFactory(){
		delete cs;
	}

	double getResult(double money)
	{
		cout<<"strategy getResult.."<<endl;
		return cs->acceptCash(money);
	}
private:
	CashSuper *cs;
	
};



int main(int argc, char const *argv[])
{
	cout<<"Strategy .."<<endl;

	int type = 2;
	double money = 300;

	CashContext *context;
	switch(type)
	{
		case eCashNormal:
		context = new CashContext(new CashNormal());
		break;
		case eCashRabeta:
		context = new CashContext(new CashRabeta(0.8));
		break;

		case eCashReturn:
		context = new CashContext(new CashReturn(300,100));
		break;
	}
	double result = context->getResult(money);

	/*
	//策略模式和简单工厂模式结合使用
	StrategyFactory *factory = new StrategyFactory(type);
	double result = factory->getResult(money);
	
	*/

	cout<<"result  :  "<<result<<endl;

	return 0;
}
