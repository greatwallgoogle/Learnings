#include <iostream>

using namespace std;

#define SALF_DELETE(p) if(p != NULL){delete p;p = NULL;}

class Girl
{
public:
	Girl(string vname)
	{
		name = vname;
	}
	~Girl(){}
	string getName()
	{
		return name;
	}
private:
	string name;
};

class GiveGift
{
public:
	GiveGift(){}
	~GiveGift(){}
	virtual void giveFlowers() = 0;//送花
	virtual void giveChocolate() = 0;//送巧克力
	virtual void giveDolls() = 0;//送洋娃娃
};

class Presuit : public GiveGift//追求者
{
public:
	Presuit(Girl *g)
	{
		mGirl = g;
	}
	~Presuit()
	{
		SALF_DELETE(mGirl);
	}
	void giveDolls()
	{
		cout<<mGirl->getName()<<"送你洋娃娃"<<endl;
	}
	void giveChocolate()
	{
		cout<<mGirl->getName()<<"送你巧克力"<<endl;
	}

	void giveFlowers()
	{
		cout<<mGirl->getName()<<"送你鲜花"<<endl;
	}
private:
	Girl *mGirl;	
};

class Proxy : public GiveGift
{
public:
	Proxy(Girl *g)
	{
		mPre = new Presuit(g);
	}
	~Proxy()
	{
		SALF_DELETE(mPre);
	}

	void giveFlowers()
	{
		mPre->giveFlowers();
	}

	void giveDolls()
	{
		mPre->giveDolls();
	}

	void giveChocolate()
	{
		mPre->giveChocolate();
	}
private:
	Presuit *mPre;
	
};

int main(int argc, char const *argv[])
{
	cout<<"proxy"<<endl;
	Proxy *mPro = new Proxy(new Girl("娇娇"));
	mPro->giveDolls();
	mPro->giveChocolate();
	mPro->giveFlowers();
	SALF_DELETE(mPro);
	return 0;
}