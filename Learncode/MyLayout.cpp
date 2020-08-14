#include <iostream>


class Base {
public:
	void f();
	virtual void g();
	virtual void h();
private:
	int a;
	int b;
};
 
class Derived : virtual public Base {
public:
	virtual void g();
    virtual void hDerived();
private:
	int c;
	int d;
};

int main()
{
    printf("%ld \n",sizeof(Derived));   
    return 0;
}