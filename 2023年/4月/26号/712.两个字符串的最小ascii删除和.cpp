/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

#include <string>
#include <vector>

using namespace std;

/**
Accepted
93/93 cases passed (52 ms)
Your runtime beats 18.25 % of cpp submissions
Your memory usage beats 24.05 % of cpp submissions (14.9 MB)
 */

// @lc code=start
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int length1 = s1.length();
        int length2 = s2.length();
        // dp[i][j]前缀长度为i，j的最小删除值
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 1; i <= length1; i++)
        {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= length2; j++)
        {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= length1; i++)
        {
            for (int j = 1; j <= length2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min((dp[i - 1][j] + s1[i - 1]), (dp[i][j - 1] + s2[j - 1]));
                }
            }
        }
        return dp[length1][length2];
    }
};
// @lc code=end
