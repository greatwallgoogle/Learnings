#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//获取树的深度
int GetDepth(TreeNode* pNode)
{
    if(NULL == pNode)
    {
        return 0;
    }
    int nLeft = GetDepth(pNode->left);
    int nRight = GetDepth(pNode->right);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//非递归，层次遍历
int GetDepth2(TreeNode* pNode)
{
    if(NULL == pNode)
    {
        return 0;
    }
    queue<TreeNode*> nodes;
    nodes.push(pNode);
    int nRes = 0;
    while (!nodes.empty())
    {
        int size = nodes.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode* pCurNode = nodes.front();
            nodes.pop();
            if(pCurNode->left)
            {
                nodes.push(pCurNode->left);
            }
            if(pCurNode->right)
            {
                nodes.push(pCurNode->right);
            }
        }
        nRes++;
    }
    return nRes;
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

    int depth = GetDepth2(pRoot);
    printf("depth:%d",depth);

    return 0;
}