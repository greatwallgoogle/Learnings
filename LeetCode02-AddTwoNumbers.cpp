/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

链接：https://leetcode-cn.com/problems/add-two-numbers
*/

/**
 * Definition for singly-linked list.
  */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pResult = NULL;
        ListNode* pHead = NULL;

        ListNode* pL1 = l1;
        ListNode* pL2 = l2;

        int nNext = 0;
        
        while(pL1 != NULL || pL2 != NULL)
        {
            int val1 = pL1 ? pL1->val : 0;
            int val2 = pL2 ? pL2->val : 0;
            int temp = val1 + val2 + nNext;
            nNext =  temp / 10;
            ListNode* pTempNode = new ListNode(temp % 10);
            if(pResult == NULL)
            {
                pResult = pTempNode;
            }
            else
            {
                pHead->next = pTempNode;
            }
            pHead = pTempNode;
            
            pL1 = pL1 ? pL1->next : NULL;
            pL2 = pL2 ? pL2->next : NULL;
        }

        if(nNext > 0)
        {
            pHead->next = new ListNode(nNext);
        }
        return pResult;
    }
};

int main()
{
    ListNode* pL1 = new ListNode(5);
    // ListNode* pL2 = new ListNode(4);
    // ListNode* pL3 = new ListNode(3);
    // pL1->next = pL2;
    // pL2->next = pL3;

    ListNode* pR1 = new ListNode(5);
    // ListNode* pR2 = new ListNode(6);
    // ListNode* pR3 = new ListNode(4);
    // pR1->next = pR2;
    // pR2->next = pR3;

    Solution s;
    ListNode* pCurNode = s.addTwoNumbers(pL1,pR1);
    while(pCurNode)
    {
        printf("%d ",pCurNode->val);
        pCurNode = pCurNode->next;
    }

    return 0;
}