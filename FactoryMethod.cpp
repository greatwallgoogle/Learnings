#include <iostream>

using namespace std;
//学雷锋精神，先用简单工厂模式实现，然后再用工厂方法模式实现，最后对比两者

class LearnLeiFeng
{
public:
	LearnLeiFeng(){}
	~LearnLeiFeng(){}
	virtual void sweep()
	{
		cout<<"扫地 "<<endl;
	}

	virtual void wash()
	{
		cout<<"洗衣服 "<<endl;
	}

	virtual void buyRice()
	{
		cout<<"买米 "<<endl;
	}
	
};

class UnderGraduate : public LearnLeiFeng
{
public:
	UnderGraduate(){}
	~UnderGraduate(){}
	void sweep()
	{
		cout<<"学雷锋的大学生扫地 "<<endl;
	}

	void wash()
	{
		cout<<"学雷锋的大学生洗衣服 "<<endl;
	}

	void buyRice()
	{
		cout<<"学雷锋的大学生买米 "<<endl;
	} 
};

class  Volunteer : public LearnLeiFeng
{
public:
	 Volunteer(){}
	~ Volunteer(){}

	void sweep()
	{
		cout<<"志愿者 扫地 "<<endl;
	}

	void wash()
	{
		cout<<"志愿者 洗衣服 "<<endl;
	}

	void buyRice()
	{
		cout<<"志愿者 买米 "<<endl;
	} 
};

enum LeiFengType
{
	eTpye_UnderGraduate = 0,
	eTpye_Volunteer = 1,
};
//简单工厂模式
class LeiFengFactory
{
public:
	LeiFengFactory(){}

	static LearnLeiFeng *createLeiFeng(LeiFengType type)
	{
		switch(type)
		{
			case eTpye_UnderGraduate:
			return new UnderGraduate();
			break;
			case eTpye_Volunteer:
			return new Volunteer();
			break;
			
		}
	}
	~LeiFengFactory(){}
	
};

//工厂方法模式
class IFactory
{
public:
	IFactory(){}
	~IFactory(){}
	virtual LearnLeiFeng *createLeiFeng() = 0;
};

class UnderGraduateFactory : public IFactory
{
public:
	UnderGraduateFactory(){}
	~UnderGraduateFactory(){}
	LearnLeiFeng *createLeiFeng()
	{
		return new UnderGraduate();
	}
	
};

class VolunteerFactory:public IFactory
{
public:
	VolunteerFactory(){}
	~VolunteerFactory(){}
	LearnLeiFeng *createLeiFeng()
	{
		return new Volunteer();
	}
	
};

int main(int argc, char const *argv[])
{
	cout<<"简单工厂模式的使用   start..."<<endl;

	//简单工厂模式的使用   start
	LearnLeiFeng *mLearnLeiFeng = LeiFengFactory::createLeiFeng(eTpye_UnderGraduate);
	mLearnLeiFeng->wash();
	mLearnLeiFeng->sweep();
	mLearnLeiFeng->buyRice();

	cout<<endl;
	LearnLeiFeng *mLearnLeiFeng2 = LeiFengFactory::createLeiFeng(eTpye_Volunteer);
	mLearnLeiFeng2->wash();
	mLearnLeiFeng2->sweep();
	mLearnLeiFeng2->buyRice();

	cout<<endl;
	LearnLeiFeng *mLearnLeiFeng3 = LeiFengFactory::createLeiFeng(eTpye_Volunteer);
	mLearnLeiFeng3->wash();
	mLearnLeiFeng3->sweep();
	mLearnLeiFeng3->buyRice();

	//简单工厂模式的使用   end
	cout<<"简单工厂模式的使用   end..."<<endl;

	//======================================
	cout<<endl;
	cout<<"工厂方法模式的使用   start..."<<endl;
	IFactory *factory = new VolunteerFactory();
	LearnLeiFeng *xueLeiFeng = factory->createLeiFeng();
	xueLeiFeng->wash();
	xueLeiFeng->buyRice();
	xueLeiFeng->sweep();

	cout<<endl;
	
	cout<<"工厂方法模式的使用   end..."<<endl;
	return 0;
}