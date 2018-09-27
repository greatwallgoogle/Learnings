#include <iostream>

using namespace std;

#define SAFE_DELETE(p) {if(p){delete p;p = NULL;}}

//模板方法模式：父类中声明一个具体的模板方法和若干个抽象方法，模板方法中给出了顶级的逻辑骨架，
//而逻辑的具体实现在抽象方法中，这就使得抽象方法的实现推迟到子类中实现，从而使不同的子类对
//抽象方法进行不同的实现，使顶级逻辑的实现各不相同。

//适用情况：当不变的和可变的行为在子类的方法中混合在一起时，不变的行为会在不同的子类中
//重复出现，这种情况下使用模板方法模式。


//以学生做试卷为例
class TestPaper
{
public:
	TestPaper(){cout<<"TestPaper 构造函数---"<<endl;}
	~TestPaper(){cout<<"TestPaper 析构函数..."<<endl;}
	virtual string answer1()
	{
		return "";
	}
	virtual string answer2()
	{
		return "";
	}
	void testQuestion1()
	{
		cout<<"杨过得到，后来给了郭靖，炼成了倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维"<<endl;
		cout<<"答案："<<answer1()<<endl;
	}

	void testQuestion2()
	{
		cout<<"杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化"<<endl;
		cout<<"答案："<<answer2()<<endl;
	}
	
};

class TestPaper1:public TestPaper
{
public:
	TestPaper1(){cout<<"TestPaper1 构造函数---"<<endl;}
	~TestPaper1(){cout<<"TestPaper1 析构函数..."<<endl;}
	string answer1()
	{
		return "b";
	}
	string answer2()
	{
		return "c";
	}
	
};
class TestPaper2:public TestPaper
{
public:
	TestPaper2(){cout<<"TestPaper2 构造函数---"<<endl;}
	~TestPaper2(){cout<<"TestPaper2 析构函数..."<<endl;}
	string answer1()
	{
		return "d";
	}

	string answer2()
	{
		return "a";
	}
};


int main(int argc, char const *argv[])
{
	cout<<"Template Method Pattern"<<endl;

	cout<<"学生一的试卷："<<endl;
	TestPaper *mTestPaper1 = new TestPaper1();
	mTestPaper1->testQuestion1();
	mTestPaper1->testQuestion2();
	SAFE_DELETE(mTestPaper1);

	cout<<endl<<"学生二的试卷："<<endl;
	TestPaper *mTestPaper2 = new TestPaper2();
	mTestPaper2->testQuestion1();
	mTestPaper2->testQuestion2();
	SAFE_DELETE(mTestPaper2);

	return 0;
}