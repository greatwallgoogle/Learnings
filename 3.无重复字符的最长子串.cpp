/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.24%)
 * Likes:    3298
 * Dislikes: 0
 * Total Accepted:    385.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //O(n^2)
    int lengthOfLongestSubstring1(string s) {
        int longest = 0;
        vector<char> list;
        for(int i = 0;i < s.size();i++)
        {
            int num = list.size();
            for(vector<char>::iterator iter =list.begin();iter != list.end();iter++)
            {
                if((*iter) == s[i])
                {
                    longest = num > longest ? num : longest;
                    iter++;
                    list.erase(list.begin(),iter);
                    break;
                }
            }
            list.push_back(s[i]);
        }

        longest = list.size() > longest ? list.size() : longest;

         static const auto ban_io_sync = []()
        {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }();


        return longest ;
    }
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring1(s);
    }
};
// @lc code=end

