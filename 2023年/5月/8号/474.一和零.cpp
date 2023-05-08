/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
Accepted
72/72 cases passed (640 ms)
Your runtime beats 5.19 % of cpp submissions
Your memory usage beats 7.33 % of cpp submissions (100.4 MB)
 */

// @lc code=start
class Solution
{
    // 统计字符串的0个数
    int _coutZero(string &str)
    {
        int ret = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] - '0' == 0)
            {
                ret += 1;
            }
        }
        return ret;
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp[i][j][k] strs前i个字符串使用j个0，k个1最长字符串个数
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= strs.size(); i++)
        {
            int zero = _coutZero(strs[i - 1]);
            int one = strs[i - 1].length() - zero;
            // cout << zero << ":" << one << endl;
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zero && k >= one)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zero][k - one] + 1);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};
// @lc code=end
