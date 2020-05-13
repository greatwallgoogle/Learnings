#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    A(int val){value = val;}
  //  A(A other){ value = other.value; } //error
    void Print()
    {
        std::cout<<"A::Print:"<<value<<std::endl;
    }
private:
    int value;
};

class MyString
{
public:
    MyString(char* pData = NULL)
    :m_pData(pData)
    {

    }
    MyString(const MyString& rh)
    {
        std::cout<<"copy construct"<<std::endl;
    }
    ~MyString()
    {

    }
    MyString& operator= (const MyString& rf)
    {
        std::cout<<"operator="<<std::endl;
        // if(this == &rf)
        // {
        //     return *this;
        // }

        // delete[] m_pData;
        // m_pData = NULL;
        // m_pData = new char[strlen(rf.m_pData) + 1];
        // strcpy(m_pData,rf.m_pData);

        if(this != &rf)
        {
            MyString temp(rf);
            char* pTemp = temp.m_pData;
            temp.m_pData = m_pData;
            m_pData = pTemp;
        }
        return *this;
    }
private:
    char* m_pData;
};

int main()
{
    A a = 10;
    a.Print();
    
    MyString c1;
    //MyString c2 = c1;//拷贝构造
    //MyString c3(c1);//拷贝构造
    MyString c4;
    c4 = c1;

    return 0;
}