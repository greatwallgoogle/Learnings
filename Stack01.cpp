#include <iostream>
#include <assert.h>

// 基于数组实现的栈(模板类)
template <class T>
class ArrayStack
{
public :
    ArrayStack(int nCapcity = 8);
    ~ArrayStack();

    bool Push(const T& ele);
    T    Pop();
    T&   GetPop();
    int  GetNum();

private:
    void Resize();
private:
    T*   m_pElement;
    int  m_nCapicity;
    int  m_nNum;
};

template<class T>
ArrayStack<T>::ArrayStack(int nCapcity)
    :m_nCapicity(nCapcity)
    ,m_pElement(new T[nCapcity])
    ,m_nNum(0)
{

}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    delete[] m_pElement;
}

template<class T>
bool ArrayStack<T>::Push(const T& ele)
{
    if(m_pElement == NULL)
    {
        printf(" m_pElement == NUL \n");
        assert(false && "m_pElement == NUL");
        return false;
    }
    if(m_nNum >= m_nCapicity)
    {
        Resize();
    }

    m_pElement[m_nNum] = ele;
    m_nNum++;
    return true;
}

template<class T>
T ArrayStack<T>::Pop()
{
    if(m_nNum <= 0)
    {
        return NULL;
    }

    m_nNum--;
    return m_pElement[m_nNum];
}

template<class T>
T& ArrayStack<T>::GetPop()
{
    if(m_nNum <= 0)
    {
        return NULL;
    }

    return m_pElement[m_nNum - 1];
}

template<class T>
int ArrayStack<T>::GetNum()
{
    return m_nNum;
}

template<class T>
void ArrayStack<T>::Resize()
{
    if(NULL == m_pElement)
    {
        if(m_nCapicity == 0)
        {
            m_nCapicity = 8;
        }
        m_pElement = new T[m_nCapicity];
        return;
    }

    T* pNewEle = new T[m_nCapicity * 2];
    for(int i = 0;i < m_nNum;i++)
    {
        pNewEle[i] = m_pElement[i];
    }

    delete[] m_pElement;
    m_pElement = pNewEle;
    m_nCapicity = m_nCapicity * 2;
}

int main()
{
    printf("Welcome to stack! \n");

    ArrayStack<int> stackVal1(4);
    stackVal1.Push(1);
    stackVal1.Push(10);
    stackVal1.Push(20);
    stackVal1.Push(40);
    stackVal1.Push(60);

    int nNum = stackVal1.GetNum();
    printf("------num:%d \n",nNum);
   
    for(int i = 0;i < nNum;i++)
    {
        int val1 = stackVal1.Pop();
        printf("%d  ",val1);
    }
    printf("\n");

    nNum = stackVal1.GetNum();
    printf("------num:%d \n",nNum);
    return 0;
}
