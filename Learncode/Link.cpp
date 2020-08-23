#include <iostream>
using namespace std;

/*
* 单链表/双向链表逆序
*/
struct SingleNode
{
    int nData;
    SingleNode *pNextNode;
    SingleNode(int ndata = 0) : nData(ndata), pNextNode(NULL) {}
};

SingleNode *ReverseList(SingleNode *pHead)
{
    if (NULL == pHead)
    {
        return NULL;
    }
    SingleNode *pPreNode = NULL;
    while (NULL != pHead && NULL != pHead->pNextNode)
    {
        SingleNode *pTemp = pHead->pNextNode;
        pHead->pNextNode = pPreNode;
        pPreNode = pHead;
        pHead = pTemp;
    }
    return pHead;
}

//----------------------------------------
struct Node
{
    int nData;
    Node *pPreNode;
    Node *pNextNode;
    Node() : nData(0), pPreNode(NULL), pNextNode(NULL) {}
};

Node *ReverseList(Node *pHead)
{
    if (NULL == pHead)
    {
        return NULL;
    }

    Node* pPreNode = NULL;
    Node* pCurNode = pHead;
    while (NULL != pCurNode)
    {
        Node* pNext = pCurNode->pNextNode;
        pCurNode->pNextNode = pPreNode;
        pCurNode->pPreNode = pNext;
        pPreNode = pCurNode;
        pCurNode = pNext;
    }
    return pPreNode;
}

int main()
{
    //----single
    // SingleNode* pNode1 = new SingleNode(1);
    // SingleNode* pNode2 = new SingleNode(2);
    // SingleNode* pNode3 = new SingleNode(3);
    // pNode1->pNextNode = pNode2;
    // pNode2->pNextNode = pNode3;

    // ReverseList(pNode1);
    // while(NULL != pNode1)
    // {
    //     printf("data:%d \n",pNode1->nData);
    // }

    printf("hello world");
    return 0;
}