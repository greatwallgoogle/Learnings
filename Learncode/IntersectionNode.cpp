#include <iostream>
using namespace std;

/*
* 题目：获取两个链表的交点
*  A:        a1 -> a2
*                   \
*                     c1 -> c2 -> c3
*                   /
*  B:  b1 -> b2 -> b3
* 
* 思路：1. 将长链表的头指针前进 abs(N) 步；
*       2. N = size(A) - size(B)
*       3. 当两个链表的当前指针都不为空，且相等时，即为交点
*/

struct LinkNode
{
    int nData;
    LinkNode* pNext;
    LinkNode(int val):nData(val),pNext(NULL){}
};

int GetListSize(LinkNode* pNode)
{
    int nCount = 0;
    while (NULL != pNode)
    {
        nCount++;
        pNode = pNode->pNext;
    }
    return nCount;
}

LinkNode* GetIntersectionNode(LinkNode* pNode1,LinkNode* pNode2)
{
    int nCount1 = GetListSize(pNode1);
    int nCount2 = GetListSize(pNode2);
    int nDiff = nCount1 - nCount2;

    LinkNode* pH1 = pNode1;
    LinkNode* pH2 = pNode2;
    //将长链表前进nDiff位
    for (int i = 0; i < abs(nDiff); i++)
    {
        if(nDiff > 0)
        {
            pH1 = pH1->pNext;
        }
        else
        {
            pH2 = pH2->pNext;
        }
    }

    while (NULL != pH1 && NULL != pH2)
    {
        if(pH1 == pH2)
        {
            return pH1;
        }
        pH1 = pH1->pNext;
        pH2 = pH2->pNext;
    }
    
    return NULL;
}

int main()
{
    LinkNode* pANode1 = new LinkNode(1);
    LinkNode* pANode2 = new LinkNode(2);
    pANode1->pNext = pANode2;


    LinkNode* pBNode1 = new LinkNode(11);
    LinkNode* pBNode2 = new LinkNode(22);
    LinkNode* pBNode3 = new LinkNode(33);
    pBNode1->pNext = pBNode2;
    pBNode2->pNext = pBNode3;

    LinkNode* pCNode1 = new LinkNode(4);
    LinkNode* pCNode2 = new LinkNode(5);
    pCNode1->pNext = pCNode2;

    
    pANode2->pNext = pCNode1;
    pBNode3->pNext = pCNode1;

    LinkNode* pRes = GetIntersectionNode(pANode1,pBNode2);
    if (NULL != pRes)
    {
        cout << pRes->nData <<endl;
    }

    return 0;
}