#include <iostream>
using namespace std;

/*
* 题目：将有序链表中的重复元素全部删除
* Input: 1->2->3->3->4->4->5
* Output: 1->2->5
*
* Input: 1->1->1->2->3
* Output: 2->3
* 
* 思路：
*/

struct LinkNode
{
    int nData;
    LinkNode* pNext;
    LinkNode(int val):nData(val),pNext(NULL){}
};

LinkNode* DeleteDuplicates(LinkNode* head)
{
    if (NULL == head)
    {
        return NULL;
    }

    LinkNode* pCurNode = head;
    while (NULL != pCurNode)
    {
        if(NULL != pCurNode->pNext && pCurNode->nData == pCurNode->pNext->nData)
        {
            LinkNode* pNext = pCurNode->pNext;
            pCurNode->pNext = pNext->pNext;
        }
        else
        {
            pCurNode = pCurNode->pNext;
        }
    }
    return head;
}

int main()
{
    LinkNode* pANode1 = new LinkNode(2);
    LinkNode* pANode2 = new LinkNode(2);
    pANode1->pNext = pANode2;

    LinkNode* pCNode1 = new LinkNode(2);
    LinkNode* pCNode2 = new LinkNode(2);
    LinkNode* pCNode3 = new LinkNode(5);
    pCNode1->pNext = pCNode2;
    pCNode2->pNext =pCNode3 ;

    pANode2->pNext = pCNode1;

    LinkNode* pRes = DeleteDuplicates(pANode1);
    while (NULL != pRes)
    {
        printf("%d \t",pRes->nData );
       pRes = pRes->pNext;
    }
    
    return 0;
}