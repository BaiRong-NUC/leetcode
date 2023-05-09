/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

#include <iostream>
#include <vector>

using namespace std;

/**
Accepted
36/36 cases passed (12 ms)
Your runtime beats 54.27 % of cpp submissions
Your memory usage beats 30.77 % of cpp submissions (9.3 MB)
 */

// @lc code=start
class Solution
{
    long MOD = 1000000007;

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1);
        long ret = 0;
        dp[0] = 1;
        for (int i = 0; i <= high; i++)
        {
            if (i >= zero)
                dp[i] += dp[i - zero];
            if (i >= one)
                dp[i] += dp[i - one];
            dp[i] %= MOD;
            if (i >= low)
            {
                ret += dp[i];
            }
            ret %= MOD;
        }
        return (int)ret;
    }
};
// @lc code=end
