#include "AlgoUtil.h"
#include <string>
#include <queue>

using namespace std;

void AlgoUtil::replaceSpace(char* str, int length)
{
	if (nullptr == str)
	{
		return;
	}

}

vector<int> AlgoUtil::InvertList(ListNode* head)
{
	vector<int> res;
	if (NULL == head)
	{
		return res;
	}

	ListNode* pre = NULL;
	while (head && head->next)
	{
		ListNode* next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	if (head)
	{
		head->next = pre;
	}

	while (head)
	{
		res.push_back(head->val);
		printf("%d ", head->val);
		head = head->next;
	}
	return res;
}

void AlgoUtil::PreNodeRecursive(TreeNode* pRoot, vector<int>& res)
{
	if (NULL == pRoot)
	{
		return;
	}

	res.push_back(pRoot->val);
	PreNodeRecursive(pRoot->pLeft, res);
	PreNodeRecursive(pRoot->pRight, res);
}

void AlgoUtil::MidNodeRecursive(TreeNode* pRoot, vector<int>& res)
{
	if (NULL == pRoot)
	{
		return;
	}
	MidNodeRecursive(pRoot->pLeft, res);
	res.push_back(pRoot->val);
	MidNodeRecursive(pRoot->pRight, res);
}

void AlgoUtil::EndNodeRecursive(TreeNode* pRoot, vector<int>& res)
{
	if (NULL == pRoot)
	{
		return;
	}
	EndNodeRecursive(pRoot->pLeft, res);
	EndNodeRecursive(pRoot->pRight, res);
	res.push_back(pRoot->val);
}

void AlgoUtil::LevelNodeTrave(TreeNode* pRoot, vector<int>& res)
{
	if (NULL == pRoot)
	{
		return;
	}
	queue<TreeNode*> nodes;
	nodes.push(pRoot);
	while (!nodes.empty())
	{
		TreeNode* curNode = nodes.front();
		if (curNode != NULL)
		{
			res.push_back(curNode->val);
			nodes.pop();
			if (curNode->pLeft != nullptr)
			{
				nodes.push(curNode->pLeft);
			}
			if (curNode->pRight != nullptr)
			{
				nodes.push(curNode->pRight);
			}
		}		
	}
}

AlgoUtil::TreeNode* AlgoUtil::ReCreateTree(const vector<int>& pre, const vector<int>& in)
{
	return ReCreateTreeImpl(pre, in,0,pre.size() - 1, 0, in.size() - 1);
}

AlgoUtil::TreeNode* AlgoUtil::ReCreateTreeImpl(const vector<int>& pre, const vector<int>& in,
	int startPre, int endPre, int startIn, int endIn)
{
	if (startPre > endPre || startIn > endIn){
		return NULL;
	}
	TreeNode* root = new TreeNode(pre[startPre]);
	for (int i = startIn; i <= endIn;i++)
	{
		if (in[i] == pre[startPre])
		{
			int newStartIndex = startIn;
			int newEndIndex = i - 1;
			int newStartPre = startPre + 1;
			int newEndPre = startPre + (newEndIndex - newStartIndex + 1);
			root->pLeft = ReCreateTreeImpl(pre, in, newStartPre, newEndPre, newStartIndex, newEndIndex);

			newStartIndex = i + 1;
			newEndIndex = endIn;
			newStartPre = newEndPre + 1;
			newEndPre = endPre;
			root->pRight = ReCreateTreeImpl(pre, in, newStartPre, newEndPre, newStartIndex, newEndIndex);
		}
	}
	return root;
}

AlgoUtil::ListNode* AlgoUtil::FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (NULL == pListHead || k <= 0)
	{
		return NULL;
	}
	ListNode* pPre = NULL;
	while (pListHead && pListHead->next)
	{
		ListNode* pNext = pListHead->next;
		pListHead->next = pPre;
		pPre = pListHead;
		pListHead = pNext;
	}

	if (pListHead)
	{
		pListHead->next = pPre;
	}

	ListNode* pRes = pListHead;
	int count = 1;
	while (count < k && pRes)
	{
		pRes = pRes->next;
		k--;
	}
	return pRes;
}

void AlgoUtil::MyQueue::push(int value)
{
	stack1.push(value);
}

void AlgoUtil::MyQueue::printT()
{
	while (stack1.size() > 0)
	{
		int res = stack1.top();
		stack1.pop();
		printf("res:%d ", res);
	}
}

int AlgoUtil::MyQueue::pop()
{
	int res = -10000;
	if (stack1.size() <= 0)
	{
		return res;
	}

	while (stack1.size() > 0)
	{
		res = stack1.top();
		stack1.pop();
		if (stack1.size() > 0)
		{
			stack2.push(res);
		}
	}

	while (stack2.size() > 0)
	{
		int tres = stack2.top();
		stack2.pop();
		stack1.push(tres);
	}
	return res;
}
void AlgoUtil::BubbleSort(vector<int>& vals)
{
	for (int i = 0; i < vals.size();i++)
	{
		for (int j = i + 1; j < (vals.size() - 1); j++)
		{
			if (vals[i] > vals[j])
			{
				int temp = vals[i];
				vals[i] = vals[j];
				vals[j] = temp;
			}
		}
	}
}


// 
// if (pListHead == nullptr || k = 0)
// {
// 	return nullptr;
// }
// 
// ListNode *pAhead = pListHead;
// ListNode *pBehind = nullptr;
// 
// for (unsigned int i = 0; i < k - 1; i++)
// {
// 	if (pAhead->m_pNext != nullptr)
// 		pAhead = pAhead->m_pNext;
// 	else
// 		return nullptr;
// }
// 
// pBehind = pListHead;
// 
// while (pAhead->m_pNext != nullptr)
// {
// 	pAhead = pAhead->m_pNext;
// 	pBehind = pBehind->m_pNext;
// }
// return pBehind;