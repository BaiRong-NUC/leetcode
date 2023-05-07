/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <vector>
#include <iostream>
using namespace std;

/**
Accepted
588/588 cases passed (68 ms)
Your runtime beats 90.18 % of cpp submissions
Your memory usage beats 84.38 % of cpp submissions (8.8 MB)
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1); // dp[i]表示最少需要多少个数的平方来表示整数i
        for (int i = 1; i <= n; i++)
        {
            int min = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                min = std::min(min, dp[i - j * j]);
            }
            dp[i] = min + 1;
        }
        return dp[n];
    }
};
// @lc code=end
