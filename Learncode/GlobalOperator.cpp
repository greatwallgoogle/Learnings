#include <iostream>
#include <cstddef>
using namespace std;

class Foo
{
public:
    Foo():m_nData(0){}
    ~Foo(){}
private:
    int m_nData;
    char m_sChar;
};

//重载全局operator new /operator delete
void* operator new(size_t size)
{
    cout<<"global new"<<endl;
    return malloc(size);
}
void operator delete(void* ptr)
{
    cout<<"global delete"<<endl;
    free(ptr);
}

void* operator new[] (size_t size)
{
    cout<<"global new[]"<<endl;
    return malloc(size);
}

void operator delete[](void* ptr)
{
    cout<<"global delete[]"<<endl;
    free(ptr);
}


int main()
{
    printf("size:%ld \n",sizeof(Foo));
    const int static SIZE = 1;
    const int static PRINT_NUM = 1;
    Foo* p[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        p[i] = new Foo();
    }

    for (int i = 0; i < PRINT_NUM; i++)
    {
        printf("%p \n",p[i]);
    }
    

    for (int i = 0; i < SIZE; i++)
    {
        delete p[i];
    }

    Foo* ptr2 = new Foo[SIZE];
    delete[] ptr2;

    return 0;
}