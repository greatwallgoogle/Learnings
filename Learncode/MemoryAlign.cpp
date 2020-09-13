#include <iostream>
#include <vector>
using namespace std;

//内存对齐

class C1
{
public:
    C1(/* args */){}
    ~C1(){}
};

class C2
{
public:
    C2(/* args */){}
    ~C2(){}

private:
    char s;
    int  val;
    short s2;
};

class C3
{
public:
    C3(/* args */){}
    ~C3(){}
private:
    int val;
    char s;
    short s2;
};

class Data
{
    char c;
    double a;
};

int main()
{
    printf("C1 class size :%ld \n",sizeof(C1));
    printf("C2 class size :%ld \n",sizeof(C2));
    printf("C3 class size :%ld \n",sizeof(C3));
    printf("Data class size :%ld \n",sizeof(Data));
    return 0;
}