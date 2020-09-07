#include <iostream>
#include <stack>
#include <queue>

/*
判断两个数是否完全相等：如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(NULL == p && NULL == q)
    {
        return true;
    }

    if(p->val == q->val)
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right ,q->right);
    }
    return false;
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
    // bool falg = isSameTree(pRoot);
    // printf("falg:%d",falg);

    return 0;
}