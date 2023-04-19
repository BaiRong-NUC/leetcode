/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
Accepted
141/141 cases passed (392 ms)
Your runtime beats 24.9 % of cpp submissions
Your memory usage beats 48.18 % of cpp submissions (22.1 MB)
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() < 2)
        {
            return s;
        }

        // 动态规划
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        // 一个字符的都是回文字符串,dp[i][j]代表i-j是回文字符串
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true;
        }

        int begin = 0;
        int strLen = 1;

        for (int length = 2; length <= s.length(); length++)
        {
            for (int left = 0; left < s.length(); left++)
            {
                // 回文字符串右边界为left+length-1
                int right = left + length - 1;
                if (right >= s.length())
                {
                    break;
                }

                if (s[left] != s[right])
                {
                    dp[left][right] = false;
                }
                else
                {
                    if (right - left < 3)
                    {
                        // 长度为2
                        dp[left][right] = true;
                    }
                    else
                    {
                        dp[left][right] = dp[left + 1][right - 1];
                    }
                }

                if (dp[left][right] == true && right - left + 1 > strLen)
                {
                    begin = left;
                    strLen = right - left + 1;
                    // cout << begin << ":" << strLen << endl;
                }
            }
        }

        return s.substr(begin, strLen);
    }
};
// @lc code=end
