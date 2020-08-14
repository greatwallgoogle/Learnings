#include <iostream>
#include <string>

class Test1
{
public:
    Test1(){}
    Test1(int tmp,std::string strTmp):m_nLen(tmp),m_strTmp(strTmp){}
    //没有声明复制构造函数
public:
    int m_nLen;
    std::string m_strTmp;
};

class Test2
{
public:
    int nVal;
    Test1 t1;
};

int main()
{
    Test1 t1(5,"hello");
    Test1 t2 = t1;

    //跟下面操作一直
    // t2.m_nLen = t1.m_nLen;
    // t2.m_strTmp = t1.m_strTmp;
    printf("test :%d  %s \n",t2.m_nLen,t2.m_strTmp.c_str());

    Test2 tTVal2;
    tTVal2.nVal = 2;
    tTVal2.t1 = t1;

    Test2 tTVal3 = tTVal2;
    printf("test22 :%d  %s \n",t23.nVal,t23.t1.m_strTmp.c_str());

    return 0;
}