#include <iostream>
#include <assert.h>

template<class T>
class Node
{
public:
    Node():m_pNext(NULL){}
    Node(T& data):m_Data(data),m_pNext(NULL){}
    Node(T& data,Node<T>* pNext):m_Data(data),m_pNext(pNext){}
public:
    T        m_Data;
    Node<T>* m_pNext;
};

//单链表
template<class T>
class SingleList
{
public:
    SingleList():m_pHead(NULL),m_pCurrent(NULL),m_nSize(0){}
    ~SingleList()
    {
        Clear();
    }

    //获取链表元素个数
    int GetNum()
    {
        return m_nSize;
    }

    //尾部插入新节点
    bool InsertNode(const T& data)
    {
        Node<T>* pNew = new Node<T>();
        pNew->m_Data = data;
        pNew->m_pNext = NULL;
        if(m_pHead == NULL)
        {
            m_pHead = pNew;
            m_pCurrent = pNew;
        }
        else
        {
            m_pCurrent->m_pNext = pNew;
            m_pCurrent = pNew;
        }
        m_nSize++;
        return true;
    }

    //删除节点
    int DeleteNode()
    {
        if(m_nSize == 0 || m_pHead == NULL|| NULL == m_pCurrent)
        {
            return -1;
        }

        if(m_pHead == m_pCurrent)
        {
            m_pHead = m_pCurrent->m_pNext;
            delete m_pCurrent;
            m_pCurrent = m_pHead;
        }
        else
        {
            Node<T>* pCurrent = m_pHead;
            while(pCurrent)
            {
                if(pCurrent->m_pNext == m_pCurrent)
                {
                    pCurrent->m_pNext = m_pCurrent->m_pNext;
                    delete m_pCurrent;
                    m_pCurrent = pCurrent;
                    break;
                }
                else
                {
                    pCurrent = pCurrent->m_pNext;
                }
            }
        }
       
        m_nSize--;
        return m_nSize;
    }

    //获取当前节点数据
    void GetCurrentNodeData(T& data)
    {
        if(m_pCurrent)
        {
           data = m_pCurrent->m_Data ;
        }
    }

    //设置当前节点数据
    void SetCurrentNodeData(T& data)
    {
        if(m_pCurrent)
        {
            m_pCurrent->m_Data = data;
        }
    }

    //清空列表
    void Clear()
    {
        if(m_nSize == 0 || m_pHead == NULL)
        {
            return;
        }

        Node<T>* tepCurrent = m_pHead;
        Node<T>* tepNext = m_pHead->m_pNext;
        
        while(tepCurrent)
        {
            delete tepCurrent;
            tepCurrent = tepNext;
            if(tepNext)
            {
                tepNext = tepNext->m_pNext;
            }
        }
        m_pHead = NULL;
        m_pCurrent = NULL;
        m_nSize = 0;
    }
private:
    Node<T>*        m_pHead;
    Node<T>*        m_pCurrent;
    int             m_nSize;
};

template<class T>
class LinkStack
{
public:
    LinkStack(){}
    ~LinkStack(){}
    //获取元素个数
    int  GetNum()
    {
        return m_SingleList.GetNum();
    }

    //添加新元素
    bool Push(const T& data)
    {
        return m_SingleList.InsertNode(data);
    }

    //移除栈顶元素
    T    Pop()
    {
        T temp;
        if(GetNum() <= 0)
        {
            return -1;
        }
        m_SingleList.GetCurrentNodeData(temp);
        m_SingleList.DeleteNode();
        return temp;
    }
private:
    SingleList<T> m_SingleList;
};

int main()
{
    printf("Welcome to link stack.\n");
    LinkStack<int> stackVal2;
    stackVal2.Push(100);
    stackVal2.Push(200);
    stackVal2.Push(300);
    stackVal2.Push(500);

    int nNum = stackVal2.GetNum();
    for(int i = 0;i < nNum;i++)
    {
        int val = stackVal2.Pop();
        printf("Pop:%d  =================\n",val);
    }
    

    return 0;
}