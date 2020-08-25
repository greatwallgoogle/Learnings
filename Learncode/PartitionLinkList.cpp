#include <iostream>
using namespace std;

/*
* 题目：给定一个值，将链表中小于和大于等于此值得节点划分到链表两侧。
* Input: head = 1->4->3->2->5->2, x = 3
* Output: 1->2->2->4->3->5
* 
* 思路：
*/

struct LinkNode
{
    int nData;
    LinkNode* pNext;
    LinkNode(int val):nData(val),pNext(NULL){}
};

LinkNode* PartitionLinkList(LinkNode* head,int nVal)
{
    if (NULL == head)
    {
        return NULL;
    }
    
    return head;
}

int main()
{
    LinkNode* pANode1 = new LinkNode(1);
    LinkNode* pANode2 = new LinkNode(6);
    pANode1->pNext = pANode2;

    LinkNode* pCNode1 = new LinkNode(8);
    LinkNode* pCNode2 = new LinkNode(2);
    LinkNode* pCNode3 = new LinkNode(5);
    LinkNode* pCNode4 = new LinkNode(2);
    pCNode1->pNext = pCNode2;
    pCNode2->pNext = pCNode3 ;
    pCNode3->pNext = pCNode4;

    pANode2->pNext = pCNode1;

    LinkNode* pRes = PartitionLinkList(pANode1,4);
    while (NULL != pRes)
    {
        printf("%d \t",pRes->nData );
       pRes = pRes->pNext;
    }
    
    return 0;
}