#include <iostream>
#include <vector>
using namespace std;
//建造者模式：四个组成部分
//1. 产品：用一个列表或数组存储组成一个完整产品的部件
//2. 指挥者：指挥建造过程，并隔离建造过程与用户之间的关联
//3. 抽象建造者：声明需要建造零件的接口方法
//4. 具体建造者：实现接口方法，建造指定的零件，并将零件添加到产品，并返回完整的产品

class Product
{
public:
	Product(){}
	~Product(){}
	void add(string part)//添加产品零件
	{
		//push_back
		parts.push_back(part);
	}

	void show()
	{
		cout<<"产品创建开始："<<endl;
		for (std::vector<string>::iterator i = parts.begin(); i != parts.end(); ++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl<<"产品创建结束！"<<endl;

	}
private:
	std::vector<string> parts;
	
};

class Builder
{
public:
	Builder(){}
	~Builder(){}
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual Product getResult() = 0;
};

class ConcreteBuilderA : public Builder
{
public:
	ConcreteBuilderA(){}
	~ConcreteBuilderA(){}
	void buildPartA()
	{
		mProduct.add("部件A");
	}

	void buildPartB()
	{
		mProduct.add("部件B");
	}

	Product getResult()
	{
		return mProduct;
	}
private:
	Product mProduct;
};

class ConcreteBuilderB:public Builder
{
public:
	ConcreteBuilderB(){}
	~ConcreteBuilderB(){}
	void buildPartA()
	{
		mProduct.add("部件X");
	}

	void buildPartB()
	{
		mProduct.add("部件Y");
	}

	Product getResult()
	{
		return mProduct;
	}
private:
	Product mProduct;
	
};

class Director
{
public:
	Director(){}
	~Director(){}
	Product construct(Builder *mBuilder)//用来指挥建造过程和隔离建造过程与用户之间的关联
	{
		mBuilder->buildPartA();
		mBuilder->buildPartB();
		return mBuilder->getResult();
	}
	
};

int main(int argc, char const *argv[])
{
	cout<<"==========="<<endl;

	//指挥者
	Director *mDirector = new Director();

	//指定具体的建造者
	Builder *mBuilder = new ConcreteBuilderA();

	//根据建造者的建造方法建造产品
	Product mProduct = mDirector->construct(mBuilder);

	//获取产品
	// Product mProduct = mBuilder->getResult();

	mProduct.show();

	return 0;
}