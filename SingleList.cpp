#include <iostream>
struct SingleListNode
{
    int             nVal;
    SingleListNode* pNext;
    SingleListNode():pNext(NULL){}
    SingleListNode(int nTempValue):nVal(nTempValue),pNext(NULL){}
};

class SingleList
{
public:
    SingleList():m_pHead(NULL),m_nSize(0){}
    ~SingleList(){}
public:
    SingleListNode* Find(int nIndex);
    void            Insert(int nIndex,SingleListNode* pNode);
    SingleListNode* Remove(int nIndex);
    void            PrintList();
private:
    SingleListNode* m_pHead;
    int             m_nSize;
};

SingleListNode* SingleList::Find(int nIndex)
{
    if(nIndex < 0 || nIndex >= m_nSize)
    {
        printf("SingleList::Find:failed! the index is out of range. index is %d \n",nIndex);
        return NULL;
    }

    if(NULL == m_pHead)
    {
        printf("SingleList::Find:failed! the head node is null. \n");
        return NULL;
    }
    
    SingleListNode* pRet = m_pHead;
    for(int i = 0;i < nIndex;i++)
    {
        if(pRet)
        {
            pRet = pRet->pNext;
        }
    }
    return pRet;
}

void SingleList::Insert(int nIndex,SingleListNode* pNode)
{
    if(NULL == pNode)
    {
        printf("SingleList::Insert:failed! the pNode is null.\n ");
        return;
    }

    if(nIndex < 0 || nIndex > m_nSize)
    {
        printf("SingleList::Insert:failed! the index is out of range, size is %d .\n ",m_nSize);
        return;
    }

    if(nIndex == 0)
    {
        //first
        pNode->pNext = m_pHead;
        m_pHead = pNode;
    }
    else
    {
        SingleListNode* pPre = Find(nIndex - 1);
        if(pPre == NULL)
        {
            printf("SingleList::Insert:failed! the pPre node is null.\n ");
            return;
        }

        pNode->pNext = pPre->pNext;
        pPre->pNext = pNode;
    }
    m_nSize++;
}

SingleListNode* SingleList::Remove(int nIndex)
{
    SingleListNode* pRet = NULL;
    if(nIndex < 0 || nIndex >= m_nSize)
    {
        printf("SingleList::Remove:failed! the index is out of range, size is %d .\n ",m_nSize);
        return pRet;
    }

    if(NULL == m_pHead)
    {
        printf("SingleList::Remove:failed! the head node is null. \n");
        return NULL;
    }

    if(nIndex == 0)
    {
        pRet = m_pHead;
        m_pHead = m_pHead->pNext;
    }
    else
    {
        SingleListNode* pPreNode = Find(nIndex - 1);
        if(pPreNode == NULL)
        {
            printf("SingleList::Remove:failed! the pPre node is null.\n ");
            return pRet;
        }

        pRet = pPreNode->pNext;
        if(pRet)
        {
            pPreNode->pNext = pRet->pNext;
            m_nSize--;
        }
    }
    
    return pRet;
}

void SingleList::PrintList()
{
    if(NULL == m_pHead)
        return;

    int nNum = 0;
    SingleListNode* pNode = m_pHead;
    while(pNode)
    {
        printf("index = %d value >> %d \n",nNum,pNode->nVal);
        pNode = pNode->pNext;
        nNum++;
    }
}

int main()
{
    printf(">>>>>>> Hello! >>>>>>>\n");
    SingleList* pLinkList = new SingleList();
    SingleListNode* pNode1 = new SingleListNode(10);
    SingleListNode* pNode2 = new SingleListNode(5);
    SingleListNode* pNode3 = new SingleListNode(8);
    pLinkList->Insert(0,pNode1);
    pLinkList->Insert(1,pNode2);
    pLinkList->Insert(0,pNode3);
    pLinkList->PrintList();

    printf("<<<<<<<< delete >>>>>>>>>\n");
    pLinkList->Remove(2);
    pLinkList->Remove(0);
    pLinkList->Remove(0);
    pLinkList->PrintList();


    delete pNode3;
    delete pNode2;
    delete pNode1;
    delete pLinkList;

    return 0;
}