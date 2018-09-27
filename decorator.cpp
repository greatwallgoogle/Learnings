#include <iostream>

using namespace std;
//decorator 装饰者模式
//举例：一个人的穿衣打扮


class Person//充当component角色
{
public:
	Person(){}
	Person(string vName)
	{
		name = vName;
	}
	~Person(){}
	virtual void show()
	{
		cout<<"装扮的"<<name<<endl;
	}
private:
	string name;	
};

class FineryDecorator : public Person//服饰类，充当Decorator角色
{
public:
	FineryDecorator(){}
	void decorator(Person *mComponent)
	{
		component = mComponent;
	}
	~FineryDecorator(){}
	void show()
	{
		if (component != NULL)
		{
			component->show();
		}
	}
protected:
	Person	*component;
};

class TShirts:public FineryDecorator//具体服饰类，充当ConcreteDecorator
{
public:
	TShirts(){}
	~TShirts(){}
	void show()
	{
		cout<<"大T恤 ";
		component->show();
	}
	
};

class BigTrouser:public FineryDecorator
{
public:
	BigTrouser(){}
	~BigTrouser(){}
	void show()
	{
		cout<<"垮裤 ";
		component->show();

	}
	
};

class LeatherShoe:public FineryDecorator
{
public:
	LeatherShoe(){}
	~LeatherShoe(){}
	void show()
	{
		cout<<"皮鞋 ";
		component->show();
	}
	
};

class Western:public FineryDecorator
{
public:
	Western(){}
	~Western(){}
	void show()
	{
		cout<<"西装 ";
		component->show();
	}
	
};
//。。。。。


void destory(Person *obj)
{
	if (obj != NULL)
	{
		delete obj;
		obj = NULL;
	}
}
int main(int argc, char const *argv[])
{
	cout<<"decorator pattern.."<<endl;
	Person *mPerson = new Person("小明");
	TShirts *tshirt = new TShirts();
	BigTrouser *bt = new BigTrouser();
	LeatherShoe *shoe = new LeatherShoe();
	Western *mWestern = new Western();

	cout<<"第一种打扮方式："<<endl;
	shoe->decorator(mPerson);
	bt->decorator(shoe);
	tshirt->decorator(bt);
	tshirt->show();
	cout<<endl<<"第二种打扮方式："<<endl;
	mWestern->decorator(mPerson);
	mWestern->show();

	destory(mPerson);
	destory(tshirt);
	destory(bt);
	destory(shoe);
	destory(mWestern);
	return 0;
}