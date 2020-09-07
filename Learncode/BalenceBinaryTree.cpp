#include <iostream>
#include <stack>
#include <queue>

/*
判断是否是平衡二叉树！
平衡二叉树：如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/

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

bool isBalanced(TreeNode* root) 
{
    if(NULL == root)
    {
        return true;
    }
    int depth1 = GetDepth(root->left);
    int depth2 = GetDepth(root->right);
    if((depth1 - depth2) > 1 || (depth2 - depth1) > 1)
    {
        return false;
    }
    if(!isBalanced(root->left))
    {
        return false;
    }

    if(!isBalanced(root->right))
    {
        return false;
    }

    return true;
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
    bool falg = isBalanced(pRoot);
    printf("falg:%d",falg);

    return 0;
}