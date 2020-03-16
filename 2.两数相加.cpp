/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    4039
 * Dislikes: 0
 * Total Accepted:    356.8K
 * Total Submissions: 967.2K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* head = NULL;
        int nextVal = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                sum +=l2->val;
                l2 = l2->next;
            }

            sum += nextVal;
            ListNode* curNode = new ListNode(sum % 10);
            nextVal = sum / 10;
            if(res == NULL)
                head = curNode;
            else
                res->next = curNode;

            res = curNode;
        }

        if(nextVal != 0 && res != NULL)
        {
            res->next = new ListNode(nextVal);
        }
        return head;
    }
};
// @lc code=end

