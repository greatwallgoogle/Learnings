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

	// ������ǰ��ݹ����
	void		PreNodeRecursive(TreeNode* pRoot,vector<int>& res);
	// ����������ݹ����
	void        MidNodeRecursive(TreeNode* pRoot, vector<int>& res);
	//�����������ݹ����
	void        EndNodeRecursive(TreeNode* pRoot, vector<int>& res);
	//��������α���
	void		LevelNodeTrave(TreeNode* pRoot, vector<int>& res);
	//����ǰ�������������ؽ�������
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
	//�����㷨
	void		BubbleSort(vector<int>& vals);
};

