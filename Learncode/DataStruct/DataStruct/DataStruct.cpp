// DataStruct.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "MyArray1.h"
#include "Find.h"
#include <vector>
#include "AlgoUtil.h"
#include <stack>
#include "ReverseList.h"
#include "Alloctor1.h"
#include "Alloctor2.h"
#include "Alloctor3.h"
using namespace LinkNode;

using namespace AlgoUtil;

void TestArray()
{
	//查询或访问
	int aValue[5] = { 1, 5, 6, 10, 23 };
	printf("index = 0,value = %d \n", aValue[0]);

	//修改
	aValue[0] = 100;
	printf("aValue[0] = %d \n", aValue[0]);

	MyArray1 myArray(5);
	myArray.Insert(0, 10);
	myArray.Insert(1, 20);
	myArray.Insert(2, 30);
	myArray.Insert(3, 40);
	myArray.Insert(4, 50);
	myArray.Insert(5, 60);
	myArray.Insert(6, 70);
	myArray.Print();

	printf("\n\n remove --------\n");
	myArray.Remove(6);
	myArray.Remove(5);
	myArray.Remove(4);
	myArray.Remove(3);
	myArray.Remove(2);
	myArray.Remove(1);
	myArray.Remove(0);
	
	
	
	myArray.Print();
}

void findTest()
{
	vector<int> aValues;
	aValues.push_back(1);
	aValues.push_back(150);
	aValues.push_back(260);
	aValues.push_back(330);
	aValues.push_back(470);
	aValues.push_back(500);

	int nTarget = 500;
	//int nIndex = FindUtil::BinaryFindRecursive(aValues, nTarget);
	int nIndex = FindUtil::BinaryFind(aValues, nTarget);
	printf("res:%d \n", nIndex);
}

void test1()
{
// 	string str = "We Are Happy";
// 	str.c_str();
// 	char* sz = "We Are Happy";
// 	AlgoUtil::replaceSpace(sz, 12);
// 	printf("sz:%s \n", sz);

	//////////////////////////////////////////////////////////////////////////
	AlgoUtil::ListNode* node1 = new AlgoUtil::ListNode(5);
	AlgoUtil::ListNode* node2 = new AlgoUtil::ListNode(6);
	AlgoUtil::ListNode* node3 = new AlgoUtil::ListNode(7);
	AlgoUtil::ListNode* node4 = new AlgoUtil::ListNode(8);
	AlgoUtil::ListNode* node5 = new AlgoUtil::ListNode(9);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	ListNode* pTest = AlgoUtil::FindKthToTail(node1, 5);
	if (pTest)
	{
		printf("%d ", pTest->val);
	}
	
	//AlgoUtil::InvertList(node1);
	delete node5;
	delete node4;
	delete node3;
	delete node2;
	delete node1;
	//////////////////////////////////////////////////////////////////////////

// 	TreeNode* pNode1 = new TreeNode(1);
// 	TreeNode* pNode2 = new TreeNode(2);
// 	TreeNode* pNode3 = new TreeNode(3);
// 	pNode1->pLeft = pNode2;
// 	pNode1->pRight = pNode3;
// 
// 	TreeNode* pNode4 = new TreeNode(4);
// 	pNode2->pRight = pNode4;
// 
// 	TreeNode* pNode5 = new TreeNode(5);
// 	pNode3->pRight = pNode5;
//
// 	vector<int> res;
// 	AlgoUtil::PreNodeRecursive(pNode1, res);
// 	for (int i = 0; i < res.size();i++)
// 	{
// 		printf("%d ", res[i]);
// 	}
// 
// 	printf("\n");
// 	res.clear();
// 	AlgoUtil::MidNodeRecursive(pNode1, res);
// 	for (int i = 0; i < res.size(); i++)
// 	{
// 		printf("%d ", res[i]);
// 	}
// 
// 	printf("\n");
// 	res.clear();
// 	AlgoUtil::EndNodeRecursive(pNode1, res);
// 	for (int i = 0; i < res.size(); i++)
// 	{
// 		printf("%d ", res[i]);
// 	}
// 
// 	printf("\n");
// 	res.clear();
// 	AlgoUtil::LevelNodeTrave(pNode1, res);
// 	for (int i = 0; i < res.size(); i++)
// 	{
// 		printf("%d ", res[i]);
// 	}
// 
// 	delete pNode1;
// 	delete pNode2;
// 	delete pNode3;
// 	delete pNode4;
// 	delete pNode5;

	//////////////////////////////////////////////////////////////////////////
// 	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
// 	vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };
// 	TreeNode* root = AlgoUtil::ReCreateTree(pre, in);
// 	
// 	vector<int> res;
// 
// 	AlgoUtil::LevelNodeTrave(root, res);
// 	for (int i = 0; i < res.size(); i++)
// 	{
// 		printf("%d ", res[i]);
// 	}
// 	delete root;
	//////////////////////////////////////////////////////////////////////////

// 	MyQueue que;
// 	que.push(1);
//  	que.push(2);
// 	que.push(3);
// 	//que.printT();
//  	int res = que.pop();
//  	printf("res: %d\n", res);
// 	res = que.pop();
// 	printf("res: %d\n", res);
// 	que.push(4);
// 	res = que.pop();
// 	printf("res: %d\n", res);
// 	que.push(5);
// 	res = que.pop();
// 	printf("res: %d\n", res);
// 	res = que.pop();
// 	printf("res: %d\n", res);
}

void testSort()
{
	vector<int> aValues;
	aValues.push_back(10);
	aValues.push_back(5);
	aValues.push_back(8);
	aValues.push_back(1);
	aValues.push_back(3);
	aValues.push_back(24);
	AlgoUtil::BubbleSort(aValues);
	printf("Bubble sort starting:\n");
	for (int i = 0; i < aValues.size();i++)
	{
		printf("%d ",aValues[i]);
	}
	printf("\nBubble sort ending !\n");
}

void InverseSingleNode()
{
	SingleNode* pNode1 = new SingleNode(1);
	SingleNode* pNode2 = new SingleNode(2);
	SingleNode* pNode3 = new SingleNode(3);
	pNode1->pNextNode = pNode2;
	pNode2->pNextNode = pNode3;

	SingleNode* pNode = ReverseList(pNode1);
	while (NULL != pNode)
	{
		printf("data:%d\n ", pNode->nData);
		pNode = pNode->pNextNode;
	}

	delete pNode3;
	delete pNode2;
	delete pNode1;
}

void InverseLinkNode()
{
	LinkedNode* pNode1 = new LinkedNode(1);
	LinkedNode* pNode2 = new LinkedNode(2);
	LinkedNode* pNode3 = new LinkedNode(3);
	pNode1->pNextNode = pNode2;
	pNode2->pPreNode = pNode1;
	pNode2->pNextNode = pNode3;
	pNode3->pPreNode = pNode2;

	{
		printf("origin:");
		LinkedNode* pNode = pNode1;
		while (NULL != pNode)
		{
			printf("%d ", pNode->nData);
			pNode = pNode->pNextNode;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	printf("\n new:");
	LinkedNode* pNode = ReverseList(pNode1);
	while (NULL != pNode)
	{
		printf("%d ", pNode->nData);
		pNode = pNode->pNextNode;
	}

	printf("\n");
	delete pNode3;
	delete pNode2;
	delete pNode1;
}



int main(int argc, char* argv[])
{
// 	TestArray();
// 	printf("hello world !\n");
// 	InverseLinkNode();
// 	Alloctor1::TestAlloc();
//	Alloctor2::TestAlloc();
	Alloctor3::TestAlloc();
	system("pause");
	return 0;
}

