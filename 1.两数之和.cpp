/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.78%)
 * Likes:    7819
 * Dislikes: 0
 * Total Accepted:    887K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return getTwoNum2(nums,target);
    }


    //第一中方法：暴力查找，时间复杂度高
    vector<int> getTwoNum(vector<int>& nums,int target)
    {
        vector<int> res;
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i + 1;j <nums.size();j++ )
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }

    vector<int> getTwoNum2(vector<int>& nums,int target)
    {
        vector<int> res;
        map<int,int> tp;
        for(int i = 0;i < nums.size();i++)
        {
            int tmp = target - nums[i];
            if(tp.find(tmp) != tp.end())
            {
                res.push_back(tp[tmp]);
                res.push_back(i);
                break;
            }
            tp[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

