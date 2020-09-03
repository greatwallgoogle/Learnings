#include <iostream>
#include <cstddef>
using namespace std;

//https://www.cnblogs.com/weiym/archive/2013/02/08/2909387.html
class Screen
{
public:
    // Screen():m_nData(0),m_pNext(NULL){}
    // ~Screen(){}
    // void* operator new(size_t size)
    // {
    //     Screen* pRes = nullptr;
    //     if(nullptr == pFreeStore)
    //     {
    //         size_t chunk = size * BLOCK_SIZE;
    //         pFreeStore = reinterpret_cast<Screen*>(new char[chunk]);
    //         Screen* pCur = pFreeStore;
    //         for (int i = 0; i < BLOCK_SIZE; i++)
    //         {
    //             Screen* pNext = pCur + 1;
    //             pCur->m_pNext = pNext;
    //             pCur = pNext;
    //         }
    //         pCur->m_pNext = nullptr;
    //     }
    //     pRes = pFreeStore;
    //     pFreeStore = pFreeStore->m_pNext;
    //     return pRes;
    // }
    // void operator delete(void* ptr)
    // {
    //     if(ptr)
    //     {
    //         Screen* pCur = reinterpret_cast<Screen*>(ptr);
    //         pCur->m_pNext = pFreeStore;
    //         pFreeStore = pCur;
    //     }
    // }
private:
    // int m_nData;
    // Screen* m_pNext;
    // static const int BLOCK_SIZE ;
    // static Screen* pFreeStore;
};

// const int Screen::BLOCK_SIZE = 24;
// Screen* Screen::pFreeStore = NULL;



int main()
{
    printf("size:%ld \n",sizeof(Screen));
    const int static SIZE = 100;
    const int static PRINT_NUM = 20;
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