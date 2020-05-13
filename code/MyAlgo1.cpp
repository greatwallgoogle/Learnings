#include <iostream>
#include <vector>
using namespace std;

struct LinkNode
{
    int nData;
    LinkNode* pNext;
};

void traverse(LinkNode* pHead)
{
    //迭代访问
    for (LinkNode* current = pHead; current != nullptr; current = current->pNext)
    {
        /* code */
    }

    //递归访问
    traverse(pHead->pNext);
}

struct TreeNode
{
    int nData;
    TreeNode* pLeft;
    TreeNode* pRight;
};

void traverse(TreeNode* pHead)
{
    //递归迭代
    traverse(pHead->pLeft);
    traverse(pHead->pRight);
}

struct NTreeNode
{
    int nData;
    std::vector<NTreeNode*> aChildNodes;
};

void traverse(NTreeNode* pHead)
{
    if(pHead == nullptr) return;
    for (size_t i = 0; i < pHead->aChildNodes.size(); i++)
    {
        /* code */
    }
}

int main()
{
    int arr1[] = {4,3,5,1};
    int num = sizeof(arr1)/sizeof(int);
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr1[i]);
    }


    
    return 0;
}