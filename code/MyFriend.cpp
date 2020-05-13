#include <iostream>
using namespace std;

class CCar
{
private:
    int price;
    friend class CDriver;  //声明 CDriver 为友元类
};

class CMinCar:public CCar
{
private:
	int num;
};

class CDriver
{
public:
    virtual void ModifyCar(CCar myCar) 
    {
        myCar.price += 1000;  //ok
    }
    virtual void ModifyCar(CMinCar myMinCar)
    {
        myMinCar.num += 1;//error
    }
};

class CDriver2:public CDriver
{
public:
    virtual void ModifyCar(CCar myCar) 
    {
        myCar.price += 1000;  //error
    }
    virtual void ModifyCar(CMinCar myMinCar)
    {
        myMinCar.num += 1;//error
    }
};

int main()
{
    return 0;
}