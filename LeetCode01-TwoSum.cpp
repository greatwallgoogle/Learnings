#include <vector>
#include <map>
using namespace std;

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

链接：https://leetcode-cn.com/problems/two-sum

*/


class Solution
{
public:
    static vector<int> TwoSum(vector<int> nums,int nTarget)
    {
        vector<int> result;
        map<int,int> ht;
        for(int i = 0;i < nums.size();i++)
        {
            int nCurNum = nums[i];
            int nMinus = nTarget - nCurNum;
            if(ht.find(nMinus) != ht.end())
            {
                result.push_back(ht[nMinus]);
                result.push_back(i);
                break;
            }
            else
            {
                ht[nCurNum] = i;
            }
        }
        return result;
    }
};


int  main()
{
    //2,7,11,15
    vector<int> nums ;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    vector<int >result = Solution::TwoSum(nums,9);
    for(int i = 0;i < result.size();i++)
    {
        printf("%d ",result[i]);
    }

    return 0;
}