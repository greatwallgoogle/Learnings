#pragma once
#include <vector>
#include <stack>
using namespace std;

namespace AlgoUtil
{
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) :
			val(x), next(nullptr)
		{
		}
	};

	struct TreeNode
	{
		int val;
		TreeNode * pLeft;
		TreeNode * pRight;
		TreeNode(int x) :
			val(x), pLeft(nullptr), pRight(nullptr)
		{
		}
	};

	void replaceSpace(char* str,int length);
	vector<int> InvertList(ListNode* head);

	// 二叉树前序递归遍历
	void		PreNodeRecursive(TreeNode* pRoot,vector<int>& res);
	// 二叉树中序递归遍历
	void        MidNodeRecursive(TreeNode* pRoot, vector<int>& res);
	//二叉树后续递归遍历
	void        EndNodeRecursive(TreeNode* pRoot, vector<int>& res);
	//二叉树层次遍历
	void		LevelNodeTrave(TreeNode* pRoot, vector<int>& res);
	//根据前序和中序遍历，重建二叉树
	TreeNode*   ReCreateTree(const vector<int>& pre,const vector<int>& in);

	TreeNode*   ReCreateTreeImpl(const vector<int>& pre, const vector<int>& in,int preStart,int preEnd,int inStart,int inEnd);
	ListNode*	FindKthToTail(ListNode* pListHead, unsigned int k);
	class MyQueue
	{
	public:
		void push(int value);

		void printT();

		int pop();
	private:
		stack<int> stack1;
		stack<int> stack2;
	};

	//https://www.cnblogs.com/onepixel/articles/7674659.html
	//排序算法
	void		BubbleSort(vector<int>& vals);
};

