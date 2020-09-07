#include <iostream>
#include <stack>
#include <queue>

/*
反转二叉树
*/

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//非递归/层次遍历/基于队列
TreeNode* InvertTree(TreeNode* pTree)
{
    if(NULL == pTree)
        return pTree;

    queue<TreeNode*> trees;
    trees.push(pTree);
    while (trees.size() > 0)
    {
        int size = trees.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* pCurNode = trees.front();
            trees.pop();
            TreeNode* pLeft = pCurNode->left;
            pCurNode->left = pCurNode->right;
            pCurNode->right = pLeft;

            if(pCurNode->left)
            {
                trees.push(pCurNode->left);
            }
            if(pCurNode->right)
            {
                trees.push(pCurNode->right);
            }
        }
    }
    return pTree;
}

//递归遍历
TreeNode* InvertTree2(TreeNode* pTree)
{
    if(NULL == pTree)
    {
        return NULL;
    }
    TreeNode* pTemp = pTree->left;
    pTree->left = pTree->right;
    pTree->right = pTemp;
    InvertTree2(pTree->left);
    InvertTree2(pTree->right);
    return pTree;
}

void Traval(TreeNode* pRoot)
{
    if(NULL == pRoot)
    {
        return ;
    }
    queue<TreeNode*> trees;
    trees.push(pRoot);
    while (trees.size() > 0)
    {
        int size = trees.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* pCurNode = trees.front();
            trees.pop();
            printf("%d ",pCurNode->val);
            if(pCurNode->left)
            {
                trees.push(pCurNode->left);
                printf(" (L:%d ",pCurNode->left->val);
            }
            if(pCurNode->right)
            {
                trees.push(pCurNode->right);
                printf(" R:%d )",pCurNode->right->val);
            }
        }
        printf("\n");
    }
}

int main()
{
    TreeNode* pRoot= new TreeNode(3);
    TreeNode* pNode1= new TreeNode(9);
    TreeNode* pNode2= new TreeNode(20);

    pRoot->left = pNode1;
    pRoot->right = pNode2;

    TreeNode* pNode3= new TreeNode(15);
    TreeNode* pNode4= new TreeNode(7);
    
    pNode2->left = pNode3;
    pNode2->right = pNode4;

    TreeNode* pNode5= new TreeNode(8);
    pNode4->left = pNode5;

    printf("origin tree:\n");
    Traval(pRoot);
    printf("\n===================\n");
    InvertTree2(pRoot);
    Traval(pRoot);

    return 0;
}