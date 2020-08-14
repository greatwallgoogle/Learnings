
#include <iostream>
using namespace std;

int (*pFunc)(int val1,int val2);//声明一个指向函数的指针
int getSum(int n1,int n2)
{
    return n1 + n2;
}

typedef int (*FuncCall1)(int n, int m);
int compareNum(int a,int b)
{
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

int funcTemp(int a, int b,int(*Func)(const int a, const int b))
{
    return Func(a,b);
}

int funcTemp2(int a, int b,FuncCall1 fc)
{
    return fc(a,b);
}


class A
{
public:
    void Speak(){
        printf("A::Speak.....\n");
    }
};

int main()
{
//     pFunc = getSum;
//     int res = pFunc(3,5);

//     FuncCall1 cf;
//     cf = compareNum;
//     int res = cf(4,3);

//     int res = funcTemp(4,5,getSum);
//     res = funcTemp2(4,7,getSum);

//     const int* ptr;
//     int const* ptr2;
//     int* const ptr3 = NULL;

//     printf("res:%d \n",res);

    //----------
    void (A::*pFunc1)();
    pFunc1 = &A::Speak;
    A a1;
    (a1.*pFunc1)();


    typedef void (A::*Func2)();
    Func2 ptr2 = &A::Speak;
    A a2;
    (a2.*ptr2)();


    return 0;
}