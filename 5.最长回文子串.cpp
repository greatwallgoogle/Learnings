/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.82%)
 * Likes:    1848
 * Dislikes: 0
 * Total Accepted:    202.6K
 * Total Submissions: 702K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //动态规划，O(n^2)
    string longestPalindrome1(string s) {
        int nSize = s.size();
        vector<vector<int>> dp(nSize, vector<int>(nSize));
        int startIndex = 0, length = 1;
        for(int i = 0;i < nSize;i++)
        {
            dp[i][i] = 1;
            if(i < (nSize - 1))
            {
                if(s[i] == s[i + 1])
                {
                    dp[i][i + 1] = 1;
                    startIndex = i;
                    length = 2;
                }
            }
        }

        //子串长度
        for(int l = 3; l <= nSize;l++)
        {
            //子串起点索引
            for(int i = 0;(l - 1 + i) < nSize;i++)
            {
                //子串终点索引
                int j = l - 1 + i;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    startIndex = i;
                    length = l;
                }
            }
        }
        return s.substr(startIndex, length);
    }

    string getNewStr(string s)
    {
        string manaStr = "$#";//前缀加$为了防止越界
        for(int i = 0;i < s.size();i++)
        {
            manaStr += s[i];
            manaStr += "#";
        }
        return manaStr;
    }

    //manachar 算法
    //https://segmentfault.com/a/1190000008484167
    //https://www.cnblogs.com/mini-coconut/p/9074315.html
    string manachar(string s)
    {
        if(s.empty())
            return s;
        int id = 0,mx = 0;
        int startIndex = 0,length = 0;

        string strNew = getNewStr(s);
        const int nSize = strNew.size();
        vector<int> p(nSize);
        for(int i = 1;i < nSize;i++)
        {
            if(i < mx)
            {
                p[i] = min(p[2 * id - i],mx - i);
            }
            else
            {
                p[i] = 1;
            }

            while(strNew[i - p[i]] == strNew[i + p[i]])
            {
                p[i]++;
            }

             // 每走一步 i，都要和 mx 比较，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
            if (mx < i + p[i])
            {
                id = i;
                mx = i + p[i];
            }

            if((p[i] - 1) > length)
            {
                length = p[i] - 1;
                startIndex =( i - p[i]) / 2;
            }
        }
        return s.substr(startIndex,length);
    }

    string longestPalindrome(string s) {
        return manachar(s);
    }
};
// @lc code=end

