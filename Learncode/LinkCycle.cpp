#include <iostream>
using namespace std;

/*
* 题目：判断链表是否有环
* 思路：利用快慢指针思想，慢指针每次前进一位，快指针每次前进两位，当快指针地址等于慢指针地址时，表示两个指针相遇，即链表有环；
*/

struct ListNode
{
    int nData;
    ListNode* pNext;
    ListNode(int val):nData(val),pNext(NULL){}
};

bool HasCycle(ListNode* pNode)
{
    ListNode* pSlowNode = pNode;
    ListNode* pFastNode = pNode;
    while (NULL != pSlowNode && NULL != pFastNode && NULL != pFastNode->pNext)
    {
        pSlowNode = pSlowNode->pNext;
        pFastNode = pFastNode->pNext->pNext;
        if (pSlowNode == pFastNode)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    pNode1->pNext = pNode2;
    pNode2->pNext = pNode3;
    pNode3->pNext = pNode4;
    pNode4->pNext = pNode5;
    pNode5->pNext = pNode1;

    bool bHasCycle = HasCycle(pNode1);
    cout <<"hello world "<<bHasCycle<<endl;
    return 0;
}