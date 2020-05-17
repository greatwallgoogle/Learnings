#include <iostream>
#include <complex>
#include <string>

using namespace std;
//http://c.biancheng.net/view/703.html
//complex 代表复数，例如 2 + 3i
// 使用： complex<int> a{2,3};

class A
{
public:
    A():id(0)
    {
        cout<<"A::A()"<<endl;
    }
    A(int i):id(i)
    {
        cout<<"A::A() id:"<<id<<endl;
    }
    ~A()
    {
        cout<<"~A::A()"<<endl;
    }

private:
    int id;
};

void MemTest()
{
    //1. malloc/free
    void* p1 = malloc(512);//512 bytes
    free(p1);

    //2. new/delete
    std::complex<int>* p2 = new std::complex<int>();
    delete p2;

    //3. ::operator new/::operator delete
    void* p3 = ::operator new(512);//512 bytes
    ::operator delete (p3);//注意这个括号，丢失报错

    //4. 分配器
    int* p4 = std::allocator<int>().allocate(7);//7 ints
    std::allocator<int>().deallocate(p4,7);
}

void TestConstruct()
{
    string* ptr = new string();
    cout<<"test string:"<<*ptr<<endl;
    //! ptr->string::string("hellos"); //error: no member named 'string' in 'std::__1::basic_string<char>'

    //ptr->~string();//ok

    delete ptr;

    printf("===========\n");
    A* a = new A(2);
    //!a->A::A(10);// cannot refer to type member 'A' in 'A' with '->'
    //a->~A(); //ok
    delete a;

    printf("=========array new/delete \n");
    A* ptr2 = new A[3];//执行3次类A的构造函数
    //...
    // for(int i = 0;i < 3;i++)
    // {
    //     new(ptr2++) A(i);
    //     printf("-------i :%d\n",i);
    // }
    delete[] ptr2;//执行3次析构函数
}

void ArrSize()
{
    int arr1[10];
    cout<<"sizeif(arr1) = "<<sizeof(arr1)<<endl;//40

    int* arr2 = new int[10];
    cout<<"sizeif(arr2) = "<<sizeof(arr2)<<endl;//8
    delete[] arr2;
}

int main()
{
    MemTest();
    TestConstruct();


    cout<<"======complex======="<<endl;
    std::complex<int> a(2,3);
    std::cout<<a<<std::endl;
    a = a + 2;
    std::cout<<a<<std::endl;
    return 0;
}