#include <iostream>
using namespace std;

class Point
{
public:
	virtual ~Point(){}
    virtual Point& mult(float factor) = 0;
    float x()const {return _x;}
    virtual float y(){return 0;}
    virtual float z(){return 0;}
protected:
    Point(float x = 0){_x = x;}
    float _x;
};

class Point2d:public Point
{
public:
    Point2d(float x = 0,float y = 0):Point(x),_y(y){}
    ~Point2d(){}

    Point2d& mult(float factor);
    float y() const {return _y;}

protected:
    float _y;
};


class Point3d:public Point2d
{
public:
    Point3d(float x = 0,float y = 0,float z = 0):Point2d(x,y),_z(z){}
    ~Point3d(){}

    Point3d& mult(float factor);
    float z() const {return _z;}

protected:
    float _z;
};


class Base1
{
public:
    Base1(){}
    virtual ~Base1(){printf("Base1::~Base1  \n");}
    virtual void speakClearly(){printf("Base1::speakClearly  \n");}
    void tst(){}
};

// class Base2
// {
// public:
//     Base2();
//     virtual ~Base2();
//     virtual void mumble();
//     virtual Base2* clone()const;
// protected:
//     float data_base2;
// };

class Derived:public Base1
{
public:
    Derived(){}
    virtual ~Derived(){printf("Derived::~Derived  \n");}
    virtual void speakClearly(){printf("Derived::speakClearly  \n");}
};


int main()
{
    void (Base1::*pmf)() = &Base1::speakClearly;
    // Base1 ba;
    // (ba.*pmf)();

    Base1* ptr = new Derived();
    (ptr->*pmf)();
    delete ptr;

    printf("%d \n",&Base1::speakClearly);
    printf("%p \n",&Base1::tst);
    return 0;
}