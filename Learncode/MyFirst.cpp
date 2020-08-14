#include <iostream>
using namespace std;

class X
{ 
public:
    static int chunkSize;
};


class Y : public virtual X{ 
public:
    static int chunkSize;
};
class Z : public virtual X{ };
class A : public Y, public Z { };

int X::chunkSize = 5;
int Y::chunkSize = 15;

// class Concrete1
// {
// private:
//     float val;
//     char c1;
// };

// class Concrete2:public Concrete1
// {
// private:
//     char c2;
// };

// class Concrete3:public Concrete2
// {
// private:
//     char c3;
// };
// class Concrete4:public Concrete3
// {
// private:
//     char c4;
//     char c5;
// };

// class Point2d
// {
// public:
// 	Point2d(float nX = 0,float nY = 0):_x(nX),_y(nY){}
// 	float getX(){return _x;}
// 	void  setX(float nT){_x = nT;}
// 	float getY(){return _y;}
// 	void  setY(float nY){_y = nY;}
//     // virtual void setZ(float nZ){}
//     // virtual float getZ(){return 0;}
// protected:
// 	float _x;
// 	float _y;
// };

// class Point3d : public Point2d
// {
// public:
// 	Point3d(float nX = 0,float nY = 0,float nZ = 0)
// 		:Point2d(nX,nY),_z(nZ){ }
// 	float getZ(){return _z;}
// 	void  setZ(float nZ){_z = nZ;}
// protected:
// 	float _z;
// };

// class Vertex
// {
// public:
//     //有虚函数，所以Vertex对象有vptr
// protected:
//     Vertex* next;
// };

// class Vertex3d:public Point3d, public Vertex
// {
// public:
//     //...
// protected:
//     float mumble;
// };

// class Temp1
// {
// public:
//     virtual ~Temp1(){}
// public:
//     float x,y,z;
// };

class Point3d
{
public:
    Point3d normalize() const;
    float   magnitude() const;
private:
    float x;
    float y;
    float z;
};

Point3d Point3d::normalize() const
{
    Point3d res;
    float length = magnitude();
    res.x = x/length;
    res.y = y/length;
    res.z = z/length;
    
    return res;
}

float Point3d::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}

int main()
{
    // printf("X:%ld Y:%ld Z:%ld A:%ld \n",sizeof(X),sizeof(Y),sizeof(Z),sizeof(A));
    // X a,b;
    // if(&a == &b) 
    //     printf("ok \n");
    // else
    //     printf("no \n");

    // X::chunkSize = 10;
    // printf("X::chunkSize:%d   Y::chunkSize:%d  \n",X::chunkSize,Y::chunkSize);


    // printf("Concrete1: %ld Concrete2: %ld Concrete3:%ld Concrete4:%ld \n",sizeof(Concrete1),
    //         sizeof(Concrete2),sizeof(Concrete3),sizeof(Concrete4));
    
    // printf("Point2d: %ld Point3d: %ld\n",sizeof(Point2d),
    //         sizeof(Point3d));

    // printf("&Temp1::x = %p\n", &Temp1::x);
    // printf("&Temp1::y = %p\n", &Temp1::y);
    // printf("&Temp1::z = %p\n",  &Temp1::z);

    Point3d obj;
    Point3d* ptr;
    obj.normalize();
    ptr->normalize();
    printf("res: %f",obj.magnitude());
    printf("hello world \n");
    return 0;
}
