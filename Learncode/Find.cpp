#include <iostream>
#include <vector>
using namespace std;


int BinaryFindRecurveImpl(const vector<int>& values,int target,int start,int end)
{
    if(start > end)
    {
        return -1;
    }

    int middle = (start + end) / 2;
    if(values[middle] == target)
    {
        return middle;
    }
    else if(values[middle] > target)
    {
        return BinaryFindRecurveImpl(values,target,start,middle - 1);
    }
    return BinaryFindRecurveImpl(values,target,middle + 1,end);
}

int BinaryFindRecurve(const vector<int>& values,int target)
{
    int start = 0;
    int end = values.size() - 1;
    return BinaryFindRecurveImpl(values,target,start,end);
}

int BinaryFind(const vector<int>& values,int target)
{
    int start = 0;
    int end = values.size() - 1;
    while(start <= end)
    {
        int middle = (start + end) / 2;
        if(values[middle] == target)
        {
            return middle;
        }
        else if(values[middle] > target)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }
    return -1;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() <= 0)
    {
        return 0;
    }
    
    int low = 0;
    int high = rotateArray.size() - 1;
    while((rotateArray[low] >= rotateArray[high]) && (high - low) != 1)
    {
        int mid = (low + high) / 2;
        
        //无法明确哪部分递增，因此顺序查找
        if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
        {
            int res = rotateArray[0];
            for(int i = 0;i < rotateArray.size();i++)
            {
                if(rotateArray[i] < res)
                {
                    res = rotateArray[i];
                }
            }
            return res;
        }
        
        if(rotateArray[low] <= rotateArray[mid])
        {
            low = mid;
        }
        else if(rotateArray[mid] <= rotateArray[high])
        {
            high = mid;
        }
    }
    return rotateArray[high];
}

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    
    ListNode* pNode = NULL;
    if(pHead1->val < pHead2->val)
    {
        pNode = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        pNode = pHead2;
        pHead2 = pHead2->next;
    }

    ListNode* pRes = pNode;
    while(pHead1 != NULL && pHead2 != NULL)
    {
        if(pHead1->val < pHead2->val)
        {
            pRes->next = pHead1;
            pRes = pHead1;
            pHead1 = pHead1->next;
        }
        else 
        {
            pRes->next = pHead2;
            pRes = pHead2;
            pHead2 = pHead2->next;
        }
    }
    
    if(pRes)
    {
        pRes->next = pHead1 ? pHead1 : pHead2;
    }
    return pNode;
}

int main()
{
    vector<int> vale;
    vale.push_back(5);
    vale.push_back(6);
    vale.push_back(7);
    vale.push_back(3);
    vale.push_back(4);
    // int res = BinaryFindRecurve(vale,15);
    //int res = minNumberInRotateArray(vale);
    //printf("res:%d",res);

    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);
    pNode1->next = pNode3;
    pNode3->next = pNode5;

    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode6 = new ListNode(6);
    pNode2->next = pNode4;
    pNode4->next = pNode6;

    ListNode* pRes =  Merge(pNode1,pNode2);
    while(pRes)
    {
        printf("%d ",pRes->val);
        pRes = pRes->next;
    }

    return 0;
}