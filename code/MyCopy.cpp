#include <iostream>
using namespace std;

class Point
{
public:
    Point(float x = 0,float y = 0)
    {
        printf("Point::Point() \n");
        // size();
    }
    virtual ~Point()
    {
        printf("Point::~Point  \n");
    }
    virtual void size(){printf("Point::size \n");}
};

class Point3d : public Point
{
public:
    Point3d(float x = 0,float y = 0,float z = 0)
        :Point(x,y)
    {
        printf("Point3d::Point3d() \n");
        // size();
    }
    ~Point3d()
    {
        printf("Point3d::~Point3d  \n");
    }
    virtual void size(){printf("Point3d::size \n");}
};

int main()
{
    Point* vd = new Point3d();
    delete vd;
    return 0;
}