#pragma once

namespace LinkNode
{
	struct SingleNode
	{
		int nData;
		SingleNode *pNextNode;
		SingleNode(int ndata = 0) : nData(ndata), pNextNode(nullptr) {}
	};

	//µ¥Á´±íÄæÐò
	SingleNode *ReverseList(SingleNode *pHead)
	{
		if (nullptr == pHead)
			return nullptr;

		SingleNode* pPreNode = nullptr;
		while (nullptr != pHead)
		{
			SingleNode* pTemp = pHead->pNextNode;
			pHead->pNextNode = pPreNode;
			pPreNode = pHead;
			pHead = pTemp;
		}
		return pPreNode;
	}


	//////////////////////////////////////////////////////////////////////////
	struct LinkedNode
	{
		int nData;
		LinkedNode *pPreNode;
		LinkedNode *pNextNode;
		LinkedNode(int data = 0) : nData(data), pPreNode(nullptr), pNextNode(nullptr) {}
	};

	//Ë«ÏòÁ´±íÄæÐò
	LinkedNode *ReverseList(LinkedNode *pHead)
	{
		if (nullptr == pHead)
		{
			return nullptr;
		}
		LinkedNode* pPreNode = nullptr;
		while (nullptr != pHead)
		{
			LinkedNode* pTemp = pHead->pNextNode;
			pHead->pNextNode = pPreNode;
			pHead->pPreNode = pTemp;
			pPreNode = pHead;
			pHead = pTemp;
		}
		return pPreNode;
	}

}