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

void depthFirstSearch(TreeNode* pRoot)
{
    if(NULL == pRoot)
    {
        return;
    }

    stack<TreeNode*> stack1;
    stack1.push(pRoot);
    while(!stack1.empty())
    {
        TreeNode* pCurNode = stack1.top();
        printf("%d ",pCurNode->val);
        stack1.pop();
        if(pCurNode->right)
        {
            stack1.push(pCurNode->right);
        }
        if(pCurNode->left)
        {
            stack1.push(pCurNode->left);
        }
    }
}

void levelFirstSearch(TreeNode* pRoot)
{
    if(NULL == pRoot)
    {
        return;
    }
    queue<TreeNode*> que;
    que.push(pRoot);
    while(!que.empty())
    {
        TreeNode* pCurNode = que.front();
        printf("%d ",pCurNode->val);
        que.pop();
        
        if(pCurNode->left)
        {
            que.push(pCurNode->left);
        }

        if(pCurNode->right)
        {
            que.push(pCurNode->right);
        }
    }
}

int getDepth(TreeNode* pRoot)
{
    if(NULL == pRoot)
    {
        return 0;
    }
    int left = getDepth(pRoot->left);
    int right = getDepth(pRoot->right);
    if(left > right)
    {
        return (left + 1);
    }
    return (right + 1);
}

int getDepth2(TreeNode* pRoot)
{
    if(NULL == pRoot)
    {
        return 0;
    }

    queue<TreeNode*> que;
    que.push(pRoot);
    int depth = 0;
    while(!que.empty())
    {
        int size = que.size();
        for(int i = 0;i < size;i++)
        {
            TreeNode* pCurNode = que.front();
            que.pop();
            if(pCurNode->left)
            {
                que.push(pCurNode->left);
            }
            if(pCurNode->right)
            {
                que.push(pCurNode->right);
            }
        }
        depth++;
    }
    return depth;
}

TreeNode* lcaDeepestLeaves(TreeNode* root) 
{
    if(NULL == root)
    {
        return NULL;
    }

    int left = getDepth2(root->left);
    int right = getDepth2(root->right);
    if(left == right)
    {
        return root;
    }
    if(left > right)
    {
        return lcaDeepestLeaves(root->left);
    }
    return lcaDeepestLeaves(root->right);
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

    // int depth = getDepth2(pRoot);
    // printf("depth:%d",depth);

    TreeNode* pParentNode = lcaDeepestLeaves(pRoot);
    if(pParentNode)
    {
        printf("val:%d",pParentNode->val);
    }

    return 0;
}