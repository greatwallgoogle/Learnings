#include <iostream>
#include <stack>
#include <queue>

/*
判断是否是镜像树
*/

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool isSymmetricImpl(TreeNode* leftNode,TreeNode* rightNode)
{
    if(NULL == leftNode && NULL == rightNode)
    {
        return true;
    }
    if(NULL == leftNode || NULL == rightNode)
    {
        return false;
    }

    if(leftNode->val == rightNode->val)
    {
        return isSymmetricImpl(leftNode->left,rightNode->right) && isSymmetricImpl(leftNode->right,rightNode->left);
    }
    return false;
}

bool isSymmetricImpl2(TreeNode* leftNode,TreeNode* rightNode)
{
    queue<TreeNode*> trees;
    trees.push(leftNode);
    trees.push(rightNode);
    while (!trees.empty())
    {
        TreeNode* p1 = trees.front();
        trees.pop();
        TreeNode* p2 = trees.front();
        trees.pop();
        if(p1 == p2 && p2 == NULL)
        {
            continue;
        }

        if(p1 == NULL || p2 == NULL)
        {
            return false;
        }

        if(p1->val != p2->val)
        {
            return false;
        }

        trees.push(p1->left);
        trees.push(p2->right);
        trees.push(p1->right);
        trees.push(p2->left);
    }
    return true;
}

bool isSymmetric(TreeNode* root) 
{
    if(NULL == root)
    {
        return true;
    }

    return isSymmetricImpl2(root,root);
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
    printf("\n=================== %d\n",isSymmetric(pRoot));
    // Traval(pRoot);

    return 0;
}