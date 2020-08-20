#include <iostream>
#include <cstddef>
using namespace std;

//https://www.cnblogs.com/weiym/archive/2013/02/08/2909387.html
class Screen
{
public:
    Screen():m_nData(0),m_pNext(NULL){}
    ~Screen(){}
    static void* operator new(size_t size)
    {
        cout<<"Screen::operator new"<<endl;
        Screen* pRes = NULL;
        size_t chunkSize = Chunk * size;
        if (NULL == pFreeStore)
        {
            //分配一大块内存
            pFreeStore = reinterpret_cast<Screen*>(new char[chunkSize]);
            pRes = pFreeStore;
            
        }

        pRes = pFreeStore;
        pFreeStore = pFreeStore->m_pNext;
        return pRes;
    }
    static void operator delete(void* ptr)
    {
        cout<<"Screen::operator delete"<<endl;
        free(ptr);
    }
private:
    int m_nData;
    Screen* m_pNext;
    static const int Chunk ;
    static Screen* pFreeStore;
};

const int Screen::Chunk = 24;
Screen* Screen::pFreeStore = NULL;



int main()
{
    printf("size:%ld \n",sizeof(Screen));
    const int static SIZE = 1;
    const int static PRINT_NUM = 1;
    Screen* p[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        p[i] = new Screen();
    }

    for (int i = 0; i < PRINT_NUM; i++)
    {
        printf("%p \n",p[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete p[i];
    }
    return 0;
}